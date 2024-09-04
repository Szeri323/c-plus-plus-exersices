#include "../../../headers/std_lib_facilities.h"

int main() {
	vector<double> cities;
	double temp, min = 0, max = 0, sum = 0;
	bool flag = true;
	while (cin >> temp) {
		if (flag == true) {
			min = temp;
			max = temp;
			flag = false;
		}
		if (temp < min) {
			min = temp;
		}
		if (temp > max) {
			max = temp;
		}
		cities.push_back(temp);
		sum += temp;
	}
	cout << "Sum: " << sum << endl;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Avg: " << sum / cities.size() << endl;

}