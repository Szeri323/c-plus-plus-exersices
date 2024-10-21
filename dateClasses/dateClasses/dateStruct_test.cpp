#include "./dateStruct/dateStruct.h"
#include "../../../headers/std_lib_facilities.h"

// unit tests

void today_test(int y, int m, int d) {
	// Creates Date object and checks if fields are correct
	Date today;
	init_day(today, y, m, d);
	cout << "Leapyear: " << today.leapyear << endl;
	if (today.y == y && today.m == m && today.d == d) {
		return;
	}
	error("Invalid today date object or fileds.");
}

void tomorrow_test(int y, int m, int d) {
	Date today;
	init_day(today, y, m, d);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == y && tomorrow.m == m && tomorrow.d == d+1) {
		return;
	}
	error("Invalid tomorrow date object or fileds.");
}

void next_month_test(int y, int m, int d) {
	Date today;
	init_day(today, y, m, d);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == y && tomorrow.m == m+1 && tomorrow.d == 1) {
		return;
	}
	error("Invalid next month.");
}

void next_year_test(int y, int m, int d) {
	Date today;
	init_day(today, y, m, d);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == y+1 && tomorrow.m == 1 && tomorrow.d == 1) {
		return;
	}
	error("Invalid next year.");
}

bool tests() {
	try {
		today_test(1978, 7, 20);
		today_test(1979, 7, 20);
		today_test(1900, 7, 20);
		today_test(2000, 7, 20);
		today_test(2016, 7, 20);
		today_test(2400, 7, 20);
		tomorrow_test(1978, 7, 20);
		next_month_test(1978, 7, 31);
		next_year_test(1978, 12, 31);
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}