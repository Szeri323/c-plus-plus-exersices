#include "../../../headers/std_lib_facilities.h"

void print_instruction() {
	cout << "Pass value and unit to convert to end use '|':" << endl;
}

void print_results(vector<double> metrics, double min, double max, double sum) {
	cout << "Size of the metrics: " << metrics.size() << "\n";
	cout << "Sum of the metrics: " << sum << 'm' << "\n";
	cout << "Minimum of the metrics: " << min << 'm' << "\n";
	cout << "Maximum of the metrics: " << max << 'm' << "\n";
	sort(metrics.begin(), metrics.end());
	for (double x : metrics)
		cout << x << " ";
}

double conversion(double value, string unit) {
	constexpr double cm_to_m = 0.01;
	constexpr double cal_to_m = 0.0254;
	constexpr double st_to_m = 12 * cal_to_m;
	if (unit == "m") {
		return value;
	}
	else if (unit == "cm") {
		return value * cm_to_m;
	}
	else if (unit == "cal") {
		return value * cal_to_m;
	}
	else if (unit == "st") {
		return value * st_to_m;
	}
	else {
		error("Invalid unit");
	}
}

void calculate() {
	vector<double> metrics;
	double min = 0, max = 0, value = 0, sum = 0;
	string unit;
	bool flag = true;
	while (cin >> value >> unit) {
		cout << value << unit << "\n";
		value = conversion(value, unit);
		metrics.push_back(value);
		sum += value;
		cout << value << "m" << "\n";
		if (flag == true) {
			min = value;
			max = value;
			flag = false;
			cout << "This number is minimum and maximum now." << "\n";
		}
		if (value < min) {
			min = value;
			cout << "This number is minimum now." << "\n";
		}
		if (value > max) {
			max = value;
			cout << "This number is maximum now." << "\n";
		}
	}
	print_results(metrics, sum, min, max);
}



int main() {
	try {
		print_instruction();
		calculate();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}