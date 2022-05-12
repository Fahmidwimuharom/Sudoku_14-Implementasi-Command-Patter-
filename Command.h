#pragma once
#include "Board.h"

class Command
{
protected:
	Board saveBoard;

public:
	virtual void setsaveBoard() = 0;
	virtual void getsaveBoard() = 0;
	virtual void undo() = 0;
	virtual void execute() = 0;

};
