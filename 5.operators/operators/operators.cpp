#include "../../../headers/std_lib_facilities.h"

int doubles() {
	cout << "Pass double number: ";
	double n;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwo times n == " << n + n
		<< "\nn square == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsqrt from n == " << sqrt(n);
	int n2 = n;
	cout << "\nmodulo n == " << n2 % 2
		<< "\n";
	return 0;
}

int ints() {
	cout << "Pass integer number: ";
	int n;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwo times n == " << n + n
		<< "\nn square == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nmodulo n == " << n % 2;
	double n2 = n;
	cout << "\nsqrt from n == " << sqrt(n2)
		<< "\n";
	return 0;
}


int main() {
	system("chcp 1250");
	doubles();
}

