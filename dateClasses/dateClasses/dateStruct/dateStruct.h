#pragma once

// cons - It allwos to use object before initialization.

struct Date {
	int y;      // year
	int m;      // month
	int d;      // day
	bool leapyear;
};
void init_day(Date& dd, int y, int m, int d);
void add_day(Date& dd, int n);