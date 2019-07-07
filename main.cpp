#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void computerChoice(int choice)
{
	switch (choice)
	{
		case 0: cout << "Computer randomly played rock.\n";
			break;
		case 1: cout << "Computer randomly played paper.\n";
			break;
		case 2: cout << "Computer randomly played scissors.\n";
			break;
	}
}
void score(int WIN, int LOSE)
{
	cout << "User Score: " << WIN << "\nComputer Score: " << LOSE << endl;
}

int userPrompt()
{
	int userInput;
	cout << "----------------------------------------------\n";
	cout << "Player choose (0-rock, 1-paper, or 2-scissors)? ";
	cin >> userInput;

	while (userInput != 0 && userInput != 1 && userInput != 2)
	{
		cout << "ERROR-1A: Must be a number 0-2.\n";
		cout << "Player choose (0-rock, 1-paper, or 2-scissors)? ";
		cin >> userInput;

		if (userInput == 0 || userInput == 1 || userInput == 2)
			break;
	}

	cout << "\n";
	return userInput;
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int userInput = 0;
	int computerInput = 0;
	char repeat;

	int win = 0;
	int lose = 0;

	do
	{
		userPrompt();

		computerInput = rand() % 3;

		if (userInput == computerInput)
		{
			//tie
		}
		else if (userInput == 0 && computerInput == 2 ||
			userInput == 1 && computerInput == 0 ||
			userInput == 2 && computerInput == 1)
		{
			++win;
		}
		else if (userInput == 2 && computerInput == 0 ||
			userInput == 0 && computerInput == 1 ||
			userInput == 1 && computerInput == 2)
		{
			++lose;
		}

		cout << "Verify CompRandNum: " << computerInput << endl;
		computerChoice(computerInput);
		score(win, lose);

		cout << "\nPlay again (Y-yes || N-no)? ";
		cin >> repeat;
		cout << "\n";
		repeat = toupper(repeat);

		while (repeat != 'Y' && repeat != 'N')
		{
			cout << "Invalid input. Must be Y || N only.\n";
			cout << "Play again (Y-yes || N-no)? ";
			cin >> repeat;
			cout << "\n";
			repeat = toupper(repeat);

			if (repeat == 'Y' || repeat == 'N')
				break;

		}

	} while (repeat == 'Y');

	return 0;
}