#include "../../../headers/std_lib_facilities.h"

class Name_pairs{
public:
	void read_names();
	void read_ages();
	void sort();
	void print();
	friend ostream& operator <<(ostream& os, const Name_pairs np);
	friend bool operator ==(const Name_pairs np, const Name_pairs np2);
	friend bool operator !=(const Name_pairs np, const Name_pairs np2);
private:
	vector<string> names;
	vector<double> ages;
};

void Name_pairs::read_names() {
	string name;
	cin >> name;
	names.push_back(name);
}

void Name_pairs::read_ages() {
	int age;
	cin >> age;
	ages.push_back(age);
}

void Name_pairs::sort() {
	vector<string> old_names = names;
	vector<double> old_ages;

	for (int i = 0; i < names.size(); ++i) {
		for (int j = 0; j < names.size(); ++j) {
			if (names[i] < names[j]) {
				string temp = names[i];
				names[i] = names[j];
				names[j] = temp;
				double temp2 = ages[i];
				ages[i] = ages[j];
				ages[j] = temp2;
			}
		}
	}
	for (int i = 0; i < old_names.size(); ++i) {
		for (int j = 0; j < names.size(); ++j) {
			if (old_names[i] == names[j]) {
				old_ages.push_back(ages[i]);
			}
		}
	}

	ages = old_ages;
}

void Name_pairs::print() {
	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << " " << ages[i] << endl;
	}
}

ostream& operator <<(ostream& os, Name_pairs np) {
	for (int i = 0; i < np.names.size(); ++i) {
		os << np.names[i] << " " << np.ages[i] << endl;
	}
	return os;
}

bool operator ==(const Name_pairs np, const Name_pairs np2) {
	if ((np.names.size() == np.ages.size()) && (np2.names.size() == np2.ages.size()) && (np.names.size()==np2.names.size())) {
		for (int i = 0; i < np.names.size(); ++i) {
			if (np.names[i] != np2.names[i] || np.ages[i] != np2.ages[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}
bool operator !=(const Name_pairs np, const Name_pairs np2) {
	return !(np == np2);
}

int main() {
	Name_pairs test;
	int number;
	cout << "Pass the number for: ";
	cin >> number;
	for (int i = 0; i < number; ++i) {
		test.read_names();
		test.read_ages();
	}
	Name_pairs test2;
	cout << "Pass the number for: ";
	cin >> number;
	for (int i = 0; i < number; ++i) {
		test2.read_names();
		test2.read_ages();
	}
	cout << "Printing results test:" << endl;
	cout << test << endl;
	cout << "Printing results test2:" << endl;
	cout << test2 << endl;
	cout << (test == test2) << endl;
	cout << (test != test2) << endl;
}