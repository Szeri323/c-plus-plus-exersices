#include "../../../headers/std_lib_facilities.h"

int main() {
	string word = "test";
	int sum = 0;
	for (int i = 0; i < word.size(); ++i) {
		sum += int(word[i]);
	}
	cout << sum;
}