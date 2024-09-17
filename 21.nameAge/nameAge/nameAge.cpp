#include "../../../headers/std_lib_facilities.h"

class Name_value {
public:
	void set(string name, int age) {
		this->name = name;
		this->age = age;
	}
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

int main() {
	vector<Name_value> v;
	string name;
	int age;
	bool flag = false;
	while (cin >> name >> age) {
		if (name == "Nosurname" && age == 0) break;
		Name_value p;
		p.set(name, age);
		for (Name_value x : v) {
			if (x.getName() == name) error("We have duplicate in names.");
		}
		v.push_back(p);
	}

	for (Name_value x : v) {
		cout << x.getName() << " " << x.getAge() << endl;
	}

	bool next = false;
	name = "";
	cout << "Do you want check some names?" << endl;
	cin >> next;
	if (next) {
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
		return 0;
	}
	age = 0;
	cout << "Do you want check some ages?" << endl;
	cin >> next;
	if (next) {
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
		return 0;
	}




	/*vector<string> names;
	vector<int> ages;
	string temp_s;
	int temp_i;
	while (cin >> temp_s >> temp_i) {
		if (temp_s == "NoSurname" && temp_i == 0) {
			break;
		}
		names.push_back(temp_s);
		ages.push_back(temp_i);
	}
	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << " " << ages[i] << endl;
	}
	bool next = false;
	string name = "";
	cout << "Do you want check some names?" << endl;
	cin >> next;
	if (next) {
		while (cin >> name) {
			if (name == "NoName") {
				break;
			}
			int temp = 0;
			for (int i = 0; i < names.size(); ++i) {
				if (name == names[i]) {
					temp = ages[i];
				}
			}
			if (temp != 0) {
				cout << temp << endl;
			}
			else {
				cout << "Name not found." << endl;
			}
		}
	}
	else {
		return 0;
	}
	int age = 0;
	cout << "Do you want check some names?" << endl;
	cin >> next;
	if (next) {
		while (cin >> age) {
			if (age == -1) {
				break;
			}
			string temp = "";
			for (int i = 0; i < ages.size(); ++i) {
				if (age == ages[i]) {
					temp = names[i];
				}
			}
			if (temp != "") {
				cout << temp << endl;
			}
			else {
				cout << "Age not found." << endl;
			}
		}
	}
	else {
		return 0;
	}*/
}