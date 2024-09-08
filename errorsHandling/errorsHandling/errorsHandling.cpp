#include "../../../headers/std_lib_facilities.h"

int area(int length, int width) {
    if (length <= 0 || width <= 0) return -1;
    return length * width;
}

int framed_area(int x, int y) {
    if (x <= 2 || y <= 2) return -1;
    return area(x - 2, y - 2);
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
    if (area1 <= 0) return -1;
    int area2 = framed_area(1, z);
    if (area2 == -1) return -1;
    int area3 = framed_area(y, z);
    if (area1 == 0 || area3 == 0)
        return -1;
    double ratio = double(area1 / area3);
    return int(ratio);
}

int main() {
    int x, y, z;
    while (cin >> x >> y >> z) {
        int result = f(x, y, z);
        if (result == -1)
            cout << "Something went wrong.";
        else {
            cout << "F: " << result << endl;
        }
    }
}