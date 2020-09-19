#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
	bool repeat_game = true;
	std::vector <int> highscores;
	int i = 0;
do {
	bool right_guess = false;
	bool valid_option = true;
	char repeat;
	int guess;
	int guess_counter = 0;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int secret_number = rand()%10 + 1;

	std::cout << secret_number;
	
	
		std::cout << "Guess a number between 1 and 10: ";
		do {
			std::cin >> guess;
			guess_counter++;
			if (guess == secret_number) {
				right_guess = true;
			}
			else {
				if (guess < secret_number) {
					std::cout << "Guess counter: " << guess_counter << "\n";
					std::cout << "Try going higher: ";
					right_guess = false;
				}
				else if (guess > secret_number) {
					std::cout << "Guess counter: " << guess_counter << "\n";
					std::cout << "Try going lower: ";
					right_guess = false;
				}
			}
		} while (right_guess != true);
		std::cout << "Congratulations, you guessed the right number!\n";
		std::cout << "You guessed " << guess_counter << " times\n\n";

		highscores.push_back(guess_counter);
		i++;

		do {
			std::cout << "Would you like to play again?(y/n) ";
			std::cin >> repeat;
			if (repeat == 'Y' || repeat == 'y') {
				repeat_game = true;
				valid_option = true;
			}
			else if (repeat == 'N' || repeat == 'n') {
				repeat_game = false;
				valid_option = true;
			}
			else {
				std::cout << "Invaldin option, try again";
				valid_option = false;
			}
		} while (valid_option == false);
	} while (repeat_game == true);
	//std::cout << highscores[0] << highscores[1];



	for (int u = 0;u <= highscores.size()-1 || u <= 5;u++) {
		std::cout << "|" << u+ 1 << "|  " << highscores[u] << "  |\n";
	}


	//std::cout << "|1|  " << highscores[0] << "  |\n";
	//std::cout << "|2|  " << highscores[1] << "  |\n";
	//std::cout << "|3|  " << highscores[2] << "  |\n";
	//std::cout << "|4|  " << highscores[3] << "  |\n";
	//std::cout << "|5|  " << highscores[4] << "  |\n";

}
