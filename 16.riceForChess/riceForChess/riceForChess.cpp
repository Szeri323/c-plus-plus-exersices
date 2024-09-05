#include "../../../headers/std_lib_facilities.h"

int main() {
	int number1 = 1;
	double number2 = 1;
	for (int i = 0; i < 33; ++i) {
		cout << i << ": " << number1 << endl;
		number1 *= 2;
	}for (int i = 0; i < 1025; ++i) {
		cout << i << ": " << number2 << endl;
		number2 *= 2;
	}
}