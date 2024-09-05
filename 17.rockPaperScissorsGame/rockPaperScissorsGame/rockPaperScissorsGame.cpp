#include "../../../headers/std_lib_facilities.h"

int main() {
	vector<int> computer_choices{ 1,3,2,3,2,1,2,3,1,2,3 };
	vector<int> other;
	int choice = 0;
	int current = 0;
	int computer = 0;
	int player = 0;
	int additional_rounds = 0;
	int temp = 0;
	cout << "Pass adional rounds number: " << endl;
	cin >> additional_rounds;
	cout << "Pass " << additional_rounds << " random numbers from 1 to 3: " << endl;
	for (int i = 0; i < additional_rounds; ++i) {
		cin >> temp;
		if (temp > 0 && temp < 4)
			other.push_back(temp);
		else {
			cout << "Not a valid number." << endl;
			return 0;
		}
	}
	for (int i = 0; i < other.size(); i+=2) {
		if (i < computer_choices.size()-1) {
			computer_choices[i] = other[i];
		}
		else {
			computer_choices.push_back(other[i]);
		}
	}
	for (int x: computer_choices)
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
				++computer;
			}
			else {
				cout << "Player wins!" << endl;
				++player;
			}
			break;
		case 2:
			if (computer_choices[i] == 1) {
				cout << "Player wins!" << endl;
				++player;
			}
			else if (computer_choices[i] == 2) {
				cout << "Draw!" << endl;
			}
			else {
				cout << "Computer wins!" << endl;
				++computer;
			}
			break;
		case 3:
			if (computer_choices[i] == 1) {
				cout << "Computer wins!" << endl;
				++computer;
			}
			else if (computer_choices[i] == 2) {
				cout << "Player wins!" << endl;
				++player;
			}
			else {
				cout << "Draw!" << endl;
			}
			break;
		}
		cout << "Player: " << player << endl
			<< "Computer: " << computer << endl;
		
	}
}