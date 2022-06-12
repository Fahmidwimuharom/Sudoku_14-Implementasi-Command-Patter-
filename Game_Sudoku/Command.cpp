#include "Command.h"

Command::Command()
{
	type = "BASE";
}

void Command::setBoard(Board* board)
{
	this->board = board;
}

int Command::getPertanyaan(int val)
{
	return pertanyaan[val];
}

string Command::getType()
{
	return type;
}


