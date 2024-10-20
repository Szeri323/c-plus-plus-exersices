#pragma once
struct Date {
	int y;      // year
	int m;      // month
	int d;      // day
};
void init_day(Date& dd, int y, int m, int d);
void add_day(Date& dd, int n);