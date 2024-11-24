#include "../../../headers/std_lib_facilities.h"
#include "Book.h"

int main() {
	Book b = { 1,2,3, "a", "Alloha", "Marek", "21/05/1999"};
	Book b2 = { 1,2,3, "a", "Larnord", "Arnold", "11/09/2004"};
	Book b3 = { 4,5,6, "a", "Elsa", "Monic", "13/01/1983"};
	cout << b.get_ISBN_number() << endl;
	cout << b.get_availability() << endl;
	cout << b.get_title() << endl;
	cout << b.get_author() << endl;
	cout << b.get_copyright_date() << endl;

	cout << (b == b2) << endl;
	cout << (b == b3) << endl;
	cout << (b2 == b3) << endl;

	cout << b << endl;
	cout << b2 << endl;
	cout << b3 << endl;
}