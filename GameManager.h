#pragma once
#include<string.h>
#include"Board.h"
#include"Command.h"
#include"CommandDelete.h"
#include"CommandFill.h"
#include"Invoker.h"
#include"Player.h"

class GameManager
{
protected:
	Board* board;
	Player* player;
	Invoker redo;
	Invoker undo;

public:
	GameManager();
	void initialize();
	void play();
	bool quit();
	int pause();
	void Undo();
	void Redo();
	void setboard(Board*);
	Board* getboard();
	void setplayer(Player*);
	Player* getplayer();
	bool checkwin();
	void fill_Cell(int, int, int);
	void deleting(int, int);
	void send_todatabase();
};
