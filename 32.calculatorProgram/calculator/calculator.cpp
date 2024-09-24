/*
Simple calculator
This is exercice from "Programowanie. Teoria i praktyka z wykorzystaniem C++." book.

Made by: Szeri september 2024

This program implements fundamental expresions for calculator.
Data is taken by input stream cin and passed to output stream cout.

Print:
    =

Quit:
    x

Input data grammar:

Calculation:
    Statement
    Print
    Quit
    Calculation Satement

Statement:
    Declaration
    Expresion

Declaration:
    "let" Name "=" Expression

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
    - Primary
    + Primary
    sqrt ( Primary )

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
const char quit = 'k';
const char print = ';';
const char name = 'a';
const char let = 'L';
const char sqrtsign = 'S';
const string declkey = "let";
const string sqrtkey = "sqrt";
const string prompt = "> ";
const string result = "= ";

class Token {
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
    cin >> ch; // Atention: >> skips whitespaces (spaces, new lines, tabulators etc.)
    switch (ch)
    {
    case print:
    case quit:
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
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;
            cin.putback(ch);
            if (s == declkey) return Token(let);
            if (s == sqrtkey) return Token(sqrtsign);
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
// Class for defining variables in calculator
public:
    string name;
    double value;
    Variable(string name, double value) 
        : name(name), value(value) {}
};

vector<Variable> var_table;

double get_value(string s) {
    // Return value of s variable
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("Getting: undefined variable.", s);
}

void set_value(string s, double d) {
    // Change value of existing Variable
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    error("Setting: undefined variable.", s);
}


int factorial(int factor) {
    if (factor == 0) {
        return 1;
    }
    if (factor == 1) {
        return 1;
    }
    return factor * factorial(factor - 1);
}

bool is_declared(string var) {
    // Checks if variable exists in vector
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

double define_name(string var, double val) {
    // Creates and add variable object if doesn't already exists
    if (is_declared(var)) error(var, " - duplicated declaration.");
    var_table.push_back(Variable(var, val));
    return val;
}

Token_stream ts;

double statement();

double declaration();

double expression();

double term();

double primary();

void print_instruction() {
    cout << "Welcome in our simple calculator."
        << endl
        << "In expresions use double type numbers."
        << endl
        << "You can use +, -, *, / operators."
        << endl
        << "To print result use " << print << " and to close program use " << quit << " key."
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

            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << endl;
        }
    catch (exception& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main()
try {
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);
    define_name("k", 1000);
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
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

double declaration() {
    Token t = ts.get();
    if (t.kind != name) error("Expected name in declaration.");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("Missing = sign in variable declaration.", var_name);
    double d = expression();
    define_name(var_name, d);
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
        if (t.kind == '!') {
            return factorial(d);
        }
        else {
            ts.putback(t);
        }
        return d;
    }
    case '-':
        return -primary();
    case '+':
        return primary();
    case sqrtsign:
    {
        double d = primary();
        if (d < 1) error("Sqrt only from positive numebrs.");
        return sqrt(d);
    }
    default:
        if (t.kind == 'a') {
            return get_value(t.name);

        }
        error("Primary was expected.");
    }
}