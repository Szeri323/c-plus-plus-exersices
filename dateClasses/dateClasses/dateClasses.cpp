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
		cout << endl;


		/*dateClass::Date today(2024, dateClass::Month::jan, 1);
		dateClass::Date tomorrow = today;

		for (int i = 1; i <= 366; ++i) {
			cout << "Next day." << endl;
			tomorrow.add_day();
			cout << today << endl;
			cout << tomorrow << endl;
		}*/


		/*dateClass::Date today2(2013, dateClass::Month::dec, 31);
		dateClass::Date next_month = today2;

		for (int i = 1; i <= 13; ++i) {
			cout << "Next month." << endl;
			next_month.add_month();
			cout << today2 << endl;
			cout << next_month << endl;
		}*/


		/*dateClass::Date today3(2017, dateClass::Month::jan, 31);
		dateClass::Date next_year = today3;

		for (int i = 1; i <= 12; ++i) {
			cout << "Next year." << endl;
			next_year.add_year();
			cout << today3 << endl;
			cout << next_year << endl;
		}*/

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}