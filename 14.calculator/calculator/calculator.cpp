#include "../../../headers/std_lib_facilities.h"

int wordsToNumber(string number) {
	vector<string> numbers = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	if (number == "1") {
		return 1;
	}
	else if (number == "2") {
		return 2;
	}
	else if (number == "3") {
		return 3;
	}
	else if (number == "4") {
		return 4;
	}
	else if (number == "5") {
		return 5;
	}
	else if (number == "6") {
		return 6;
	}
	else if (number == "7") {
		return 7;
	}
	else if (number == "8") {
		return 8;
	}
	else if (number == "9") {
		return 9;
	}
	else {
		for (int i = 0; i < numbers.size(); ++i) {
			if (number == numbers[i]) {
				return i + 1;
			}
		}
	}
}

double sum(double x, double y) {
	return x + y;
}
double substraction(double x, double y) {
	return x - y;
}
double multiplication(double x, double y) {
	return x * y;
}
double division(double x, double y) {
	return x / y;
}

void logic() {
	string number1, number2;
	char sign;
	double result = 0;
	cout << "Pass number1, sign, number2: " << endl;
	cin >> number1 >> sign >> number2;
	int x = wordsToNumber(number1);
	int y = wordsToNumber(number2);
	if ((x > 0 && x < 10) && (y > 0 && y < 10)) {
		if (sign == '+') {
			result = sum(x, y);
		}
		else if (sign == '-') {
			result = substraction(x, y);
		}
		else if (sign == '*') {
			result = multiplication(x, y);
		}
		else if (sign == '/') {
			result = division(x, y);
		}
		else {
			error("Invalid sign.");
		}
		cout << "Result of " << x << " " << sign << " " << y << ": " << result << endl;
	}
	else {
		error("Invalid parameters.");
	}
}

int main() {
	try {
		logic();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}