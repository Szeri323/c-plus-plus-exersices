#include "../../../headers/std_lib_facilities.h"

class Temp {
public:
    Temp() : high_temp(-1000), low_temp(1000), sum(0), number_of_temps(0) {}
    void set_values(double temp);
    double get_high_temp();
    double get_low_temp();
    double get_sum();
    int get_number_of_temps();
private:
    double high_temp;
    double low_temp;
    double sum;
    int number_of_temps;
};

void Temp::set_values(double temp) {
    ++number_of_temps;
    if (temp > high_temp) high_temp = temp;
    if (temp < low_temp) low_temp = temp;
    sum += temp;
}

double Temp::get_high_temp() {
    return high_temp;
}

double Temp::get_low_temp() {
    return low_temp;
}

double Temp::get_sum() {
    return sum;
}

int Temp::get_number_of_temps() {
    return number_of_temps;
}

void get_temps(Temp &t) {
    int temp = 0;
    while (cin >> temp) {
        t.set_values(temp);
    }
    
}

void print_results(Temp t) {
    cout << "Highest temperature : " << t.get_high_temp() << endl;
    cout << "Lowest temperature : " << t.get_low_temp() << endl;
    cout << "Average temperature : " << t.get_sum() / t.get_number_of_temps() << endl;
}

int main() {
    try {
        Temp t;
        get_temps(t);
        print_results(t);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }

}