#include "../../../headers/std_lib_facilities.h"

int main() {
	vector<string> disliked{ "nie", "lubie", "plackow"};
	vector<string> words;
	string temp;
	while (cin >> temp) {
		words.push_back(temp);
	}
	sort(words.begin(), words.end());
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < disliked.size(); ++j) {
			if (words[i] == disliked[j])
				words[i] = "Biip";
			
		}
		cout << words[i] << "\n";

	}
	
}