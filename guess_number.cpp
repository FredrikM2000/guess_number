#include <iostream>
#include <cstdlib>

int main() {
	bool right_guess = false;
	int guess;
	int secret_number = rand() % 30569;
	std::cout << secret_number;
	do {
		std::cout << "Guess a number: ";
		std::cin >> guess;

		if (guess == secret_number) {
			right_guess = true;
		}
	} while (right_guess != true);
	std::cout << "Congratulations, you guessed the right number!";
}
