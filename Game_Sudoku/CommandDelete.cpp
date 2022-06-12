#include"CommandDelete.h"

CommandDelete::CommandDelete()
{
	type = "DELETE";

}

void CommandDelete::undo()
{
	board->FillCell(pertanyaan[0], pertanyaan[1], pertanyaan[2]);
}

void CommandDelete::redo()
{
	board->DeleteCell(pertanyaan[0], pertanyaan[1]);
}

void CommandDelete::execute(int a, int b)
{
	pertanyaan[0] = a;
	pertanyaan[1] = b;
	pertanyaan[2] = board->getCellVal(a, b);
	board->DeleteCell(pertanyaan[0], pertanyaan[1]);
}