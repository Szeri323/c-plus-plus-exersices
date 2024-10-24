#include "../../../headers/std_lib_facilities.h"
#pragma once

// cons - It allwos to use object before initialization - solved
// cons - leave filed of the struct public

struct Date {
	int y;      // year
	int m;      // month
	int d;      // day
	bool leapyear; 
	int max_d; // max number of days in month
	Date(int y, int m, int d);
	void add_day(int n);
};
ostream& operator<<(ostream& os, const Date& dd);