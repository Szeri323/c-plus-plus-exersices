#include "../../../headers/std_lib_facilities.h"

int area(int length, int width) {
    cout << "area func called." << endl;
    if (length <= 0 || width <= 0) error("Argument of function area() isn't positive.");
    return length * width;
}

int framed_area(int length, int width) {
    constexpr int frame_width = 2;
    cout << "framed area func called." << endl;
    if (length - frame_width <= 0 || width - frame_width <= 0) error("Argument of function area() called by framed_area() isn't positive.");
    return area(length - frame_width, width - frame_width);
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
    if (area1 <= 0) error("Area isn't positive.");
    int area2 = framed_area(1, z);
    if (area2 <= 0) error("Framed area isn't positive.");
    int area3 = framed_area(y, z);
    if (area3 <= 0) error("Framed area isn't positive.");
    return double(area1 / area3);
}

int main() {
    int x, y, z;
    while (cin >> x >> y >> z) {
        try
        {
            cout << "F: " << f(x, y, z) << endl;
        }
        catch (runtime_error& e)
        {
            cout << "Something went wrong: " << e.what() << endl;
        }
    }
}