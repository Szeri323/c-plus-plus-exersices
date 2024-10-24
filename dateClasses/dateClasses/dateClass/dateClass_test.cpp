#include "./dateClass.h"
#include "../../../headers/std_lib_facilities.h"

// unit tests

void today_test(int y, int m, int d) {
	// Creates Date object and checks if fields are correct
	Date today(y, m, d);
	if (today.y == y && today.m == m && today.d == d) {
		return;
	}
	error("Invalid today date object or fileds.");
}

void tomorrow_test(int y, int m, int d) {
	Date today(y, m, d);
	Date tomorrow = today;
	tomorrow.add_day(1);
	// test for the last day of the year
	if (d == today.max_d && m == 12) {
		if (tomorrow.y == y + 1 && tomorrow.m == 1 && tomorrow.d == 1) {
			return;
		}
	}
	// test for the last day of the month
	if (d == today.max_d) {
		if (tomorrow.y == y && tomorrow.m == m + 1 && tomorrow.d == 1) {
			return;
		}
	}
	// test for normal day
	if (tomorrow.y == y && tomorrow.m == m && tomorrow.d == d + 1) {
		return;
	}
	error("Invalid tomorrow date object or fileds.");
}

void tests() {

	// correct dates
	vector<int> y{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 };
	vector<int> m{ 2,3,2,2,9,2,2 };
	vector<int> d{ 28,5,28,29,24,17,29 };

	// incorrect dates
	vector<int> iy{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 };
	vector<int> im{ 2,35,2,5,33,2,12 };
	vector<int> id{ 29,77,29,759,24,29,32 };

	cout << "Today correct dates tests:" << endl;
	for (int i = 0; i < y.size(); ++i) {
		try {
			today_test(y[i], m[i], d[i]);
			cout << "Test " << i + 1 << " passed." << endl;
		}
		catch (exception& e) {
			cout << "Test " << i + 1 << " did not passed." << endl;
			cout << e.what() << endl;
		}
	}

	// waits for an exception because of incorrect dates and then passes the test
	cout << "Today incorrect tests:" << endl;
	for (int i = 0; i < iy.size(); ++i) {
		try {
			today_test(iy[i], im[i], id[i]);
			cout << "Test " << i + 1 << " did not passed." << endl;
		}
		catch (exception& e) {
			cout << "Test " << i + 1 << " passed." << endl;
			cout << e.what() << endl;
		}
	}

	cout << "Tomorrow correct dates tests:" << endl;
	for (int i = 0; i < y.size(); ++i) {
		try {
			tomorrow_test(y[i], m[i], d[i]);
			cout << "Test " << i + 1 << " passed." << endl;
		}
		catch (exception& e) {
			cout << "Test " << i + 1 << " did not passed." << endl;
			cout << e.what() << endl;
		}
	}

	// waits for an exception because of incorrect dates and then passes the test
	cout << "Tomorrow incorrect dates tests:" << endl;
	for (int i = 0; i < iy.size(); ++i) {
		try {
			tomorrow_test(iy[i], im[i], id[i]);
			cout << "Test " << i + 1 << " did not passed." << endl;
		}
		catch (exception& e) {
			cout << "Test " << i + 1 << " passed." << endl;
			cout << e.what() << endl;
		}
	}
}