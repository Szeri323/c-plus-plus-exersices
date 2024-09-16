
//
// Przyk³adowy kod z rozdzia³u 6.6 "Wypróbowywanie pierwszej wersji" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "../../../headers/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // rodzaj tokenu
    double value;     // Dla liczb: wartoœæ. 
    Token(char ch)    // Tworzy Token ze znaku.
        :kind(ch), value(0) { }
    Token(char ch, double val)     // Tworzy Token ze znaku i wartoœci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // Tworzy Token_stream wczytuj¹cy ze strumienia cin.
    Token get();      // Pobiera token.
    void putback(Token t); // Wstawia token z powrotem.
private:
    bool full;
    Token buffer;
    // szczegó³y implementacyjne
};

Token_stream::Token_stream() :full(false), buffer(0) {
}

void Token_stream::putback(Token t) {
    if (full) error("Wywo³anie funkcji putback(), gdy bufor jest pe³ny.");
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
    case ';':                      // drukowanie
    case 'k':                      // koniec
    case '(': case ')': case  '+': case '–': case '*': case '/': case '%':
        return Token(ch);          // Ka¿dy znak reprezentuje sam siebie
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);       // Wstawia cyfrê z powrotem do strumienia wejœciowego
        double val;
        cin >> val;            // Wczytuje liczbê zmiennoprzecinkow¹
        return Token('8', val); // ‘8’ reprezentuje „liczbê”
    }
    default:
        error("Nieprawid³owy token.");
    }
    return -1;
}
//------------------------------------------------------------------------------

Token_stream ts;      // globalny strumieñ tokenów

//------------------------------------------------------------------------------

double expression();  // Wczytuje i wartoœciuje wyra¿enie.

//------------------------------------------------------------------------------

double term();        // Wczytuje i wartoœciuje sk³adnik.

//------------------------------------------------------------------------------

double primary()     // Wczytuje i oblicza wartoœæ czynnika.
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // Obs³uga '(' wyra¿enie ')'.
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' by³ oczekiwany.");
        return d;
    }
    case '8':            // Do reprezentacji liczb s³u¿y znak 8.
        return t.value;  // Zwraca wartoœæ liczby.
    default:
        error("By³ oczekiwany czynnik.");
    }
}
//------------------------------------------------------------------------------

int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'k') break; // ‘k’ = koniec
        if (t.kind == ';')        // ‘;’ = drukuj teraz
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
    cerr << "Wyj¹tek \n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term(); // Wczytuje i wartoœciuje sk³adnik.
    Token t = ts.get();   // Pobiera nastêpny token ze strumienia.

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();   // Wartoœciuje sk³adnik i wykonuje dodawanie.
            t = ts.get();
            break;
        case '-':
            left -= term();   // Wartoœciuje sk³adnik i wykonuje odejmowanie.
            t = ts.get();
            break;
        default:
            ts.putback(t);    // Wstawia token t z powrotem do strumienia tokenów.
            return left;      // Jeœli nie ma wiêcej znaków + lub –, zwraca odpowiedŸ.
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();   // Pobiera nastêpny token ze strumienia.

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("Dzielenie przez zero.");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t); // Wstawia token t z powrotem do strumienia tokenów.
            return left;
        }
    }
}

//------------------------------------------------------------------------------
