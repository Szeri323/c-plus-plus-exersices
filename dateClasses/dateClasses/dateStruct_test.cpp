#include "../../../headers/std_lib_facilities.h"
#include "dateStruct.cpp"

// unit tests

bool today_test() {
	// Creates Date object and checks if fields are correct
	Date today;
	init_day(today, 1978, 7, 20);
	if (today.y == 1978 && today.m == 7 && today.d == 20) {
		return true;
	}
	error("Invalid today date object or fileds.");
}

bool tomorrow_test() {
	Date today;
	init_day(today, 1978, 7, 20);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == 1978 && tomorrow.m == 7 && tomorrow.d == 21) {
		return true;
	}
	error("Invalid tomorrow date object or fileds.");
}

bool next_month_test() {
	Date today;
	init_day(today, 1978, 7, 31);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == 1978 && tomorrow.m == 8 && tomorrow.d == 1) {
		return true;
	}
	error("Invalid next month.");
}

bool next_year_test() {
	Date today;
	init_day(today, 1978, 12, 31);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	if (tomorrow.y == 1979 && tomorrow.m == 1 && tomorrow.d == 1) {
		return true;
	}
	error("Invalid next year.");
}

bool tests() {
	try {
		today_test();
		tomorrow_test();
		next_month_test();
		next_year_test();
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}