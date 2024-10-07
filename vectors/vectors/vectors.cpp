#include "../../../headers/std_lib_facilities.h"

void print(const string& vector_name, const vector<int>& v) {
	cout << vector_name << ": ";
	for (int x : v) {
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

int main() {
	vector<int> v;
	fibonacci(1, 2, v, 100);
	print("somevector", v);
}