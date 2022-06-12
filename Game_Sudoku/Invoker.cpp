#include "Invoker.h"

using namespace std;

Invoker::Invoker()
{
	i_Command.clear();
}

void Invoker::push(Command* command)
{
	i_Command.push_back(command);
}

Command& Invoker::pop()
{
	if (i_Command.empty())
	{
		cout << endl << "Your chance to Undo/Redo is over"<< endl;
	}

	else
	{
		Command* temp = move(i_Command.back());
		CommandFill* a;

		i_Command.pop_back();

		return *temp;
	}
}

bool Invoker::isEmpety()
{
	return i_Command.empty();
}

int Invoker::getSize()
{
	return i_Command.size();
}