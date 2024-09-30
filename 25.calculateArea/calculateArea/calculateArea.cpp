#include "../../../headers/std_lib_facilities.h"

double square_area(double sides_length) {
	if (sides_length <= 0) error("Sides must be positive.");
	return sides_length * sides_length;
}

double rectangle_area(double length, double width) {
	if (length <= 0 || width <= 0) error("Arguments must be positive.");
	int a = length * width;
	if (a <= 0) error("Result must be positive.");
	return a;
}

double hexagon_area(double sides_length) {
	if (sides_length <= 0) error("Sides must be positive.");
	return 6 * (sides_length * sides_length * sqrt(3)) / 4;
}

int main() {
	int sides;
	bool sides_equal;
	while (cout << "How many sides? " << endl, cin >> sides, cout << "Sides are equal? (0,1)" << endl, cin >> sides_equal) {
		try {
			if (sides_equal == true) {
				if (sides == 4) {
					double sides_length;
					cout << "Pass sides length: " << endl;
					cin >> sides_length;
					cout << "Square area is: " << square_area(sides_length) << endl;
				}
				if (sides == 6) {
					double sides_length;
					cout << "Pass sides length: " << endl;
					cin >> sides_length;
					cout << "Hexagon area is: " << hexagon_area(sides_length) << endl;
				}
			}
			else {
				if (sides == 4) {
					int length;
					int width;
					cout << "Pass length and width: " << endl;
					cin >> length >> width;
					cout << "Rectangle area is: " << rectangle_area(length, width) << endl;

				}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}