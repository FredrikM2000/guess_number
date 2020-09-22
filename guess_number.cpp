#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int main() {
	bool repeat_game = true;
	int difficulty_input;
	int difficulty{};
	int round = 0;
	bool valid_difficulty = true;
	std::vector <int> highscores = {};

	do {
		std::cout << "Easy(1)\n";
		std::cout << "Medium(2)\n";
		std::cout << "Hard(3)\n";
		std::cout << "Select difficulty: ";
		std::cin >> difficulty_input;
	
		switch (difficulty_input) {
		case(1):
			difficulty = 5;
			valid_difficulty = true;
			break;
		case(2):
			difficulty = 10;
			valid_difficulty = true;
			break;
		case(3):
			difficulty = 30;
			valid_difficulty = true;
			break;
		default:
			valid_difficulty = false;
			std::cout << "\nNot valid, try again\n\n";
			break;
		}
	} while (valid_difficulty == false);

	do {
		bool right_guess = false;
		bool valid_option = true;
		char repeat_input;
		int guess;
		int guess_counter = 0;

		std::srand(static_cast<unsigned int>(std::time(nullptr)));// When you set the limit of the random number to an integer that does not change you get the same sequence of numbers, so to have a different limit every time, I set the limit to the curent time
		int secret_number = rand() % difficulty + 1;

		std::cout << "Guess a number between 1 and " <<  difficulty << ": ";
		
		do {
			std::cin >> guess;
			guess_counter++;
			if (guess == secret_number) {
				right_guess = true;
			} else {
				if (guess <= difficulty && guess >= 1) {//Makes sure the guess is valid
					if (guess < secret_number) {
						std::cout << "Try going higher: ";
						right_guess = false;
					}
					else if (guess > secret_number) {
						std::cout << "Try going lower: ";
						right_guess = false;
					}
				} else {
					std::cout << "Not valid guess, try again";
					right_guess = false;
				}
			}
		} while (right_guess == false);
		std::cout << "\nCongratulations, you guessed the right number!\n";
		std::cout << "You guessed " << guess_counter << " times\n\n";

		highscores.push_back(guess_counter);

		if (round >= 1 && guess_counter < highscores.at(round-1)) {
			std::cout << "Well done, you beat your previous score\n";
		}
		std::sort(highscores.begin(), highscores.end());//sorts the vector from highest to lowest
		std::cout << " _________\n";
		for (int u = 0;u <= round;u++) {
			std::cout << " |" << (u + 1) << ".|  " << highscores.at(u) << "  |\n";//prints the higscores
	}
		std::cout << " _________\n";
		do {
			std::cout << "Would you like to play again?(y/n) ";
			std::cin >> repeat_input;
			if (repeat_input == 'Y' || repeat_input == 'y') {
				repeat_game = true;
				valid_option = true;
				round++;
			}
			else if (repeat_input == 'N' || repeat_input == 'n') {
				repeat_game = false;
				valid_option = true;
				std::cout << "\nWell played!\n";
			}
			else {
				std::cout << "Invaldin option, try again\n";
				valid_option = false;
			}
		} while (valid_option == false);
	} while (repeat_game == true);
}
