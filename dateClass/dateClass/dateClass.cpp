#include "../../../headers/std_lib_facilities.h"

class Year {
	// Class defines min and max rage of year value


	// Static constexpr defines that is only one instance of min and max
	static constexpr int min = 1800;
	static constexpr int max = 2200;
public:
	class Invalid {};
	Year(int x) : y(x) {
		if (x<min || x>max) throw Invalid();
	}
	int year() { return y; }
private:
	int y;
};

enum class Month {
	jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Date {
public:
	// naive konstructor, we have int year besides of Year type
	Date(int year, Month month, int day) {};
private:
	int year = 1970;
	Month month = Month::jan;
	int day = 1;
};

int main() {
	Date date{ 2004, Month::feb, 5 };
	// Year initalize only when min/max condition is true and return int value
	Date date2{ Year(2004).year(), Month::feb, 5};
}