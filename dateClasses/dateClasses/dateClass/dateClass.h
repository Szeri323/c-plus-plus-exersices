#pragma once
#include "../../../headers/std_lib_facilities.h"

// cons - It allwos to use object before initialization - solved
// cons - leave filed of the struct public

class Date {
public:
	Date(int y, int m, int d);
	void add_day(int n);
private:
	int y;      // year
	int m;      // month
	int d;      // day
	bool leapyear;
	int max_d; // max number of days in month
};
ostream& operator<<(ostream& os, const Date& dd);