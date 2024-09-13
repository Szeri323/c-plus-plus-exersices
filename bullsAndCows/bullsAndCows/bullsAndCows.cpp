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
	vector<int> solution;
	while (solution.size() != 4) {
		int random = randint(9);
		bool flag = false;
		if (solution.size() == 0) {
			solution.push_back(random);
		}
		for (int j = 0; j < solution.size(); ++j) {
			if (random == solution[j]) 
				flag = true;
		}
		if (flag == false)
			solution.push_back(random);
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
	int cows = 0;
	for (int i = 0; i < solution.size(); ++i) {
		if (solution[i] == choice_numbers[i]) {
			bulls += 1;
		}
		else {
			for (int j = 0; j < solution.size(); ++j) {
				if (j == i) {
					continue;
				}
				if (choice_numbers[i] == solution[j]) {
					cows += 1;
				}
			}
		}
		if (bulls == 4) {
			return true;
		}
	}
	cout << "Bulls: " << bulls << " " << "Cows: " << cows << endl;
}

int main() {
	while (true) {
		int n = 0;
		cout << "Pass randomly choosen number: " << endl;
		cin >> n;
		seed_randint(n);
		vector<int> solution = populte_vector();
		string choice;
		int counter = 0;
		bool again = false;
		while (true) {
			try {
				cout << "Write 4 numbers from 0 to 9: " << endl;
				cin >> choice;
				if (choice.size() < 4 || choice.size() > 4) error("Incorrect number of numbers. Pass 4.");
				vector<int> choice_numbers = create_vector_from_string(choice);
				++counter;
				if (compare_vectors(solution, choice_numbers) == true) {
					if (counter == 1) {
						cout << "You win in " << counter << " attempt." << endl;
					}
					else {
						cout << "You win in " << counter << " attempts." << endl;
					}
					cout << "Do you want play again?" << endl;
					cin >> again;
					break;

				}
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
		}
		if (again == false) {
			cout << "Thanks for play, see you next time." << endl;
			break;
		}
	}
}