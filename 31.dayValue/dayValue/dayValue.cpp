#include "../../../headers/std_lib_facilities.h"

class Days_of_week {
public:
	void populate_vector(const string& day, int value) {
		if (day == "monday" || day == "mon") monday.push_back(value);
		else if (day == "tuesday" || day == "tue") tuesday.push_back(value);
		else if (day == "wednesday" || day == "wed") wednesday.push_back(value);
		else if (day == "thursday" || day == "thu") thursday.push_back(value);
		else if (day == "friday" || day == "fri") friday.push_back(value);
		else if (day == "saturday" || day == "sat") saturday.push_back(value);
		else if (day == "sunday" || day == "sun") sunday.push_back(value);
		else error("Invalid day or value.");
	}
	int sum_of_vector(const vector<int>& day_of_week) {
		int sum = 0;
		for (int x : day_of_week)
			sum += x;
		return sum;
	}
	void static print_vectors(const vector<int>& day_of_week) {
		bool first = true;
		for (int x : day_of_week) {
			if (!first)
				cout << ", ";
			cout << x;
			first = false;
		}
		cout << endl;
	}
	void print_all_vectors() {
		cout << "Values of vectors: " << endl;
		cout << "Monday: "; print_vectors(monday); cout << "Sum: " << sum_of_vector(monday) << endl;
		cout << "Tuesday: "; print_vectors(tuesday); cout << "Sum: " << sum_of_vector(tuesday) << endl;
		cout << "Wednesday: "; print_vectors(wednesday); cout << "Sum: " << sum_of_vector(wednesday) << endl;
		cout << "Thursday: "; print_vectors(thursday); cout << "Sum: " << sum_of_vector(thursday) << endl;
		cout << "Friday: "; print_vectors(friday); cout << "Sum: " << sum_of_vector(friday) << endl;
		cout << "Saturday: "; print_vectors(saturday); cout << "Sum: " << sum_of_vector(saturday) << endl;
		cout << "Sunday: "; print_vectors(sunday); cout << "Sum: " << sum_of_vector(sunday) << endl;
	}
private:
	vector<int> monday;
	vector<int> tuesday;
	vector<int> wednesday;
	vector<int> thursday;
	vector<int> friday;
	vector<int> saturday;
	vector<int> sunday;
};

int main() {
	try {
		Days_of_week dw;
		string day;
		int value;
		cout << "Pass (day, value) pairs correct sheme is full day name, 3 first letters and integer type values: " << endl;
		while (cin >> day >> value) {
			dw.populate_vector(day, value);
		}
		dw.print_all_vectors();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}