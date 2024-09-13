#include "../../../headers/std_lib_facilities.h"

int sum_of_vector(vector<int> day_week) {
	int sum = 0;
	for (int x : day_week)
		sum += x;
	return sum;
}

int main() {
	vector<int> monday;
	vector<int> tuesday;
	vector<int> wednesday;
	vector<int> thursday;
	vector<int> friday;
	vector<int> saturday;
	vector<int> sunday;
	string day;
	int value;
	cout << "Pass day value pairs: " << endl;
	while (cin >> day >> value) {
		if (day == "monday") {
			monday.push_back(value);
		}
		else if (day == "tuesday") {
			tuesday.push_back(value);
		}
		else if (day == "wednesday") {
			wednesday.push_back(value);
		}
		else if (day == "thursday") {
			thursday.push_back(value);
		}
		else if (day == "friday") {
			friday.push_back(value);
		}
		else if (day == "saturday") {
			saturday.push_back(value);
		}
		else if (day == "sunday") {
			sunday.push_back(value);
		}
		else {
			break;
		}
	}
	
	cout << "Monday: " << sum_of_vector(monday) << endl;
	cout << "Tuesday: " << sum_of_vector(tuesday) << endl;
	cout << "Wednesday: " << sum_of_vector(wednesday) << endl;
	cout << "Thursday: " << sum_of_vector(thursday) << endl;
	cout << "Friday: " << sum_of_vector(friday) << endl;
	cout << "Saturday: " << sum_of_vector(saturday) << endl;
	cout << "Sunday: " << sum_of_vector(sunday) << endl;
	
}