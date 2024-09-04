#include "../../../headers/std_lib_facilities.h"

int main() {
	cout << "Hello, pass your name and age:";
	string firstName = "";
	double age = 1;
	cin >> firstName >> age;
	cout << "Oh wow, you are " << firstName << " and you are " << age * 12 << " months old!";
}