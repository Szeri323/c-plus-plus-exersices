#include "../../../headers/std_lib_facilities.h"

const char number = '8';
const char quit = 'x';
const char print = '=';
const string prompt = "> ";
const string result = "= ";

class Token {
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0) { }
    Token(char ch, double val)
        :kind(ch), value(val) { }
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t) {
    if (full) error("Calling putback(), when buffer is full.");
    buffer = t;
    full = true;
}
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
    case '=':
    case 'x':
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
        error("Invalid token.");
    }
    return -1;
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

Token_stream ts;

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
        << "To print result use = and to close program use 'x' key."
        << endl;
    return;
}

void calculate() {
    while (cin) {
        cout << prompt;
        Token t = ts.get();

        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << expression() << endl;
    }
}

int main()
try {
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

double expression()
{
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

double term()
{
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

double primary() 
{
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
    default:
        error("Primary was expected.");
    }
}