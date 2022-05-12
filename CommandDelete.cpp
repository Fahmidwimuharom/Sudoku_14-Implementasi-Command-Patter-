#include"CommandDelete.h"

void CommandDelete::setsaveBoard(Board saveBoard)
{
	this->saveBoard = saveBoard;
}

Board CommandDelete::getsaveBoard()
{
	return saveBoard;
}

void CommandDelete::undo(int x, int y, int value)
{
	saveBoard.Fill(x, y, value);
}

void CommandDelete::execute(int x, int y)
{
	saveBoard.Delete(x, y);
}