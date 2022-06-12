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
			<< "2. Exit" << endl
			<< "Input []: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			game.setPlayerUsername();
			game.play();
			break;
		case 0:
			break;
		default:;
		}
	}
}
