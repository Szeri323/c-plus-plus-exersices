#include "./dateStruct/dateStruct.h"
#include "../../../headers/std_lib_facilities.h"

void init_day(Date& dd, int y, int m, int d) {
	// checks if date contains correct year, month and day
	if (y % 4 == 0 && y % 100 != 0 && y % 400 != 0 || y % 4 == 0 && y % 100 == 0 && y % 400 == 0) {
		dd.leapyear = true;
	}
	else {
		dd.leapyear = false;
	}
	switch (m) {
	case 1:
		dd.max_d = 31;
		break;
	case 2:
		if (dd.leapyear)
			dd.max_d = 29;
		else
			dd.max_d = 28;
		break;
	case 3:
		dd.max_d = 31;
		break;
	case 4:
		dd.max_d = 30;
		break;
	case 5:
		dd.max_d = 31;
		break;
	case 6:
		dd.max_d = 30;
		break;
	case 7:
		dd.max_d = 31;
		break;
	case 8:
		dd.max_d = 31;
		break;
	case 9:
		dd.max_d = 30;
		break;
	case 10:
		dd.max_d = 31;
		break;
	case 11:
		dd.max_d = 30;
		break;
	case 12:
		dd.max_d = 31;
		break;
	}

	if (y >= 0 && m >= 1 && m <= 12 && d >= 1 && d <= dd.max_d) {
		dd.y = y;
		dd.m = m;
		dd.d = d;
	}
}

void add_day(Date& dd, int n) {
	// make different days max for different months
	if (dd.d < dd.max_d) {
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