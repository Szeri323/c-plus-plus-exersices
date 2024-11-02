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
		tomorrow.add_day();
		// test for the last day of the year
		if (d == today.max_days() && m == Month::dec) {
			if (tomorrow.year() == y + 1 && tomorrow.month() == Month::jan && tomorrow.day() == 1) {
				return;
			}
		}
		// test for the last day of the month but not last day of the year
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

	void next_month_test(int y, Month m, int d) {
		Date today(y, m, d);
		Date next_month = today;
		next_month.add_month();
		// test for last month but not last day
		if (m == Month::dec && !(d == today.max_days())) {
			if (next_month.year() == y + 1 && next_month.month() == Month::jan && next_month.day() == d) {
				return;
			}
		}
		// test for last month and last day
		if (m == Month::dec && d == today.max_days()) {
			if (next_month.year() == y + 1 && next_month.month() == Month::jan && next_month.day() == next_month.max_days()) {
				return;
			}
		}
		// test for last day of month but not last month of the year
		if (d == today.max_days() && !(m == Month::dec)) {
			if (next_month.month() == static_cast<Month>(static_cast<int>(m) + 1) && next_month.day() == next_month.max_days()) {
				return;
			}
		}
		// test for every day but not last day of month
		if (next_month.year() == y && next_month.month() == static_cast<Month>(static_cast<int>(m) + 1) && next_month.day() == d) {
			return;
		}
		error("Invalid tomorrow date object or fileds.");
	}

	void next_year_test(int y, Month m, int d) {
		Date today(y, m, d);
		Date next_year = today;
		next_year.add_year();
		if (next_year.year() == ++y) {
			return;
		}
		error("Invalid tomorrow date object or fileds.");
	}

	void add_n_days_test(int y, Month m, int d, int n) {}
	void add_n_months_test(int y, Month m, int d, int n) {}
	void add_n_years_test(int y, Month m, int d, int n) {}

	void tests() {

		// correct dates
		vector<int> y{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 , 2013 };
		//vector<int> m{ 2,3,2,2,9,2,2 };
		vector<Month> m{ Month::feb, Month::mar, Month::feb, Month::feb, Month::sep, Month::feb, Month::feb, Month::dec};
		vector<int> d{ 28,5,28,29,24,17,29, 31 };

		// incorrect dates
		vector<int> iy{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 };
		//vector<int> im{ 2,35,2,5,33,2,12 };
		vector<Month> im{ Month::feb, Month::mar, Month::feb, Month::may, Month::mar, Month::feb, Month::dec }; // Month enum enforced a valid month, otherwise it will not compile
		vector<int> id{ 29,77,29,759,243,29,32 };

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
		
		cout << "Next month correct dates tests:" << endl;
		for (int i = 0; i < y.size(); ++i) {
			try {
				next_month_test(y[i], m[i], d[i]);
				cout << "Test " << i + 1 << " passed." << endl;
			}
			catch (exception& e) {
				cout << "Test " << i + 1 << " did not passed." << endl;
				cout << e.what() << endl;
			}
		}

		// waits for an exception because of incorrect dates and then passes the test
		cout << "Next month incorrect dates tests:" << endl;
		for (int i = 0; i < iy.size(); ++i) {
			try {
				next_month_test(iy[i], im[i], id[i]);
				cout << "Test " << i + 1 << " did not passed." << endl;
			}
			catch (exception& e) {
				cout << "Test " << i + 1 << " passed." << endl;
				cout << e.what() << endl;
			}
		}
		
		cout << "Next year correct dates tests:" << endl;
		for (int i = 0; i < y.size(); ++i) {
			try {
				next_year_test(y[i], m[i], d[i]);
				cout << "Test " << i + 1 << " passed." << endl;
			}
			catch (exception& e) {
				cout << "Test " << i + 1 << " did not passed." << endl;
				cout << e.what() << endl;
			}
		}

		// waits for an exception because of incorrect dates and then passes the test
		cout << "Next year incorrect dates tests:" << endl;
		for (int i = 0; i < iy.size(); ++i) {
			try {
				next_year_test(iy[i], im[i], id[i]);
				cout << "Test " << i + 1 << " did not passed." << endl;
			}
			catch (exception& e) {
				cout << "Test " << i + 1 << " passed." << endl;
				cout << e.what() << endl;
			}
		}




		// Test for next dates

		// TODO - add date generator and all date cases for tests
		// TODO - Date generator for tests
		//vector<int> year{ 1978, 1979, 1900, 2000, 2016, 2300, 2400 , 2013 };
		////vector<int> m{ 2,3,2,2,9,2,2 };
		//vector<Month> month{ Month::jan, Month::feb, Month::mar, Month::apr, Month::may, Month::jun, Month::jul, Month::aug, Month::sep, Month::oct, Month::nov, Month::dec };
		//vector<int> day{ 28,5,28,29,24,17,29, 31 };

		//for (int i = 0; i < year.size(); ++i) {
		//	try {

		//	}
		//	catch (exception& e) {

		//	}
		//}



	}
}