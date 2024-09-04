#include "../../../headers/std_lib_facilities.h"

int main() {
	vector<string> numbers = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	int number;
	string word;
	//cout << "Write number form 1 to 10: " << endl;
	cout << "Write number by words:" << endl;
	/*while (cin >> number) {
		if (number > 0 && number < 11) {
			cout << numbers[number - 1] << endl;
		}
		else {
			cout << "Invalid number." << endl;
			return 0;
		}
	}*/
	while (cin >> word) {
		for (int i = 0; i < numbers.size(); ++i) {
			if (word == numbers[i]) {
				cout << i + 1 << endl;
			}
		}
	}
}