#include"CommandFill.h"

void CommandFill::setsaveBoard(Board saveBoard)
{
	this->saveBoard = saveBoard;
}

Board CommandFill::getsaveBoard()
{
	return saveBoard;
}

void CommandFill::undo(int x, int y)
{
	saveBoard.Delete(x, y);
	}

void CommandFill::execute(int x, int y, int value)
{
	saveBoard.Fill(x, y, value);
}