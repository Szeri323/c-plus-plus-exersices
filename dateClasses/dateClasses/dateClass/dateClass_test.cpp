#include "./dateClass.h"
#include "../../../../headers/std_lib_facilities.h"

// unit tests
namespace dateClass {

	void today_test(int y, Month m, int d) {
		// Creates Date object and checks if fields are correct
		Date today(y, m, d);
		if (today.year() == y && today.month() == m && today.day() == d) {
			return;
		}
		error("Invalid today date object or fileds.");
	}

	void tomorrow_test(int y, Month m, int d) {
		Date today(y, m, d);
		Date tomorrow = today;
		tomorrow.add_day(1);
		// test for the last day of the year
		if (d == today.max_days() && m == Month::dec) {
			if (tomorrow.year() == y + 1 && tomorrow.month() == Month::jan && tomorrow.day() == 1) {
				return;
			}
		}
		// test for the last day of the month
		if (d == today.max_days()) {
			if (tomorrow.year() == y && tomorrow.month() == static_cast<Month>(static_cast<int>(m)+1) && tomorrow.day() == 1) {
				return;
			}
		}
		// test for normal day
		if (tomorrow.year() == y && tomorrow.month() == m && tomorrow.day() == d + 1) {
			return;
		}
		error("Invalid tomorrow date object or fileds.");
	}

	void tests() {

		// correct dates
		vector<int> y{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 };
		//vector<int> m{ 2,3,2,2,9,2,2 };
		vector<Month> m{ Month::feb,Month::mar,Month::feb,Month::feb,Month::sep,Month::feb,Month::feb};
		vector<int> d{ 28,5,28,29,24,17,29 };

		// incorrect dates
		vector<int> iy{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 };
		//vector<int> im{ 2,35,2,5,33,2,12 };
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
}