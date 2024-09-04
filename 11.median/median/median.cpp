#include "../../../headers/std_lib_facilities.h"

int main() {
	vector<double> temperatures;
	double temp;
	while (cin >> temp) {
		temperatures.push_back(temp);
	}
	sort(temperatures.begin(), temperatures.end());
	if (temperatures.size() % 2 == 0) {
		cout << "Mediana: " << (temperatures[temperatures.size() / 2] + temperatures[temperatures.size() / 2 -1]) /2 << endl;
	}
	else {
		cout << "Mediana: " << temperatures[temperatures.size() / 2] << endl;
	}
}