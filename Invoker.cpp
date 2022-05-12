#include"Invoker.h"

void Invoker::pop()
{
	i_Command.pop();
}

void Invoker::push(Command* command)
{
	i_Command.push(command);
}