#include "../../../headers/std_lib_facilities.h"

vector<double> populate_vector() {
	vector<double> numbers;
	double number;
	cout << "Pass sequence of numbers:" << endl;
	while (cin >> number) {
		numbers.push_back(number);
	}
	cin.clear();
	return numbers;
}

int get_number() {
	int n;
	cout << "How many first numbers do you want to sum: ";
	cin >> n;
	if (n < 0) error("Number can't be negative");
	if (n == 0) {
		cout << "No numbers will be sum." << endl;
		return 0;
	}
	return n;
}

double sum_vector_numebrs(vector<double> numbers, int n) {
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += numbers[i];
	}
	return sum;
}

vector<double> calculate_difference_between_numebrs(vector<double> numbers) {
	vector<double> differences;
	for (int i = 1; i < numbers.size(); ++i) {
		differences.push_back(numbers[i - 1] - numbers[i]);
	}
	return differences;
}

void print_results(double sum, int n, vector<double> differences) {
	cout << "Sum of " << n << " first numbers is: " << sum << endl;
	cout << "Differences of vector numbers are:" << endl;
	for (double x : differences) {
		cout << x << " ";
	}
}

int main() {
	try {
		vector<double> numbers = populate_vector();
		int n = get_number();
		if (numbers.size() < n) error("Not enough numbers to sum.");
		int sum = sum_vector_numebrs(numbers, n);
		vector<double> differences = calculate_difference_between_numebrs(numbers);
		print_results(sum, n, differences);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}