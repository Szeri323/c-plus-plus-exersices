#include "../../../headers/std_lib_facilities.h"

//class 

//operator <<

//test for class leapyear, months only from 1-12 and days from 1-31
//invalid sample of test data (2004,13,-5)

// struct *
struct Date {
	int y;      // rok
	int m;      // miesi¹c
	int d;      // dzieñ
};

void init_day(Date& dd, int y, int m, int d) {
	if (y >= 0 && m > 0 && m < 13 && d>0 && d < 32) {
		dd.y = y;
		dd.m = m;
		dd.d = d;
	}
}

void add_day(Date& dd, int n) {
	// make different days max for different months
	if (dd.d < 31) {
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

int main() {
	/*Date today = Date(1978, Month::jul, 20);
	Date tomorrow = today.add_day();*/
	// for struct *
	Date today;
	init_day(today, 1978, 7, 20);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	cout << "Today: " << '(' << today.y << ", " << today.m << ", " << today.d << ')' << endl;
	cout << "Tomorrow: " << '(' << tomorrow.y << ", " << tomorrow.m << ", " << tomorrow.d << ')' << endl;
	init_day(today, 1978, 7, 31);
	tomorrow = today;
	add_day(tomorrow, 1);
	cout << "Today: " << '(' << today.y << ", " << today.m << ", " << today.d << ')' << endl;
	cout << "Tomorrow: " << '(' << tomorrow.y << ", " << tomorrow.m << ", " << tomorrow.d << ')' << endl;
	init_day(today, 1978, 12, 31);
	tomorrow = today;
	add_day(tomorrow, 1);
	cout << "Today: " << '(' << today.y << ", " << today.m << ", " << today.d << ')' << endl;
	cout << "Tomorrow: " << '(' << tomorrow.y << ", " << tomorrow.m << ", " << tomorrow.d << ')' << endl;

}