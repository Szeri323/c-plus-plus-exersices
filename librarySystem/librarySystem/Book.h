#pragma once
#include "../../../headers/std_lib_facilities.h"
class Book {
public:
	Book(int n1, int n2, int n3, std::string x, std::string title, std::string author, std::string copyright_date);
	//getters
	bool get_availability() {return is_available;}
	std::string get_ISBN_number() {return ISBN_number;}
	std::string get_title() {return title;}
	std::string get_author() {return author;}
	std::string get_copyright_date() {return copyright_date;}


private:
	bool is_available;
	std::string ISBN_number;
	std::string title;
	std::string author;
	std::string copyright_date;
};