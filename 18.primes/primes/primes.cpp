#include "../../../headers/std_lib_facilities.h"


int main() {
	vector<int> primes{ 2 };
	int max;
	cout << "Pass max range for primes: " << endl;
	cin >> max;
	for (int i = 3; i <= max; ++i) {
		if (i % 2 != 0) {
			for (int j = 0; j < primes.size(); ++j) {
				if (i % primes[j] == 0) {
					break;
				}
				if (j == primes.size() - 1) {
					primes.push_back(i);
				}
			}
			
		}
	}
	for (int x: primes)
		cout << x << " ";
}