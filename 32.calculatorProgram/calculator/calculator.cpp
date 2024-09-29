/*
Simple calculator
This is exercice from "Programowanie. Teoria i praktyka z wykorzystaniem C++." book.

Made by: Szeri september 2024

This program implements fundamental expresions for calculator.
Data is taken by input stream cin and passed to output stream cout.

Print:
    ;

Help:
    help

Quit:
    end

Keywords:
    let
    const
    sqrt
    pow

Input data grammar:

Calculation:
    Statement
    Print
    Help
    Quit
    Calculation Satement

Statement:
    Declaration
    Expresion

Declaration:
    "let" Name "=" Expression
    "const" Name "=" Expression
    (declared) Name "=" Expresion
    (declared, no const) Name "=" (declared) Name

Expression:
    Term
    Expression + Term
    Expression - Term

Term:
    Primary
    Term * Primary
    Term / Primary
    Term % Primary

Primary:
    Number
    ( Expression )
    - Number
    + Number
    sqrt ( Primary )
    pow ( Primary, int<Primary> )

Number:
    floating-point-literal

Data come from cin stream, go through ts name Token_stream.
*/

#include "../../../headers/std_lib_facilities.h"

// Testing from the file section

void read_from_test_file() {
    string iname = "test_file.txt";
    ifstream ist{ iname };
    if (!ist) error("Could not open the test file.");
}
void write_to_log_file() {
    string oname = "logs.txt";
    ofstream ost{ oname };
    if (!ost) error("Could not open the logs file.");
}

const char number = '8';
const char quit = 'E';
const char print = ';';
const char help = 'h';
const char name = 'a';
const char let = 'L';
const char constant = 'C';
const char sqrtsign = 'S';
const char powsign = 'P';
const string varkey = "let";
const string constkey = "const";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string quitkey = "end";
const string helpkey = "help";
const string prompt = "> ";
const string result = "= ";

class Token {
// Get char from cin and define if it is char or number or variable name
public:
    char kind;
    double value;
    string name;
    Token(char ch)
        :kind(ch), value(0) { }
    Token(char ch, double val)
        :kind(ch), value(val) { }
    Token(char ch, string n) 
        :kind(ch), value(0), name(n) { }
};

class Token_stream {
// It is buffer for Tokens
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

Token Token_stream::get() {
    // Reads chars from input stream and creates tokens
    if (full) { // checks if token is ready
        full = false;
        return buffer;
    }

    char ch;
    cin.get(ch); // Atention: >> skips whitespaces (spaces, new lines, tabulators etc.)
    while (ch == ' ')
        cin.get(ch);
    switch (ch)
    {
    case print:
    /*case quit:*/
    case ',':
    case '_':
    case '=':
    case '!': case '(': case ')': case '{': case '}':
    case  '+': case '-': case '*': case '/': case '%':
        return Token(ch);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token(number, val);
    }
    case '\n':
        return Token(print);
    default:
        // if (ch == '#') set declaration keyword to # from let
        //if (ch == '#') {
        //    string s;
        //    s += ch;
        //    while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
        //        s += ch;
        //    cin.putback(ch);
        //    if (s == declkey) return Token(let);
        //}

        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                s += ch;
            cin.putback(ch);
            if (s == varkey) return Token(let);
            if (s == constkey) return Token(constant);
            if (s == sqrtkey) return Token(sqrtsign);
            if (s == powkey) return Token(powsign);
            if (s == quitkey) return Token(quit);
            if (s == helpkey) return Token(help);
            return Token(name, s);
        }
        error("Invalid token.");
    }
}

void Token_stream::putback(Token t) {
    if (full) error("Calling putback(), when buffer is full.");
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c) {
    // Takes Tokens from a Token stream while frist char c occures
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

class Variable {
// Class for defining variables or constants in calculator
public:
    string name;
    double value;
    bool constant;
    Variable(string name, double value, bool constant) 
        : name(name), value(value), constant(constant){}
};

class Symbol_table {
public:
    double get(string s);
    void set(string s, double d);
    bool is_declared(string var);
    double define(string var, double val, bool constant);
private:
    vector<Variable> var_table;
};


double Symbol_table::get(string s) {
    // Return value of s variable
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("Getting: undefined variable.", s);
}

void Symbol_table::set(string s, double d) {
    // Change value of existing Variable
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s){
            if (!var_table[i].constant) {
                var_table[i].value = d;
                return;
            }
            error("Setting: variable is constant.");
        }
    error("Setting: undefined variable.", s);
}

bool Symbol_table::is_declared(string var) {
    // Checks if variable exists in vector
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

double Symbol_table::define(string var, double val, bool constant) {
    // Creates and add variable object if doesn't already exists
    if (is_declared(var)) error(var, " - duplicated declaration.");
    var_table.push_back(Variable(var, val, constant));
    return val;
}

int factorial(int factor) {
    if (factor == 0 || factor == 1) return 1;
    return factor * factorial(factor - 1);
}

Token_stream ts;

Symbol_table symtab;

double statement();

double declaration();

double expression();

double term();

double primary();

void print_instruction() {
    cout << "Welcome in our simple calculator."
        << endl
        << "To see help write " << helpkey << " and press enter."
        << endl;
    return;
}

void print_help() {
    cout << "In expresions use double type numbers."
        << endl
        << "Operators:"
        << endl
        << "\tYou can use +, -, *, /, % operators."
        << endl
        << "Negation:"
        << endl
        << "\tTo use negation use '!'."
        << endl
        << "Brackets:"
        << endl
        << "\tBrackets you can use (), {} pairs."
        << endl
        << "Variables and constants:"
        << endl
        << "\tTo declare variable use '" << varkey << "' for constant use '" << constkey << "' next choose name and by using '=' assign value."
        << endl
        << "Change value of name value:"
        << endl
        << "\tYou can only change variables by using '='. Constant are unmutable."
        << endl
        << "To print result use '" << print << "' or new line sign (enter). For close program use '" << quitkey << "' key."
        << endl;
    return;
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin) 
        try {
            cout << prompt;
            Token t = ts.get();
            if (t.kind == 'h') {
                print_help();
                cout << prompt;
                t = ts.get();
            }
            while (t.kind == print) {
                t = ts.get();
                if (t.kind == 'h') {
                    print_help();
                    cout << prompt;
                    t = ts.get();
                }
            }
                
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << endl;
        }
    catch (exception& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

void define_constants_from_file(ifstream& ist) {
    string name;
    double value;
    bool is_const;
    while (ist >> name >> value >> is_const)
        symtab.define(name, value, is_const);
}

void read_constants_file() {
    string name = "constants.txt";
    ifstream ist{ name };
    if (!ist) error("Could not open the file.");
    define_constants_from_file(ist);
    ist.close();
}

int main()
try {
    read_constants_file();
    /*symtab.define("pi", 3.1415926535, true);
    symtab.define("e", 2.7182818284, true);
    symtab.define("k", 1000, true);*/
    print_instruction();
    calculate();
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "Exception \n";
    keep_window_open("~~");
    return 2;
}

double statement() {
    Token t = ts.get();
    switch (t.kind) {
    case constant:
    case let:
        ts.putback(t);
        return declaration();
    case name:
    {
        ts.putback(t);
        return expression();
    }
    default:
        ts.putback(t);
        return expression();
    }
}

double declaration() {
    Token t = ts.get();

    Token t2 = ts.get();
    if (t2.kind != name) error("Expected name in declaration.");
    string var_name = t2.name;

    Token t3 = ts.get();
    if (t3.kind != '=') error("Missing = sign in variable declaration.", var_name);
    double d = expression();
    (t.kind == let) ? symtab.define(var_name, d, false) : symtab.define(var_name, d, true); // check if constant or not
    return d;
}

double expression() {
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double term() {
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '%':
        {
            double d = primary();
            if (d == 0) error("Dividing by 0.");
            left = fmod(left, d);
            t = ts.get();
            break;
            /*int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(term());
            if (i2 == 0) error(" % : dividing by zero.");
            left = i1 % i2;
            t = ts.get();
            break;*/
        }
        case '!':
        {
            left = factorial(left);
            t = ts.get();
            break;
        }
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("Dividing by zero.");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch (t.kind) {
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' was expected.");
        return d;
    }
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' was expected.");
        return d;
    }
    case number:
    {
        double d = t.value;
        t = ts.get();
        if (t.kind == '!') return factorial(d);
        ts.putback(t);
        return d;
    }
    case name:
        if (symtab.is_declared(t.name)) {
            Token t2 = ts.get();
            if (t2.kind == '=') {
                double d = expression();
                symtab.set(t.name, d);
                return symtab.get(t.name);
            }
            else {
                ts.putback(t2);
                return symtab.get(t.name);
            }
        }
        error("Name is not declared.");
    case '-':
        return -primary();
    case '+':
        return primary();
    case sqrtsign:
    {
        // allows to use expression like sqrt(3*3) or sqrt(2.5) and use sqrt from std lib to return result
        double d = primary();
        if (d < 1) error("Sqrt only from positive numebrs.");
        return sqrt(d);
    }
    case powsign:
    {
        // checks if format is pow(double, int) and use pow(x,i) form std lib to return result
        Token t = ts.get();
        if (t.kind != '(') error("Invalid pow operation. Missing ( sign.");

        double x = primary();

        Token t2 = ts.get();
        if (t2.kind != ',') error("Invalid pow operation. Missing , sign.");

        int i = narrow_cast<int>(primary());

        Token t3 = ts.get();
        if (t3.kind != ')') error("Invalid pow operation. Missing ) sign.");

        return pow(x, i);
    }
    default:
        if (t.kind == 'a') return symtab.get(t.name);
        error("Primary was expected.");
    }
}