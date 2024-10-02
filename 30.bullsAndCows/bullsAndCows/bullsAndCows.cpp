#include "../../../headers/std_lib_facilities.h"

template<typename T>
bool is_type_int() {
	return typeid(T).name() == typeid(int).name();
}

template<typename T>
vector<T> populte_vector(vector<T> &solution) {
	while (solution.size() != 4) {
		int random = 0;
		if (is_type_int<T>()) {
			random = randint(9);
		}
		else {
			random = randint(97, 122);
		}
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

template<typename T>
vector<T> populate_vector_from_string(vector<T> &choice_vector, string choice) {
	for (int i = 0; i < choice.size(); ++i) {
		if (is_type_int<T>())
			choice_vector.push_back(choice[i] - '0');
		else
			choice_vector.push_back(choice[i]);
	}
	return choice_vector;
}

template<typename T>
bool compare_vectors(vector<T> const& solution, vector<T> const& choice_numbers) {
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

template<typename T>
void game_loop(vector<T> const& solution) {
	string choice;
	int counter = 0;
	while (true) {
		try {
			if(is_type_int<T>())
				cout << "Write 4 numbers from 0 to 9: " << endl;
			else
				cout << "Write 4 letters from a to z: " << endl;
			cin >> choice;
			if (!cin) error("Invalid input.");
			if (choice.size() < 4 || choice.size() > 4) error("Incorrect number of letters. Pass 4.");
			for (int i = 0; i < choice.size(); ++i) {
				if (is_type_int<T>()) {
					if (!isdigit(choice[i])) {
						++counter;
						error("It must be number.");
					}
				}
				else {
					if (isdigit(choice[i])) {
						++counter;
						error("It must be letter.");
					}
				}
				for (int j = 0; j < choice.size(); ++j) {
					if (j == i) continue;
					if (choice[j] == choice[i]) {
						++counter;
						if (is_type_int<T>()) {
							error("numbers must be different.");
						}
						else {
							error("letters must be different.");
						}
					}
				}
			}
			vector<T> choice_vector;
			populate_vector_from_string(choice_vector, choice);
			++counter;
			if (compare_vectors(solution, choice_vector) == true) {
				if (counter == 1) {
					cout << "You win in " << counter << " attempt." << endl;
				}
				else {
					cout << "You win in " << counter << " attempts." << endl;
				}
				break;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

void setup_and_start_game() {
	while (true) {
		try {
			int choice = 0;
			cout << "Do you want play with letters (1) or digits (2)? For exit (9)." << endl;
			cin >> choice;
			int n = 0;
			cout << "Pass randomly choosen number: " << endl;
			cin >> n;
			if (!cin) error("Invalid number.");
			seed_randint(n);
			switch (choice) {
			case 1: {
				vector<char> solution;
				solution = populte_vector(solution);
				game_loop(solution);
				break;
			}
			case 2: {
				vector<int> solution;
				solution = populte_vector(solution);
				game_loop(solution);
				break;
			}
			default:
				break;
			}
			bool again = false;
			cout << "Do you want play again?" << endl;
			cin >> again;
			if (again == false) {
				cout << "Thanks for play, see you next time." << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

int main() {
	try {
		setup_and_start_game();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}