#pragma once
#include "CommandFill.h"

CommandFill::CommandFill()
{
	type = "FILL";
}

void CommandFill::undo()
{
	board->DeleteCell(pertanyaan[0], pertanyaan[1]);
}

void CommandFill::redo()
{
	board->FillCell(pertanyaan[0], pertanyaan[1], pertanyaan[2]);
}

void CommandFill::execute(int x, int y, int value)
{
	pertanyaan[0] = x;
	pertanyaan[1] = y;
	pertanyaan[2] = value;
	board->FillCell(pertanyaan[0], pertanyaan[1], pertanyaan[2]);
}