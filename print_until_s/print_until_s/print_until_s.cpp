#include "../../../headers/std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
    // prints strings until keyword.
    for (string s : v) {
        if (s == quit) return;
        cout << s << '\n';
    }
}
void print_until_ss(vector<string> v, string quit)
{
    // prints strings until counter hit 2. Function don't need two keyqords one after another.
    int counter = 0;
    for (string s : v) {
        if (s == quit) {
            ++counter;
            if (counter == 2) return;
        }
        cout << s << '\n';
    }
}
void print_until_ss_sequence(vector<string> v, string quit)
{
    // prints strings until counter hit 2. Function count only keywords that appear one next to each other
    int counter = 0;
    for (string s : v) {
        if (s == quit) {
            ++counter;
            if (counter == 2) return;
        }
        else {
            counter = 0;
        }
        cout << s << '\n';
    }
}

int main() {
    vector<string> v{ "alpha", "Beta", "sdjah", "ghaksdj", "exit", "asjghas", "arman", "armen" };
    vector<string> v2{ "alpha", "Beta","exit", "sdjah", "ghaksdj", "exit", "asjghas", "arman", "armen" };
    vector<string> v3{ "alpha", "Beta","exit", "sdjah", "ghaksdj", "exit", "asjghas", "exit", "exit", "arman", "armen" };
    print_until_s(v, "exit");
    cout << endl;
    cout << endl;
    print_until_ss(v2, "exit");
    cout << endl;
    cout << endl;
    print_until_ss_sequence(v3, "exit");
}