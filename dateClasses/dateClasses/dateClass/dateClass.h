#pragma once
#include "../../../../headers/std_lib_facilities.h"

// cons - It allwos to use object before initialization - solved
// cons - leave filed of the struct public
namespace dateClass {
	
	class Date {
	public:
		Date(int y, int m, int d);

		int const year() { return y; };
		int const month() { return m; };
		int const day() { return d; };
		int const max_days() { return max_d; };
		bool const leapyear() { return ly; };

		void add_day(int n);

		// operator overloading <<
		friend ostream& operator<<(ostream& os, Date& dd);

	private:
		int y;      // year
		int m;      // month
		int d;      // day
		bool ly = false;
		int max_d; // max number of days in month
	};

	// helper functions
	bool is_leapyear(int y, int m, int d);
	int set_max_days_for_month(int m, bool leapyear);

	

}