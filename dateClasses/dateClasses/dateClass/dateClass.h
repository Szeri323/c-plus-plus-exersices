#pragma once
#include "../../../../headers/std_lib_facilities.h"

namespace dateClass {
	
	enum class Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:
		// constructor
		Date(int y, Month m, int d);

		// unmatable methods
		int year() const { return y; };
		Month month() const { return m; };
		int day() const { return d; };
		int max_days() const { return max_d; };
		bool leapyear() const { return ly; };

		// mutable methods
		void add_day();
		void add_month();
		void add_year();
		void add_n_days(int n);
		void add_n_months(int n);
		void add_n_years(int n);

		// operator overloading <<
		friend ostream& operator<<(ostream& os, Date& dd);

	private:
		int y;      // year
		Month m;      // month
		int d;      // day
		bool ly = false;
		int max_d; // max number of days in month
	};

	// helper functions
	bool is_leapyear(int y);
	int calc_max_days_for_month(Month m, bool leapyear);

}