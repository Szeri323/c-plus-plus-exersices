#include "../../../headers/std_lib_facilities.h"

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

int main() {
	/*vector<int> v;
	fibonacci(1, 2, v, 100);
	print("somevector", v);*/
	vector<int> v1{ 1,3,5,7,9 };
	vector<int> v2 = swap1(v1);
	print("test", v2);
	swap2(v1);
	print("test2", v1);
	vector<string> strings{ "apple", "banana", "orange" };
	vector<string> strings2 = swap1(strings);
	swap2(strings);
	cout << endl;
	print("test", strings2);
	print("test", strings);

}