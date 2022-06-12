#pragma once
#include "Board.h"
#include "Header.h"

class Command
{
protected:
	int pertanyaan[3]
	{
	};

	Board* board
	{
	};

	string type = "";

public:
	Command();
	~Command() = default;

	virtual void undo()
	{
	}
	virtual void redo()
	{
	}
	virtual void execute()
	{
	}
	void setBoard(Board*);
	int getPertanyaan(int);

	string getType();

};
