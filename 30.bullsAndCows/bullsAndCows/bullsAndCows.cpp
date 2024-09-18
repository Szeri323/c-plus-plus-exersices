#include "../../../headers/std_lib_facilities.h"

// Bull and Cows numbers

int char_to_digit(char c) {
	/*switch (c) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		error("Input is not a digit.");
	}*/
	return c - '0';
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
		choice_numbers.push_back(char_to_digit(choice[i]));
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

// Bull and Cows letters

vector<char> populte_vector_char() {
	vector<char> solution;
	while (solution.size() != 4) {
		int random = randint(97, 122);
		bool flag = false;
		if (solution.size() == 0) {
			solution.push_back(char(random));
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

vector<char> create_vector_char_from_string(string choice) {
	vector<char> choice_letters;
	for (int i = 0; i < choice.size(); ++i) {
		choice_letters.push_back(choice[i]);
	}
	return choice_letters;
}

bool compare_vectors_char(vector<char> solution, vector<char> choice_numbers) {
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
	int choice;
	cout << "Do you want play with letters (1) or digits (2)?" << endl;
	cin >> choice;
	if (choice == 1) {
		while (true) {
			int n = 0;
			cout << "Pass randomly choosen number: " << endl;
			cin >> n;
			seed_randint(n);
			vector<char> solution = populte_vector_char();
			string choice;
			int counter = 0;
			bool again = false;
			while (true) {
				try {
					cout << "Write 4 letter from a to z: " << endl;
					cin >> choice;
					if (choice.size() < 4 || choice.size() > 4) error("Incorrect number of letters. Pass 4.");
					for (int i = 0; i < choice.size(); ++i) {
						for (int j = 0; j < choice.size(); ++j) {
							if (j == i) continue;
							if (choice[j] == choice[i]) error("letters must be different.");
						}
					}
					vector<char> choice_numbers = create_vector_char_from_string(choice);
					++counter;
					if (compare_vectors_char(solution, choice_numbers) == true) {
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
	else if (choice == 2) {
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
					for (int i = 0; i < choice.size(); ++i) {
						for (int j = 0; j < choice.size(); ++j) {
							if (j == i) continue;
							if (choice[j] == choice[i]) error("Numbers must be different.");
						}
					}
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
}