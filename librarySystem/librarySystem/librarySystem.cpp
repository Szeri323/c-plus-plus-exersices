#include "../../../headers/std_lib_facilities.h"
#include "Book.h"

int main() {
	Book b = { 1,2,3, "a", "Alloha", "Marek", "21/05/1999"};
	cout << b.get_ISBN_number() << endl;
	cout << b.get_availability() << endl;
	cout << b.get_title() << endl;
	cout << b.get_author() << endl;
	cout << b.get_copyright_date() << endl;
}