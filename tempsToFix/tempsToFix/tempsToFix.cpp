#include "../../../headers/std_lib_facilities.h"

double ctok(double c)     // convet celcius to kelvins
{
    int k = c + 273.15;
    return k;
}
int main()
{
    double c = 0;         // variable for input data
    cin >> c;             // taking temperature to input variable
    double k = ctok(c); // temperature conversion
    cout << k << endl;   // printing temperature
}