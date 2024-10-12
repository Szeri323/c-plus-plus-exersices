#include "../../../headers/std_lib_facilities.h"

// enums

enum class Month {
	jan = 0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m) {
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

vector<string> month_tbl{ "Styczeñ", "Luty", "Marzec", "Kwiecieñ", "Maj", "Czerwiec", "Lipiec", "Sierpieñ", "Wrzesieñ", "PaŸdziernik", "Listopad", "Grudzieñ"};

ostream& operator<<(ostream& os, Month m) {
	return os << month_tbl[int(m)];
}

// "normal" enums

enum Number {
	one = 1, two, three
};

int main() {
	cout << "Number: " << Number::one << endl;
	Month m = Month::jan;
	cout << int(m) << endl;
	cout << m << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;	
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;	
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;	
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;	
	cout << int(m) << endl;
	++m;
	cout << m << endl;
	cout << int(m) << endl;
	++m;
	cout << m << endl;
}