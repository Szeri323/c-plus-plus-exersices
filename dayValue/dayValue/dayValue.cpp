#include "../../../headers/std_lib_facilities.h"

int sum_of_vector(vector<int> day_of_week) {
	int sum = 0;
	for (int x : day_of_week)
		sum += x;
	return sum;
}

void static print_vectors(vector<int> day_of_week) {
	for (int x : day_of_week)
		cout << x << " ";
	cout << endl;
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
	cout << "Pass (day, value) pairs correct sheme is full day name, 3 first letters and integer type values: " << endl;
	while (cin >> day >> value) {
		if (day == "monday" || day == "mon") {
			monday.push_back(value);
		}
		else if (day == "tuesday" || day == "tue") {
			tuesday.push_back(value);
		}
		else if (day == "wednesday" || day == "wed") {
			wednesday.push_back(value);
		}
		else if (day == "thursday" || day == "thu") {
			thursday.push_back(value);
		}
		else if (day == "friday" || day == "fri") {
			friday.push_back(value);
		}
		else if (day == "saturday" || day == "sat") {
			saturday.push_back(value);
		}
		else if (day == "sunday" || day == "sun") {
			sunday.push_back(value);
		}
		else {
			break;
		}
	}

	cout << endl;
	cout << "Values from vectors: " << endl;
	cout << "Monday: "; 
	print_vectors(monday);
	cout << "Tuesday: ";
	print_vectors(tuesday);
	cout << "Wednesday: ";
	print_vectors(wednesday);
	cout << "Thursday: ";
	print_vectors(thursday);
	cout << "Friday: ";
	print_vectors(friday);
	cout << "Saturday: ";
	print_vectors(saturday);
	cout << "Sunday: ";
	print_vectors(sunday);
	cout << endl;
	cout << "Sum of values from vector: " << endl;
	cout << "Monday: " << sum_of_vector(monday) << endl;
	cout << "Tuesday: " << sum_of_vector(tuesday) << endl;
	cout << "Wednesday: " << sum_of_vector(wednesday) << endl;
	cout << "Thursday: " << sum_of_vector(thursday) << endl;
	cout << "Friday: " << sum_of_vector(friday) << endl;
	cout << "Saturday: " << sum_of_vector(saturday) << endl;
	cout << "Sunday: " << sum_of_vector(sunday) << endl;
	
}