#include "../../../headers/std_lib_facilities.h"

int main() {
	for (int i = 48; i < 123; ++i) {
		if (i >= 58 && i <= 64 || i >= 91 && i <= 96) {
			continue;
		}
		cout << char(i) << "\t" << i << "\n";
	}
}