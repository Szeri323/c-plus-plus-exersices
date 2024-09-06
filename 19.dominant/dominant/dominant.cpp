#include "../../../headers/std_lib_facilities.h"

bool numberInVector(vector<int> numbers, int number) {
	for (int i = 0; i < numbers.size(); ++i) {
		if (number == numbers[i]) {
			return true;
		}
	}
	return false;
}
int indexOfVectorMax(vector<int> numbers) {
	int max = 0;
	int index = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		if (max < numbers[i]) {
			index = i;
			max = numbers[i];
		}
	}
	return index;
}

void printIntVector(vector<int> numbers) {
	for (int x : numbers)
		cout << x << " ";
}

int main() {
	vector<int> numbers{ 1,2,3,3,3,5,5,5,5,5,5,5,5,5,3,3,2,1,1,2 };
	vector<int> unique, counters;
	int counter = 0;
	int number = numbers[0];
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); ++i) {
		if (unique.size() == 0) {
			unique.push_back(number);
		}
		if (numbers[i] != number) {
			number = numbers[i];
			if (!numberInVector(unique, number)) {
				unique.push_back(number);
			}
			counters.push_back(counter);
			counter = 1;
		}
		else {
			++counter;
		}
		if (i == numbers.size() - 1) {
			counters.push_back(counter);
		}

	}
	cout << "Numbers: ";
	printIntVector(numbers);
	cout << endl;
	cout << "Unique numbers: ";
	printIntVector(unique);
	cout << endl;
	cout << "Counters of occurrences in numbers vector: ";
	printIntVector(counters);
	cout << endl;
	cout << "Dominant: " << unique[indexOfVectorMax(counters)] << endl;
}