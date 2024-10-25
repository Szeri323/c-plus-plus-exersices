#pragma once
#include "../../../../headers/std_lib_facilities.h"

// cons - It allwos to use object before initialization - solved
// cons - leave filed of the struct public
namespace dateCalass {
	class Date {
	public:
		Date(int y, int m, int d);
		void add_day(int n);
		int const year() { return y; };
		int month() { return m; };
		int day() { return d; };
		int max_days() { return max_d; };
		bool leapyear() { return ly; };
	private:
		int y;      // year
		int m;      // month
		int d;      // day
		bool ly = false;
		int max_d; // max number of days in month
	};
	ostream& operator<<(ostream& os, const Date& dd);
}