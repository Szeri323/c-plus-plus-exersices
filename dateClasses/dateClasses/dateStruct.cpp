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