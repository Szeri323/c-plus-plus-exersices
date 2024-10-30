#include "./dateClass.h"
#include "../../../../headers/std_lib_facilities.h"

namespace dateClass {

	Date::Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {
		// checks if date contains correct year, month and day
		ly = is_leapyear(yy);
		max_d = set_max_days_for_month(mm, ly);

		if (!(yy >= 0 && int(mm) >= 1 && int(mm) <= 12 && dd >= 1 && dd <= max_d)) {
			/*y = yy;
			m = mm;
			d = dd;*/
			error("Invalid year, month, or day.");
		}
	}

	void Date::add_day(int n) {
		// make different days max for different months
		if (d < max_d) {
			++d;
		}
		else {
			if (int(m) < 12) {
				d = 1;
				m = static_cast<Month>(static_cast<int>(m) + 1);
			}
			else {
				d = 1;
				m = Month::jan;
				++y;
			}
			ly = is_leapyear(y);
			max_d = set_max_days_for_month(m, ly);
		}
	}

	bool is_leapyear(int y) {
		if (y % 4 == 0 && y % 100 != 0 && y % 400 != 0 || y % 4 == 0 && y % 100 == 0 && y % 400 == 0) {
			return true;
		}
		return false;
	}

	int set_max_days_for_month(Month m, bool leapyear) {
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