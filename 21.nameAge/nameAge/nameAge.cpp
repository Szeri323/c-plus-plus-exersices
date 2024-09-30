#include "../../../headers/std_lib_facilities.h"

class Name_value {
public:
	Name_value(string name, int age) : name(name), age(age) {}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
private:
	string name;
	int age;
};

vector<Name_value> populate_vector() {
	vector<Name_value> v;
	string name;
	int age;
	bool flag = false;
	while (cin >> name >> age) {
		if (name == "Nosurname" && age == 0) break;
		Name_value p(name, age);
		for (Name_value x : v) {
			if (x.getName() == name) error("We have duplicate in names.");
		}
		v.push_back(p);
	}

	for (Name_value x : v) {
		cout << x.getName() << " " << x.getAge() << endl;
	}
	return v;
}

void additional_acctions(const vector<Name_value> &v) {
	string name = "";
	int age = 0;
	bool choice = false;
	cout << "Do you want check some names yes(1), no (0)?" << endl;
	cin >> choice;
	if (choice) {
		while (cin >> name) {
			bool found = false;
			if (name == "Noname") {
				break;
			}
			for (Name_value x : v) {
				if (x.getName() == name) {
					cout << x.getAge() << endl;
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "Name not found." << endl;
			}
		}
	}
	else {
		return;
	}
	cout << "Do you want check some ages?" << endl;
	cin >> choice;
	if (choice) {
		while (cin >> age) {
			bool found = false;
			if (age < 1) {
				break;
			}
			for (Name_value x : v) {
				if (x.getAge() == age) {
					cout << x.getName() << endl;
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "Age not found." << endl;
			}
		}
	}
	else {
		return;
	}
}

int main() {
	try {
		vector<Name_value> v = populate_vector();
		additional_acctions(v);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}