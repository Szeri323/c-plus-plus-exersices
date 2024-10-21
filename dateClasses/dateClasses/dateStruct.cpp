#include "./dateStruct/dateStruct.h"
#include "../../../headers/std_lib_facilities.h"

void init_day(Date& dd, int y, int m, int d) {
	// checks if date contains correct year, month and day
	cout << y << endl;
	if (y % 4 == 0 && y % 100 != 0 && y % 400 != 0 || y % 4 == 0 && y % 100 == 0 && y % 400 == 0) {
		dd.leapyear = true;
	}
	else {
		dd.leapyear = false;
	}
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