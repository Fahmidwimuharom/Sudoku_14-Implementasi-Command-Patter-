#pragma once
#include"Command.h"

class CommandDelete :public Command
{
public:
	void setsaveBoard(Board);
	void getsaveboard();
	void undo(int, int, int);
	void execute(int, int);
};
