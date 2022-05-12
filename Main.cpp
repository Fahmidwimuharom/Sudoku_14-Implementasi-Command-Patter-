#include "Board.h"

int main()
{
	Board* board = new Board();

	board->printBoard();
	if (board->checkColumn() == true && board->checkRegion() == true && board->checkRow() == true)
	{
		std::cout << "MENANG" << std::endl;
	}
	else
	{
		std::cout << "KALAH" << std::endl;
	}

	return 0;
}