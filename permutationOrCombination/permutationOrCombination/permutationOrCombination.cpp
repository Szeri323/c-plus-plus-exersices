#include "../../../headers/std_lib_facilities.h"

/* 

Author: szeri

The program asks user to pass 2 numbers and choose between permuation and combination. 
Computer calculate result and print it on the screen depending of user choice.

inputs: int a,b,choice.

*/

int factorial(int factor) {
	if (factor == 0)
		return 1;
	if (factor == 1)
		return 1;
	return factor * factorial(factor - 1);
}

int permutation(int a, int b) {
	if (a < 0 || b < 0) error("Numbers can't be negative.");
	return (factorial(a) / factorial(a - b));
}

int combination(int a, int b) {
	if (a < 0 || b < 0) error("Numbers can't be negative.");
	return (permutation(a, b) / factorial(b));
}

int main() {
	while (cin) {
		try {
			cout << "Pass two number:" << endl;
			int a, b, choice;
			cin >> a >> b;
			cout << "Do you want to calculate permutation (1) or combination (2)?" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Permutiation of " << a << " and " << b << " is " << permutation(a, b) << endl;
			}
			else if (choice == 2) {
				cout << "Combination of " << a << " and " << b << " is " << combination(a, b) << endl;
			}
			else {
				error("Wrong choice, choose 1 or 2.");
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}