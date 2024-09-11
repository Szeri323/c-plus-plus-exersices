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
int main()
{
    char unit = 'c';
    double degrees = 0;       // variable for input data
    double result;
    cout << "Pass degrees and units: " << endl;
    cin >> degrees >> unit;             // taking temperature to input variable
    if (unit == 'c') {
        result = ctok(degrees); // kelvins to celcius conversion
    }
    else if (unit == 'k') {
        result = ktoc(degrees);
    }
    else {
        cout << "Not supported unit.";
        return -1;
    }
    cout << result << endl;   // printing temperature
}