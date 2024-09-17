#include "../../../headers/std_lib_facilities.h"



int main() {
	vector<double> numbers;
	vector<double> differences;
	double number;
	int n;
	int sum = 0;
	cout << "How many number do you want to sum: " << endl;
	cin >> n;
	if (n < 0) { 
		cout << "Vector size can't be negative." << endl; 
		return -1;
	}
	cout << "Write numbers you want to add to vector, when you finish write symbol like '/'." << endl;
	while (cin >> number) {
		numbers.push_back(number);
	}
	if (numbers.size() < n) {
		cout << "Not enough number to sum." << endl;
		return -2;
	}
	else {
		for (int i = 0; i < n; ++i) {
			sum += numbers[i];
		}
		cout << sum << endl;
	}
	for (int i = 1; i < numbers.size(); ++i) {
		differences.push_back(numbers[i - 1] - numbers[i]);
	}
	for (double x : differences) {
		cout << x << " ";
	}
}