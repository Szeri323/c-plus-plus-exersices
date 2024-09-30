#include "../../../headers/std_lib_facilities.h"

bool logic() {
	int i = 0;
	double min = 1, max = 100, current = 50, factor = 25;
	bool anwser = false;
	bool correct = false;
	while (true) {
		cout << "Is the number bigger than " << current << "?" << endl;
		cin >> anwser;
		if (anwser == true) {
			min = current + 1;
			current = int(current + factor);
		}
		else {
			max = current;
			current = int(current - factor);
		}
		factor = int(factor / 2);
		if (factor == 0)
			factor = 1;
		++i;
		if (max - min == 0 || i == 7) {
			cout << "Is your number: " << max << endl;
			cin >> correct;
			break;
		}
	}
	return correct;
}

int main() {
	try {
		if (logic()) cout << "My program beat you.\n";
		else cout << "Congratulations you won!\n";
		keep_window_open();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}