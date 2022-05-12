#pragma once
#include"Command.h"

class CommandDelete :public Command
{
public:
	void setsaveBoard(Board);
	void getsaveBoard();
	void undo(int, int, int);
	void execute(int, int);
};