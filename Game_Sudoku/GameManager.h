#pragma once
#include"Header.h"
#include "Player.h"
#include"Invoker.h"

class GameManager
{
private:
	Board* board;
	Player* player;
	Invoker redo;
	Invoker undo;

public:
	GameManager(Board*, Player*);
	void CheckWrongCell();
	void play();
	void UndoAct();
	void RedoAct();
	void continueGame();
	void setPlayerUsername();
	void fillCell(int, int, int);
	void deleteCell(int, int);
};