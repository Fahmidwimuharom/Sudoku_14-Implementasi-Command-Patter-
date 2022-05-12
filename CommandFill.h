#pragma once
#include"Command.h"
#include "Board.h"

class CommandFill :public Command
{
public:
	void setsaveBoard(Board);
	Board getsaveBoard();
	void undo(int, int);
	void execute(int, int, int);
};