#include "./dateStruct.h"
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

Date::Date(int yy, int mm, int dd) {
	// checks if date contains correct year, month and day
	leapyear = is_leapyear(yy, mm, dd);
	max_d = set_max_days_for_month(mm, leapyear);

	if (yy >= 0 && mm >= 1 && mm <= 12 && dd >= 1 && dd <= max_d) {
		y = yy;
		m = mm;
		d = dd;
	}
}

void Date::add_day(int n) {
	// make different days max for different months
	if (d < max_d) {
		++d;
	}
	else {
		if (m < 12) {
			d = 1;
			++m;
		}
		else {
			d = 1;
			m = 1;
			++y;
		}
		leapyear = is_leapyear(y, m, d);
		max_d = set_max_days_for_month(m, leapyear);
	}
}

ostream& operator<<(ostream& os, const Date& dd) {
	os << "Year: " << dd.y << " Month: " << dd.m << " Day: " << dd.d << " Max days of month: " << dd.max_d << " Is Leapyear: " << dd.leapyear << endl;
	return os;
}