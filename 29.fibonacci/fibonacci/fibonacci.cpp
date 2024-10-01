#include "../../../headers/std_lib_facilities.h"

void fibonacci() {
	vector<int> fibonacci;
	fibonacci.push_back(1);
	fibonacci.push_back(1);
	for (int i = 1; i < 100; ++i) {
		fibonacci.push_back(fibonacci[i - 1] + fibonacci[i]);
	}
	for (int x : fibonacci) {
		cout << x << " ";
	}
}

int main() {
	try {
		fibonacci();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}