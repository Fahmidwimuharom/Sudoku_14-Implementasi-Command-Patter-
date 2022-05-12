#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	board = new Board();
	player = new Player();
}

void GameManager::initialize()
{
	board->generate_num();
	board->printBoard();
}

void GameManager::play()
{

}

bool GameManager::quit()
{
	return true;
}

int GameManager::pause()
{
	int jawaban;
	cout << "Jeda...." <<endl;
	cout << "Silahkan Masuk" <<endl;
	cout << "1. Lanjut\n 2. Keluar" <<endl;
	cout << "Jawaban: "; 
	cin >> jawaban;

	return jawaban;
}

void GameManager::Undo()
{

}

void GameManager::Redo()
{

}

void GameManager::setboard(Board* board)
{
	this->board = board;
}

Board* GameManager::getboard()
{
	return board;
}

void GameManager::setplayer(Player* player)
{
	this->player = player;
}

Player* GameManager::getplayer()
{
	return player;
}

bool GameManager::checkwin()
{
	if (board->checkColumn() == true && board->checkRegion() == true && board->checkRow() == true)
	{
		return true;
	}
	return false;
}

void GameManager::fill_Cell(int x, int y, int value)
{
	board->Fill(x, y, value);
}

void GameManager::deleting(int x, int y)
{
	board->Delete(x, y);
}

void GameManager::send_todatabase()
{

}
