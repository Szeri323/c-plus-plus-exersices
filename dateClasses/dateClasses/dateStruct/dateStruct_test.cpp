#include "dateStruct.h"
#include "../../../headers/std_lib_facilities.h"

// unit tests

void today_test(int y, int m, int d) {
	// Creates Date object and checks if fields are correct
	Date today;
	init_day(today, y, m, d);
	if (today.y == 1978 && today.m == 7 && today.d == 20) {
		return;
	}
	error("Invalid today date object or fileds.");
}

void tomorrow_test(int y, int m, int d) {
	Date today;
	init_day(today, y, m, d);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == 1978 && tomorrow.m == 7 && tomorrow.d == 21) {
		return;
	}
	error("Invalid tomorrow date object or fileds.");
}

void next_month_test(int y, int m, int d) {
	Date today;
	init_day(today, y, m, d);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == 1978 && tomorrow.m == 8 && tomorrow.d == 1) {
		return;
	}
	error("Invalid next month.");
}

void next_year_test(int y, int m, int d) {
	Date today;
	init_day(today, y, m, d);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == 1979 && tomorrow.m == 1 && tomorrow.d == 1) {
		return;
	}
	error("Invalid next year.");
}

bool tests() {
	try {
		today_test(1978, 7, 20);
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