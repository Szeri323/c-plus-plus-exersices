// Main shold be outside of the struct
// void f in struct X is infinite loop

struct X {
	void f(int x) { // member function that is infinite loop
		struct Y {
			int f() { return 1; } 
			int m;
		};
		int m;
		m = x; 
		Y m2;
		return f(m2.f());
	}
	int m; 
	void g(int m) { // member function that use uninitialized property and call f which is infinite loop
		if (m) f(m + 2); 
		else {
			g(m + 2);
		}
	}
	X(){} // this is probably constructor 
	void m3() {} // empty member function
	void main() { // this should be outside the struct
		X a; 
		a.f(2);
	}
};