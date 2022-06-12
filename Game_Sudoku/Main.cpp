#include <iostream>
#include "GameManager.h"

int main() 
{
	Board board;
	Player player;
	GameManager game(&board, &player);

	int menu = 10;
	while (menu != 0)
	{
		cout << "\n<<- MainMenu ->>" << endl
			<< "1. Play" << endl
			<< "2. Continue " << endl
			<< "3. Set Player Name" << endl
			<< "4. Exit" << endl
			<< "Input []: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			game.play();
			break;
		case 2:
			game.continueGame();
			break;
		case 3:
			game.setPlayerUsername();
			break;
		case 0:
			break;
		default:;
		}
	}
}
