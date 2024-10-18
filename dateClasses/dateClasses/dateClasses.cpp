#include "../../../headers/std_lib_facilities.h"

//class 

//operator <<

//test for class leapyear, months only from 1-12 and days from 1-31
//invalid sample of test data (2004,13,-5)

// struct *
struct Date {
	int y;      // rok
	int m;      // miesi¹c
	int d;      // dzieñ
};

void init_day(Date& dd, int y, int m, int d) {
	if (y >= 0 && m > 0 && m < 13 && d>0 && d < 32) {
		dd.y = y;
		dd.m = m;
		dd.d = d;
	}
}

void add_day(Date& dd, int n) {
	// make different days max for different months
	if (dd.d < 31) {
		++dd.d;
	}
	else {
		if (dd.m < 12) {
			dd.d = 1;
			++dd.m;
		}
		else {
			dd.d = 1;
			dd.m = 1;
			++dd.y;
		}
	}
}

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

int main() {
	if (tests()) {
		cout << "All good." << endl;
	}
	else {
		cout << "Some of tests did not pass." << endl;
	}
}