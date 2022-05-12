#pragma once
#include <iostream>
#include<stack>
#include<vector>
#include"Command.h"
#include"CommandDelete.h"
#include"CommandFill.h"


class Invoker
{
protected:
	std::stack<Command*> i_Command;

public:
	void push(Command*);
	void pop();
	
};