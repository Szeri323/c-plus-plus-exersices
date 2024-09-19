#include "../../../headers/std_lib_facilities.h"

vector<char> populate_vector(vector<char> number) {
	while (number.size() < 4) {
		char ch;
		cin >> ch;
		switch (ch) {
		case ';':
			return number;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			number.push_back(ch);
			break;
		}
		default:
			error("Not a number.");
		}
	}
	return number;
}

int decomposition(vector<char> number) {
	int val = 0;
	int factor = 1;
	for (int i = number.size() - 1; i >= 0; --i) {
		int digit = number[i] - '0';
		digit *= factor;
		val += digit;
		factor *= 10;
	}
	return val;
}

int main() {
	try
	{
		vector<char> number;
		number = populate_vector(number);
		int val = decomposition(number);

		cout << "Decomposition of number " << val << ":";
		if (val > 999) {
			cout << " thousands: " << number[0] << " hundreds: " << number[1] << " tens: " << number[2] << " units: " << number[3] << endl;
		}
		else if (val > 99) {
			cout << " hundreds: " << number[0] << " tens: " << number[1] << " units: " << number[2] << endl;
		}
		else if (val > 9) {
			cout << " tens: " << number[0] << " units: " << number[1] << endl;
		}
		else {
			cout << " units: " << number[0] << endl;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}