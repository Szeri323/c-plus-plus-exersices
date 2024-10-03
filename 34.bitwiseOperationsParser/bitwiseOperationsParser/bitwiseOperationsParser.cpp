#include "../../../headers/std_lib_facilities.h"

class Token {
public:
    char kind;
    int value;
    Token(char ch)
        :kind(ch), value(0) { }
    Token(char ch, int val)
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
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;
    switch (ch)
    {
    case '=':
    case 'x':
    case '!':
    case '(': case ')': case '{': case '}': case  '~': case '&': case '|': case '^':
        return Token(ch);
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        int val;
        cin >> val;
        return Token('8', val);
    }
    default:
        error("Invalid token.");
    }
    return -1;
}

Token_stream ts;

int expression();

int exp();

int term();

int primary();

int main()
try {
    cout << "Welcome in bitwise operations parser."
        << endl
        << "In expresions use int type numbers."
        << endl
        << "You can use ~, &, ^, |, operators."
        << endl
        << "To print result use = and to close program use 'x' key."
        << endl;
    int val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'x') break;
        if (t.kind == '=')
            cout << '=' << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open();
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Exception \n";
    keep_window_open();
    return 2;
}

int expression()
{
    int left = exp();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '|':
            left |= exp();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int exp()
{
    int left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '^':
            left ^= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int term()
{
    int left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '&':
        {
            left &= primary();
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

int primary()
{
    Token t = ts.get();
    switch (t.kind) {
        /* case '!':
             t = ts.get();
             if(t.kind == '8') return !t.value;
             error("Expected number after '!' sign.");*/
    case '~':
        t = ts.get();
        if (t.kind == '8') return ~t.value;
        error("Expected number after '~' sign.");
    case '8':
    {
        return t.value;
    }
    default:
        error("Primary was expected.");
    }
}