#include "../../../headers/std_lib_facilities.h"

double calculateDelta(double a, double b, double c) {
	return b * b - 4 * a * c;
}

int main() {
	double a, b, c;
	cout << "Pass a, b, c: " << endl;
	cin >> a >> b >> c;
	double delta = calculateDelta(a, b, c);
	cout << "Delta equals: " << delta << endl;
	if (delta > 0) {
		cout << delta << endl;
		cout << sqrt(delta) << endl;
		cout << "x1: " << (-b - sqrt(delta)) / 2 * a << endl;
		cout << "x2: " << (-b + sqrt(delta)) / 2 * a << endl;
	}
	else if (delta == 0) {
		cout << "x: " << (-b / 2 * a) << endl;
	}
	else {
		cout << "Equation does not have solution." << endl;
	}
}