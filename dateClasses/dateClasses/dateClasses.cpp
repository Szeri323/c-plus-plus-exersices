#include "./dateStruct/dateStruct.h"
#include "./dateStruct/dateStruct_test.h"
#include "./dateClass/dateClass.h"
#include "./dateClass/dateClass_test.h"
#include "../../../headers/std_lib_facilities.h"

//class 

//operator <<

//test for class leapyear, months only from 1-12 and days from 1-31
//invalid sample of test data (2004,13,-5)


int main() {
	try
	{
		dateClass::tests();
		cout << "All good." << endl;
		dateClass::Date today(2017, dateClass::Month::jan, 31);
		dateClass::Date tomorrow = today;
		tomorrow.add_day(1);
		cout << today << endl;
		cout << tomorrow << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}