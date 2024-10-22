#include "./dateStruct/dateStruct.h"
#include "../../../headers/std_lib_facilities.h"

bool is_leapyear(int y, int m, int d) {
	if (y % 4 == 0 && y % 100 != 0 && y % 400 != 0 || y % 4 == 0 && y % 100 == 0 && y % 400 == 0) {
		return true;
	}
	return false;
}

int set_max_days_for_month(int m, bool leapyear) {
	switch (m) {
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31;
	case 4:	case 6: case 9: case 11:
		return 30;
	case 2:
		if (leapyear)
			return 29;
		else
			return 28;
	}
}

void init_day(Date& dd, int y, int m, int d) {
	// checks if date contains correct year, month and day
	dd.leapyear = is_leapyear(y, m, d);
	dd.max_d = set_max_days_for_month(m, dd.leapyear);
	
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