#include "../../../headers/std_lib_facilities.h"

class Point {
public:
	Point();
	friend bool operator==(Point p1, Point p2);
	friend ifstream& operator>>(ifstream& ist, Point& p);
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
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

bool operator==(Point p1, Point p2) {
	return (p1.get_x() == p2.get_x() || p1.get_y() == p2.get_y());
}

ifstream& operator>>(ifstream& ist, Point& p) {
	char char1, char2, char3;
	int x, y;
	ist >> char1 >> x >> char2 >> y >> char3;
	if (!ist) return ist;
	if (char1 != '(' || char2 != ',' || char3 != ')') {
		ist.clear(ios_base::failbit);
		return ist;
	}
	p.set(x, y);
	return ist;
}

vector<Point> reading_from_file() {
	//cout << "Pass the input file name: ";
	string iname = "points.txt";
	//cin >> iname;
	ifstream ist{ iname }; // ist is input stream for the file named in iname
	if (!ist) error("Could not open input file ", iname);
	vector<Point> points;
	for (Point p; ist >> p;) {
		points.push_back(p);
	}
	ist.close();
	return points;
}

void writing_to_file(vector<Point> points) {
	//cout << "Pass the output file name: ";
	string oname = "points.txt";
	//cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("Could not open output file ", oname);
	for (Point p : points)
		ost << '(' << p.get_x() << ',' << p.get_y() << ")\n";
	ost.close();
}

vector<Point> create_vector_from_user_points() {
	cout << "Pass some number of points (x,y):";
	vector<Point> original_points;
	int x, y;
	while (cin >> x >> y) {
		Point p;
		p.set(x, y);
		original_points.push_back(p);
	}
	return original_points;
}

void compare_vectors(vector<Point> vp1, vector<Point> vp2) {
	for (int i = 0; i < vp1.size(); ++i) {
		if (!(vp1[i] == vp2[i])) {
			cout << "Something went worong!" << endl;
			return;
		}
	}
	cout << "Vetors are identical." << endl;
}

void print_vector(vector<Point> vp, string name) {
	cout << name <<":" << endl;
	cout << "Number of elements: " << vp.size() << endl;
	for (Point p : vp)
		cout << '(' << p.get_x() << ',' << p.get_y() << ')' << endl;
}

int main() {
	try {
		vector<Point> original_points = create_vector_from_user_points();
		writing_to_file(original_points);
		vector<Point> points = reading_from_file();
		print_vector(original_points, "Original vector");
		print_vector(points, "Processed vector");
		compare_vectors(original_points, points);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}