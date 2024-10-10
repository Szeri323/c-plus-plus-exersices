#include "../../../headers/std_lib_facilities.h"

//template<typename T>
//vector<T> populate_vector(vector<T>& v) {
//	T temp;
//	while (cin) {
//		cin >> temp;
//		if (!cin) {
//			cin.clear();
//			cin.ignore();
//			break;
//		}
//		if (typeid(T) == typeid(string)) {
//			/*if constexpr (is_same<T, string>::value) {*/
//			if (to_string(temp) == "\\") {
//				break;
//				/*}*/
//			}
//		}
//		v.push_back(temp);
//	}
//	return v;
//}

vector<string> populate_vector(vector<string>& v) {
	string temp;
	while (cin) {
		cin >> temp;
		if (!cin) {
			cin.clear();
			cin.ignore();
			break;
		}
		if (temp == "\\") {
			break;
		}
		v.push_back(temp);
	}
	return v;
}
vector<double> populate_vector(vector<double>& v) {
	double temp;
	while (cin) {
		cin >> temp;
		if (!cin) {
			cin.clear();
			cin.ignore();
			break;
		}
		v.push_back(temp);
	}
	return v;
}

int minv(const vector<int>& v) {
	int min = 0;
	bool is_first = 1;
	for (int x : v) {
		if (is_first) {
			min = x;
			is_first = 0;
		}
		else {
			if (x < min) {
				min = x;
			}
		}
	}
	return min;
}

int maxv(const vector<int>& v) {
	int max = 0;
	bool is_first = 1;
	for (int x : v) {
		if (is_first) {
			max = x;
			is_first = 0;
		}
		else {
			if (x > max) {
				max = x;
			}
		}
	}
	return max;
}

double calculate_median(vector<int> v) {
	sort(v.begin(), v.end());
	if (v.size() % 2 == 0) {
		return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
	}
	else {
		return v[v.size() / 2];
	}
}

double calculate_average(const vector<int>& v) {
	int sum = 0;
	for (int x : v) {
		sum += x;
	}
	return sum / v.size();
}

template<typename T>
void print(const string& vector_name, const vector<T>& v) {
	cout << vector_name << ": ";
	for (T x : v) {
		cout << x << " ";
	}
}

vector<int> fibonacci(int x, int y, vector<int>& v, int n) {
	v.push_back(x);
	v.push_back(y);
	for (int i = 1; i < n-1; ++i) {
		v.push_back(v[i - 1] + v[i]);
	}
	return v;
}

template<typename T>
vector<T> swap1(const vector<T>& v1) {
	vector<T> v2;
	for (int i = v1.size()-1; i >= 0; --i) {
		v2.push_back(v1[i]);
	}
	return v2;
}

template<typename T>
void swap2(vector<T>& v) {
	for (int i = 0; i < v.size()/2; ++i) {
		T temp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = temp;
	}
}

void sort_and_order_vectors(vector<string> name, vector<double> age) {
	// Function create copy of name vector then sort names in original one then try to assing ages to the sorted vector based on referenc copy
	for (int i = 0; i < name.size(); ++i) {
		cout << name[i] << " " << age[i] << endl;
	}
	vector<string> names = name;
	sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); ++i) {
		cout << name[i] << " ";
		for (int j = 0; j < names.size(); ++j) {
			if (name[i] == names[j]) {
				cout << age[j] << " " << endl;
			}
		}
	}
}

double calculate_index(vector<double>& price, vector<double>& weight) {
	if (price.size() != weight.size()) error("Vectors sizes are not equal.");
	double index = 0;
	for (int i = 0; i < price.size(); ++i) {
		index += price[i] * weight[i];
	}
	return index;
}

struct Vector_data {
	int minValue;
	int maxValue;
	double median;
	double average;
};

Vector_data make_a_struct(const vector<int>& v) {
	Vector_data vd;
	vd.minValue = minv(v);
	vd.maxValue = maxv(v);
	vd.median = calculate_median(v);
	vd.average = calculate_average(v);
	return vd;
}

void pass_by_reference(const vector<int>& v, int& minValue, int& maxValue, double& median, double& average) {
	minValue = minv(v);
	maxValue = maxv(v);
	median = calculate_median(v);
	average = calculate_average(v);
}

int count_chars_in_string(const string& s) {
	return s.size();
}

vector<int> analize_strings_in_vector(vector<string> v) {
	int minValue = 0;
	int maxValue = 0;
	sort(v.begin(), v.end());
	vector<int> letters_counter;
	for (string s : v) {
		letters_counter.push_back(count_chars_in_string(s));
	}
	minValue = minv(letters_counter);
	maxValue = maxv(letters_counter);
	for (int i = 0; i < letters_counter.size(); ++i) {
		if (letters_counter[i] == minValue) {
			cout << "Min value is: " << minValue << " and it a " << v[i] << endl;
		}
		if (letters_counter[i] == maxValue) {
			cout << "Max value is: " << maxValue << " and it a " << v[i] << endl;
		}
	}
	cout << "First string is " << v[0] << endl;
	cout << "Last string is " << v[v.size()-1] << endl;

	return letters_counter;

}

int main() {
	/*vector<int> v;
	fibonacci(1, 2, v, 100);
	print("somevector", v);*/
	/*vector<int> v1{ 1,3,5,7,9 };
	vector<int> v2 = swap1(v1);
	print("test", v2);
	swap2(v1);
	print("test2", v1);
	vector<string> strings{ "apple", "banana", "orange" };
	vector<string> strings2 = swap1(strings);
	swap2(strings);
	cout << endl;
	print("test", strings2);
	print("test", strings);*/
	/*vector<string> name;
	vector<double> age;
	string n;
	int a;
	cout << "pass five names";
	try {
		name = populate_vector(name);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	cout << "pass age of those persons";
	age = populate_vector(age);
	if (name.size() != age.size()) {
		error("Sizes must be equal.");
	}
	sort_and_order_vectors(name, age);*/
	/*vector<double> price;
	vector<double> weight;
	cout << "prices: " << endl;
	price = populate_vector(price);
	cout << "weights: " << endl;
	weight = populate_vector(weight);
	cout << calculate_index(price, weight) << endl;*/
	/*vector<int> numbers{ 1,2,3,4,5,6,7,1,2,3,4,5,10090 };
	cout << maxv(numbers) << endl;*/
	/*vector<int> v = { 1,2,3,4,5 };
	int minValue = 0;
	int maxValue = 0;
	double median = 0;
	double average = 0;
	Vector_data vd;
	vd = make_a_struct(v);
	cout << "Vector_data: " << vd.minValue << " " << vd.maxValue << " " << vd.median << " " << vd.average << endl;
	pass_by_reference(v, minValue, maxValue, median, average);
	cout << "referances: " << minValue << " " << maxValue << " " << median << " " << average << endl;*/
	vector<string> v{ "a", "ab", "abc", "test" };
	vector<int> v2 = analize_strings_in_vector(v);
	print("ints: ",v2);

}