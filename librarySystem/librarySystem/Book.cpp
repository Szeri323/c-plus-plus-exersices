#include "Book.h"
#include "../../../headers/std_lib_facilities.h"

Book::Book(int n1, int n2, int n3, std::string x, std::string title, std::string author, std::string copyright_date) : is_available(1), title(title),
	author(author), copyright_date(copyright_date) {
	ISBN_number = std::to_string(n1) + '-' + std::to_string(n2) + '-' + std::to_string(n3) + '-' + x;
}

bool Book::borrow_book() {
	/*
	check if book is available
	make book unavailable
	get date of borrowing
	set date of returning
	*/
	return true;
}
bool Book::return_book() {
	/*
	check if book if reserved
	check date of returning
		if the book is overdue
		else
	make book available
	*/
	return true;
}

bool Book::operator ==(Book b) { 
	return (ISBN_number == b.ISBN_number); 
}

bool Book::operator !=(Book b) {
	return (ISBN_number != b.ISBN_number);
}

ostream& operator <<(ostream& os, Book b) {
	return os << 
		"Title: " << b.get_title() << endl << 
		"Author: " << b.get_author() << endl << 
		"ISBN: " << b.get_ISBN_number();
}
