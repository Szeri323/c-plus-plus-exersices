#include "../../../headers/std_lib_facilities.h"

int main() {
	vector<string> names;
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
	}
}