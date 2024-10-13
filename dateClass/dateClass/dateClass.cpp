#include "../../../headers/std_lib_facilities.h"

enum class Month {
	jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Date {
public:
	Date(int year, Month month, int day) {};
private:
	int year;
	Month month;
	int day;
};

int main() {
	Date date{ 2004, Month::feb, 5 };
}