#include "./dateClass.h"
#include "../../../../headers/std_lib_facilities.h"

namespace dateClass {

	// TODO - where it is possible use methods: eg is possible to use add_year insteed of ++y 
	// TODO - write logic for add_n_xxxx 

	Date::Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {
		// checks if date contains correct year, month and day
		ly = is_leapyear(yy);
		max_d = calc_max_days_for_month(mm, ly);

		if (!(yy >= 0 && int(mm) >= 1 && int(mm) <= 12 && dd >= 1 && dd <= max_d)) {
			/*y = yy;
			m = mm;
			d = dd;*/
			error("Invalid year, month, or day.");
		}
	}

	void Date::add_day() {
		// TODO - make logic for many month eg. 62 days how many months???
		if (m == Month::dec && d == max_d) {
			d = 1;
			m = Month::jan;
			++y;
		}
		else if (m != Month::dec && d == max_d) {
			d = 1;
			m = static_cast<Month>(static_cast<int>(m) + 1);
		}
		else {
			++d;
		}
		ly = is_leapyear(y);
		max_d = calc_max_days_for_month(m, ly);
	}

	void Date::add_month() {
		// add month, if it is last month of the year add year, if days is greater than max days of next month adds another month and set days to rest of modulo
		int next_month_max_d;
		if (int(m) == 12) {
		next_month_max_d = calc_max_days_for_month(Month::jan, is_leapyear(y+1));
		}
		else{
		next_month_max_d = calc_max_days_for_month(static_cast<Month>(static_cast<int>(m) + 1), ly);
		}
		if (int(m) < 12 && d <= next_month_max_d) {
			m = static_cast<Month>(static_cast<int>(m) + 1);
		}
		else if (int(m) < 12 && d > next_month_max_d) {
			d = d % next_month_max_d;
			m = static_cast<Month>(static_cast<int>(m) + 2);
		}
		else {
			m = Month::jan;
			++y;
		}

		ly = is_leapyear(y);
		max_d = calc_max_days_for_month(m, ly);
	}

	void Date::add_year() {
		// change year and if days are greater than max days of month set d to max_d
		++y;
		ly = is_leapyear(y);
		max_d = calc_max_days_for_month(m, ly);
		if (d > max_d) {
			d = max_d;
		}
	}

	void Date::add_n_days(int n) {
		// TODO - make logic for many month eg. 62 days how many months???
		if (int(m) <= 12 && d + n <= max_d) {
			d += n;
		}
		else if (int(m) < 12 && d + n > max_d) {
			d = (d + n) % max_d;
			m = static_cast<Month>(static_cast<int>(m) + 1);
		}
		else {
			d = (d + n) % max_d;
			m = Month::jan;
			++y;
		}
		ly = is_leapyear(y);
		max_d = calc_max_days_for_month(m, ly);
	}
	void Date::add_n_months(int n) {
		// TODO - what if jan has 31 but feb only 28 or 29?
		// TODO - add one month and does not change days or month + 1 and days from 1?
		int next_month_max_d;
		if (int(m) + n > 12) {
			next_month_max_d = calc_max_days_for_month(static_cast<Month>((static_cast<int>(m) + n) % 12), ly);
		}
		else {
			next_month_max_d = calc_max_days_for_month(static_cast<Month>(static_cast<int>(m) + n), ly);
		}
		cout << next_month_max_d << endl;
		if (int(m) < 12 && d <= next_month_max_d) {
			m = static_cast<Month>(static_cast<int>(m) + n);
		}
		else if (int(m) < 12 && d > next_month_max_d) {
			d = next_month_max_d;
			m = static_cast<Month>(static_cast<int>(m) + n);
		}
		else if (int(m) == 12 && d <= next_month_max_d) {
			m = Month::jan;
			++y;
		}
		else {
			d = next_month_max_d;
			m = Month::jan;
			++y;
		}
		ly = is_leapyear(y);
		max_d = calc_max_days_for_month(m, ly);
	}
	void Date::add_n_years(int n) {
		y += n;
		ly = is_leapyear(y);
		max_d = calc_max_days_for_month(m, ly);
	}

	bool is_leapyear(int y) {
		if (y % 4 == 0 && y % 100 != 0 && y % 400 != 0 || y % 4 == 0 && y % 100 == 0 && y % 400 == 0) {
			return true;
		}
		return false;
	}

	int calc_max_days_for_month(Month m, bool leapyear) {
		switch (int(m)) {
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			return 31;
		case 4:	case 6: case 9: case 11:
			return 30;
		case 2:
			return leapyear ? 29 : 28;
		default:
			return 0;
		}
	}

	ostream& operator<<(ostream& os, Date& dd) {
		os << "Year: " << dd.year() << " Month: " << int(dd.month()) << " Day: " << dd.day() << " Max days of month: " << dd.max_days() << " Is Leapyear: " << dd.leapyear() << endl;
		return os;
	}
}