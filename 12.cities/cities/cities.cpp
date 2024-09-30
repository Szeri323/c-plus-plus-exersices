#include "../../../headers/std_lib_facilities.h"

void print_results(const vector<double> &cities) {
	double sum = 0;
	for (double x : cities) {
		sum += x;
	}
	cout << "Sum: " << sum << endl;
	cout << "Min: " << cities[0] << endl;
	cout << "Max: " << cities[cities.size()-1] << endl;
	cout << "Avg: " << sum / cities.size() << endl;
}

void get_values(vector<double>& cities) {
	double dist;
	while (cin >> dist)
		cities.push_back(dist);
}

int main() {
	try {
		vector<double> cities;
		get_values(cities);
		sort(cities.begin(), cities.end());
		print_results(cities);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}