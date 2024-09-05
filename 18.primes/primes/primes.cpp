#include "../../../headers/std_lib_facilities.h"

vector<int> simplePrimes(int max) {
	vector<int> primes{ 2 };
	
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
	return primes;
}

vector<int> eratostenesPrimes(int max) {
	vector<int> primes;
	for (int i = 2; i <= max; ++i) {
		primes.push_back(i);
	}

	for (int i = 0; i <= sqrt(max); ++i) {
		for (int j = i+1; j < primes.size(); ++j) {
			if (primes[j] % primes[i] == 0) {
				primes.erase(primes.begin() + j);
			}
		}
	}
	return primes;
}

int main() {
	int max;
	cout << "Pass max range for primes: " << endl;
	cin >> max;
	vector<int> myPrimes = simplePrimes(max);
	vector<int> primes = eratostenesPrimes(max);
	// n primes form vector
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << myPrimes[i] << " ";
	}
	// all primes for range form 2 to max
	/*for (int x: myPrimes)
		cout << x << " ";
	cout << endl;
	for (int x: primes)
		cout << x << " ";*/
}