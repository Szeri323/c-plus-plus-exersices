#include "../../../headers/std_lib_facilities.h"

int main() {
    try {
        cout << "Brawo!\n";
        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << "B��d: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Nieznany rodzaj wyj�tku!\n";
        keep_window_open();
        return 2;
    }
}