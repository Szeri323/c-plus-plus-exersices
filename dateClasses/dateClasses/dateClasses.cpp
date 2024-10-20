#include "dateStruct_test.h"
#include "../../../headers/std_lib_facilities.h"

//class 

//operator <<

//test for class leapyear, months only from 1-12 and days from 1-31
//invalid sample of test data (2004,13,-5)

int main() {
	if (tests()) {
		cout << "All good." << endl;
	}
	else {
		cout << "Some of tests did not pass." << endl;
	}
}