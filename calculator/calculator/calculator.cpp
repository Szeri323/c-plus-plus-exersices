
//
// Przyk�adowy kod z rozdzia�u 6.6 "Wypr�bowywanie pierwszej wersji" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "../../../headers/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // rodzaj tokenu
    double value;     // Dla liczb: warto��. 
    Token(char ch)    // Tworzy Token ze znaku.
        :kind(ch), value(0) { }
    Token(char ch, double val)     // Tworzy Token ze znaku i warto�ci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // Tworzy Token_stream wczytuj�cy ze strumienia cin.
    Token get();      // Pobiera token.
    void putback(Token t); // Wstawia token z powrotem.
private:
    bool full;
    Token buffer;
    // szczeg�y implementacyjne
};

Token_stream::Token_stream() :full(false), buffer(0) {
}

void Token_stream::putback(Token t) {
    if (full) error("Wywo�anie funkcji putback(), gdy bufor jest pe�ny.");
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
    case '(': case ')': case  '+': case '�': case '*': case '/': case '%':
        return Token(ch);          // Ka�dy znak reprezentuje sam siebie
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);       // Wstawia cyfr� z powrotem do strumienia wej�ciowego
        double val;
        cin >> val;            // Wczytuje liczb� zmiennoprzecinkow�
        return Token('8', val); // �8� reprezentuje �liczb�
    }
    default:
        error("Nieprawid�owy token.");
    }
    return -1;
}
//------------------------------------------------------------------------------

Token_stream ts;      // globalny strumie� token�w

//------------------------------------------------------------------------------

double expression();  // Wczytuje i warto�ciuje wyra�enie.

//------------------------------------------------------------------------------

double term();        // Wczytuje i warto�ciuje sk�adnik.

//------------------------------------------------------------------------------

double primary()     // Wczytuje i oblicza warto�� czynnika.
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // Obs�uga '(' wyra�enie ')'.
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' by� oczekiwany.");
        return d;
    }
    case '8':            // Do reprezentacji liczb s�u�y znak 8.
        return t.value;  // Zwraca warto�� liczby.
    default:
        error("By� oczekiwany czynnik.");
    }
}
//------------------------------------------------------------------------------

int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'k') break; // �k� = koniec
        if (t.kind == ';')        // �;� = drukuj teraz
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
    cerr << "Wyj�tek \n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term(); // Wczytuje i warto�ciuje sk�adnik.
    Token t = ts.get();   // Pobiera nast�pny token ze strumienia.

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();   // Warto�ciuje sk�adnik i wykonuje dodawanie.
            t = ts.get();
            break;
        case '-':
            left -= term();   // Warto�ciuje sk�adnik i wykonuje odejmowanie.
            t = ts.get();
            break;
        default:
            ts.putback(t);    // Wstawia token t z powrotem do strumienia token�w.
            return left;      // Je�li nie ma wi�cej znak�w + lub �, zwraca odpowied�.
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();   // Pobiera nast�pny token ze strumienia.

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
            ts.putback(t); // Wstawia token t z powrotem do strumienia token�w.
            return left;
        }
    }
}

//------------------------------------------------------------------------------
