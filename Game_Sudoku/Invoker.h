#pragma once
#include"Header.h"
#include"Command.h"
#include"CommandDelete.h"
#include"CommandFill.h"

using namespace std;

class Invoker
{
private:
	vector<Command*> i_Command;

public:
	Invoker();
	~Invoker() = default;
	void push(Command*);
	Command& pop();

	bool isEmpety();
	int getSize();
	
};