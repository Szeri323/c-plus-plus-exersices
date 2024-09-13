#include "../../../headers/std_lib_facilities.h"

int char_to_digit(int c) {
	switch (c) {
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
	default:
		error("Input is not a digit.");
	}
}

vector<int> populte_vector() {
	vector<int> digits{ 0,1,2,3,4,5,6,7,8,9 };
	vector<int> solution;
	for (int i = 0; i < 4; ++i) {
		solution.push_back(i);
	}
	return solution;
}
vector<int> create_vector_from_string(string choice) {
	vector<int> choice_numbers;
	for (int i = 0; i < choice.size(); ++i) {
		choice_numbers.push_back(char_to_digit(int{ choice[i] }));
	}
	return choice_numbers;
}

bool compare_vectors(vector<int> solution, vector<int> choice_numbers) {
	int bulls = 0;
	int cows;
	for (int i = 0; i < solution.size(); ++i) {
		if (solution[i] == choice_numbers[i]) {
			cout << "bull" << endl;
			bulls += 1;
		}
		else {
			/*temp = choice_numbers[i];*/
			for (int j = 0; j < solution.size(); ++j) {
				if (j == i) {
					continue;
				}
				if (choice_numbers[i] == solution[j]) {
					cout << "cow" << endl;
				}
			}
		}
		if (bulls == 4) {
			return true;
		}
	}
}

int main() {
	vector<int> solution = populte_vector();
	string choice;
	while (true) {
		try {
			cout << "Write 4 numbers from 0 to 9: " << endl;
			cin >> choice;
			if (choice.size() < 4 || choice.size() > 4) error("Incorrect number of numbers. Pass 4.");
				vector<int> choice_numbers = create_vector_from_string(choice);
			for (int x : solution)
				cout << x << " ";
			cout << endl;
			for (int x : choice_numbers)
				cout << x << " ";
			cout << endl;
			if (compare_vectors(solution, choice_numbers) == true) {
				cout << "You win." << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}