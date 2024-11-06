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

}
bool operator !=(const Name_pairs np, const Name_pairs np2) {

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
	cout << "Printing results:" << endl;
	//test.print();
	cout << test << endl;
	//test.sort();
	cout << "Printing results:" << endl;
	test.print();
}