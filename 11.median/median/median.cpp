#include "../../../headers/std_lib_facilities.h"

double calculate_median() {
	vector<double> temperatures;
	double temp;
	while (cin >> temp) {
		temperatures.push_back(temp);
	}
	sort(temperatures.begin(), temperatures.end());
	if (temperatures.size() % 2 == 0) {
		return (temperatures[temperatures.size() / 2] + temperatures[temperatures.size() / 2 - 1]) / 2;
	}
	else {
		return temperatures[temperatures.size() / 2];
	}
}

int main() {
	try {
		cout << "Median: " << calculate_median() << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	
}