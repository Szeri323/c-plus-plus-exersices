#include "../../../headers/std_lib_facilities.h"

int main() {
	int i = 0;
	double min = 1, max = 100, current = 50, factor = 25;
	bool anwser = false;
	while(true) {
		cout << "Is the number bigger than " << current << "?" << endl;
		cin >> anwser;
		cout << "Factor: " << factor << endl;
		if (anwser == true) {
			min = current + 1;
			current = int(current + factor);
		}
		else {
			max = current;
			current = int(current - factor);
		}
		factor = int(factor / 2);
		cout << "Min: " << min << endl;
		cout << "Max: " << max << endl;
		++i;
		if (i == 7) {
			cout << "Is your number: " << max << endl;
			break;
		}
	}
	/*cout << "Is your number bigger than 50?" << endl;
	cin >> anwser;
	if (anwser == true) {
		cout << "Is your number bigger than 75?" << endl;
		cin >> anwser;
		if (anwser == true) {
			cout << "Is your number bigger than 87?" << endl;
		}
		else {
			cout << "Is your number bigger than 63?" << endl;
		}
	}
	else {
		cout << "Is your number bigger than 25?" << endl;
		cin >> anwser;
		if (anwser == true) {
			cout << "Is your number bigger than 37?" << endl;
		}
		else {
			cout << "Is your number bigger than 12?" << endl;
		}
	}*/

}