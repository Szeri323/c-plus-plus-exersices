#include "../../../headers/std_lib_facilities.h"

int area(int lenght, int width);

int main() {
	// Syntax errors
	int s1 = area(7;   // Error: missing ) sign
	int s2 = area(7)   // Error: missing ; sign
	Int s3 = area(7);  // Error: no existing type Int
	int s4 = area(‘7); // Error: missing second sign (missing ‘ sign)

	// Type errors
	int x0 = arena(7);        // B³¹d: niezadeklarowana funkcja
	int x1 = area(7);         // B³¹d: nieprawid³owa liczba argumentów
	int x2 = area(“seven”, 2); // B³¹d: pierwszy argument ma nieprawid³owy typ
}