#pragma once
namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	class Date {
	public:
		class Invalid {}; // For exceptions
		Date(int y, Month m, int d); // Checks if date is correct and execute initialization
		Date(); // Default constructor
		// Default copy operations are sufficient

		// non-modifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

	private:
		int y;
		Month m;
		int d;

	};
	bool is_date(int y, Month m, int d); // true if date is correct

	bool leapyear(int y); // true if y is leapyear

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
} // Chrono