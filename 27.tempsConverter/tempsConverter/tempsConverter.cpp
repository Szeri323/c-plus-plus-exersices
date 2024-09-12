#include "../../../headers/std_lib_facilities.h"

double ctok(double c)     // convet celcius to kelvins
{
    if (c < -273.15) error("Invalid data - Temperature below absolute zero.");
    int k = c + 273.15;
    return k;
}
double ktoc(double k)     // convet celcius to kelvins
{
    if (k < 0) error("Invalid data - Temperature below absolute zero.");
    int c = k - 273.15;
    return c;
}
double ctof(double degrees) {
    double result = 9.0 / 5 * degrees + 32;
    cout << result << endl;
    cout << result - int(result) << endl;
    if (result - int(result) != 0) error("Result is not int.");
    return result;
}
double ftoc(double degrees) {
    double result = (degrees - 32) * 5/9;
    cout << result << endl;
    cout << result - int(result) << endl;
    if (result - int(result) != 0) error("Result is not int.");
    return result;
}
int main()
{
    char unit = 'c';
    char desired_unit = 'k';
    double degrees = 0;       // variable for input data
    double result = 0;
    cout << "Pass degrees and units to which unit you want to convert: " << endl;
    cin >> degrees >> unit >> desired_unit;             // taking temperature to input variable
    if (unit == 'c') {
        if (desired_unit == 'k') {
            result = ctok(degrees); // celcius to kelvins conversion
        }
        else if (desired_unit == 'f') {
            result = ctof(degrees); 
        }
        else {
            cout << "Not implemented unit." << endl;
            return 0;
        }
    }
    else if (unit == 'k') {
        if (desired_unit == 'c') {
            result = ktoc(degrees); // kelvins to celcius conversion
        }
        else {
            cout << "Not implemented yet" << endl;
            return 0;
        }
    }
    else if (unit == 'f') {
        if (desired_unit == 'c') {
            result = ftoc(degrees);
        }
        else {
        cout << "Not implemented yet" << endl;
        return 0;
        }
    }
    else {
        cout << "Not supported unit.";
        return -1;
    }
    cout << result << endl;   // printing temperature
}