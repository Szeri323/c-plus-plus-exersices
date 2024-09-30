#include "../../../headers/std_lib_facilities.h"

vector<int> setup_game() {
	vector<int> computer_choices{ 1,3,2,3,2,1,2,3,1,2,3 };
	vector<int> other;
	int temp = 0;
	int additional_rounds = 0;
	cout << "Pass adional rounds number: " << endl;
	cin >> additional_rounds;
	cout << "Pass " << additional_rounds << " random numbers from 1 to 3: " << endl;
	for (int i = 0; i < additional_rounds; ++i) {
		cin >> temp;
		if (temp > 0 && temp < 4)
			other.push_back(temp);
		else {
			error("Invalid number.");
		}
	}
	for (int i = 0; i < other.size(); i += 2) {
		if (i < computer_choices.size() - 1) {
			computer_choices[i] = other[i];
		}
		else {
			computer_choices.push_back(other[i]);
		}
	}
	return computer_choices;
}

vector<int> game(const vector<int> &computer_choices) {
	int choice = 0;
	int player_score = 0;
	int computer_score = 0;
	
	for (int x : computer_choices)
		cout << x << endl;
	cout << "Rock = 1, Paper = 2, Scissors = 3: " << endl;
	for (int i = 0; i < computer_choices.size(); ++i) {
		cin >> choice;
		cout << computer_choices[i] << " " << choice << endl;
		switch (choice) {
		case 1:
			if (computer_choices[i] == 1) {
				cout << "Draw!" << endl;
			}
			else if (computer_choices[i] == 2) {
				cout << "Computer wins!" << endl;
				++computer_score;
			}
			else {
				cout << "Player wins!" << endl;
				++player_score;
			}
			break;
		case 2:
			if (computer_choices[i] == 1) {
				cout << "Player wins!" << endl;
				++player_score;
			}
			else if (computer_choices[i] == 2) {
				cout << "Draw!" << endl;
			}
			else {
				cout << "Computer wins!" << endl;
				++computer_score;
			}
			break;
		case 3:
			if (computer_choices[i] == 1) {
				cout << "Computer wins!" << endl;
				++computer_score;
			}
			else if (computer_choices[i] == 2) {
				cout << "Player wins!" << endl;
				++player_score;
			}
			else {
				cout << "Draw!" << endl;
			}
			break;
		}		
	}
	return vector<int> {player_score, computer_score};
}

void print_results(const vector<int>& results) {
	cout << "Player: " << results[0] << endl
		<< "Computer: " << results[1] << endl;
	if (results[0] > results[1]) cout << "Player won!" << endl;
	else if (results[0] < results[1]) cout << "Computer won!" << endl;
	else cout << "It's a draw!" << endl;
}

int main() {
	try {
		vector<int> computer_choices = setup_game();
		vector<int> results = game(computer_choices);
		print_results(results);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}