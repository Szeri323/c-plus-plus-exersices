#include "../../../headers/std_lib_facilities.h"

double usd_rate_if(string currencie) {
	if (currencie == "jpy") {
		return 0.0068;
	}
	else if (currencie == "eur") {
		return 1.11;
	}
	else if (currencie == "pln") {
		return 0.26;
	}
	else {
		return 0;
	}
}
double usd_rate_switch(int currencie) {
	switch (currencie)
	{
	case 1:
		return 0.0068;
	case 2:
		return 1.11;
	case 3:
		return 0.26;
	default:
		return 0;
	}
}

double to_usd(int amount, double rate) {
	return amount * rate;
}


int main() {
	int amount = 0;
	cout << "Pass amount: ";
	cin >> amount;
	int currencie;
	cout << "Pass currencie symbol (jpy: 1, eur: 2, pln: 3): ";
	cin >> currencie;
	double rate = usd_rate_switch(currencie);
	if (rate == 0) {
		cout << "Invalid currencie symbol.";
		return 0;
	}
	cout << to_usd(amount, rate);
}