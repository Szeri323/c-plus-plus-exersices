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

void calculate() {
	int max;
	cout << "Pass max range for primes: " << endl;
	cin >> max;
	vector<int> myPrimes = simplePrimes(max);
	/*vector<int> primes = eratostenesPrimes(max);*/
	// all primes for range form 2 to max
	/*for (int x : myPrimes)
		cout << x << " ";
	cout << endl;
	for (int x : primes)
		cout << x << " ";
	cout << endl;*/
	// n primes from vector
	cout << "Write how many numbers from vector myPrimes you want to see:";
	int n;
	cin >> n;
	if (n > myPrimes.size()) error("Number is bigger that vector size.");
	cout << n << " primes form My primes vector." << endl;
	for (int i = 0; i < n - 1; ++i) {
		cout << myPrimes[i] << " ";
	}
}

int main() {
	try {
		calculate();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}