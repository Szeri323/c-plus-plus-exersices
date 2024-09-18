#include "../../../headers/std_lib_facilities.h"

class Token {
public:
	string word;
	Token(string w) :word(w) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	Token buffer;
	bool full;
};

Token_stream::Token_stream() : buffer("none"), full(false) {};

void Token_stream::putback(Token t) {
	if (full) error("Calling putback(), when buffer is full.");
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	string word;
	cin >> word;
	if (word == "the" || word == "birds" || word == "fish" || word == "c++" ||
		word == "rules" || word == "fly" || word == "swim" ||
		word == "and" || word == "or" || word == "but" || word == "/") {
		return Token(word);
	}
	else {
		error("No word in collection.");
	}
}

Token_stream ts;

string sentence();

//string conjunction();

string verb();

string noun();

string article();

int main() {
	string sen = "";
	while (cin) {
		try {
			Token t = ts.get();

			ts.putback(t);

			sen = sentence();
			cout << "sentence: " << sen << endl;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	//val = sentence()
}

string sentence() {
	string sen = "";
	sen += article();
	sen += " " + noun();
	sen += " " + verb();
	Token t = ts.get();

	if (t.word == "and" || t.word == "or" || t.word == "but") {
		sen += " " + t.word + " " + sentence();
		return sen;
	}
	else if (t.word == "/") {
		return sen;
	}
	else {
		error("Invalid construction of sentence, needed conjunction.");
	}
}

string verb() {
	Token t = ts.get();
	if (t.word == "rules" || t.word == "fly" || t.word == "swim") {
		return t.word;
	}
	else {
		error("The word is not verb.");
	}
}

string noun() {
	Token t = ts.get();

	if (t.word == "birds" || t.word == "fish" || t.word == "c++") {
		return t.word;
	}
	else {
		error("The word is not noun.");
	}
}

string article() {
	Token t = ts.get();

	if (t.word == "the") {
		return t.word;
	}
	else {
		error("The word is not article.");
	}
}
