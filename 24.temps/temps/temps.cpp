#include "../../../headers/std_lib_facilities.h"



int main() {
    vector<double> temps = { -10.9, -2, -4.3, 9 ,-2 ,0, 1, 2, 3, 22, 12, -1, .5 , -20 };
    //vector<double> temps = {  1, 2, 3, 22, 12, .5 };
    //vector<double> temps = {  1 };
    //vector<double> temps = { -10.9, -2, -4.3, -2 };
    double temp = 0;
    double sum = 0;
    double high_temp = temps[0];
    double low_temp = temps[0];
    int number_of_temps = 0;

    while (cin >> temp) {
        ++number_of_temps;
        if (temp > high_temp) high_temp = temp;
        if (temp < low_temp) low_temp = temp;
        sum += temp;
    }
    cout << "Highest temperature : " << high_temp << endl;
    cout << "Lowest temperature : " << low_temp << endl;
    cout << "Average temperature : " << sum / temps.size() << endl;

}