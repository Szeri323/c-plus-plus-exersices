#include "../../../headers/std_lib_facilities.h"

// Point reader

class Point {
public:
	Point();
	Point(int x, int y);
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
private:
	int x;
	int y;
};

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}
//ifstream& operator>>(ifstream& ist, Point& p) {
//	char char1, char2;
//	int x=3, y=4;
//	ist >> x >> char1 >> y >> char2;
//	if (char1 != ' ' || char2 != ' ') {
//		cout << char1 << " " << char2 << endl;
//		error("Invalid format od data.");
//	}
//	else
//		p = Point(x, y);
//	return ist;
//}

void reading_from_file() {
	cout << "Pass the input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname }; // ist is input stream for the file named in iname
	if (!ist) error("Could not open input file ", iname);
	vector<Point> points;
	int x, y;
	while (ist >> x >> y) {
		points.push_back(Point(x,y));
	}
	for (Point p: points)
		cout << '(' << p.get_x() << ',' << p.get_y() << ")\n";
}

void writing_to_file() {
	cout << "Pass the output file name: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("Could not open output file ", oname);
	vector<Point> points;
	for (int i = 0; i < 4; ++i) {
		Point p(5, 10);
		points.push_back(p);
	}
	for (Point p : points)
		//ost << '(' << p.get_x() << ',' << p.get_y() << ")\n";
		ost << p.get_x() << " " << p.get_y() << " ";
}

// Numbers reader to terminator

void reading_from_file_ints() {
	const char terminator = '*';
	string iname = "numbers.txt";
	ifstream ist{ iname };
	if (!ist) error("Could not open the file.");
	/*while (ist) {
		char x;
		ist >> x;
		if (x == '*') break;
		cout << x - '0' << " ";
	}*/
	vector<int> v;
	for (int i; ist >> i;) v.push_back(i);
	if (ist.eof()) return;
	if (ist.bad()) error("We can't handle that!");
	if (ist.fail()) {
		ist.clear();
		char c;
		ist >> c;
		if (c != terminator) {
			ist.unget();
			ist.clear(ios_base::failbit);
		}
	}
	for (int x : v)
		cout << x << endl;
}

int main() {
	try {
		reading_from_file_ints();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}