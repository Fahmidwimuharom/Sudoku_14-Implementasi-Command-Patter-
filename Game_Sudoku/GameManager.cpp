#include "GameManager.h"

using namespace std;

GameManager::GameManager(Board* board, Player* player)
{
	this->board = board;
	this->player = player;
}

void GameManager::CheckWrongCell()
{
	struct WrongCell
	{
		int a;
		int b;
		int value;
	};

	vector <WrongCell> Cell;

	for (int i = 0; i < UKURAN; ++i) 
	{
		for (int j = 0; j < UKURAN; ++j)
		{
			if (this->board->getCellVal(i, j) != this->board->getCellSolVal(i, j)) 
			{
				Cell.push_back({ i, j, this->board->getCellVal(i,j) });
			}
		}
	}

	cout << endl << "Every Cell is correct, Except :  " << endl;
	for (const auto& arr : Cell)
	{
		cout << "Cell "	<< "[" << arr.a << "]" << "[" << arr.b << "] : ";
		if (arr.value == 0)
		{
			cout << "Empty";
		}
		else 
		{
			cout << arr.value;
		}
		cout << endl;
		Cell.pop_back();
	}
}

void GameManager::setPlayerUsername()
{
	string username;
	cout << endl << "Input Username: "; 
	cin >> username;

	player->setUsername(username);
}


void GameManager::play()
{
	cout << endl << "How many cells do you want to delete/remove? Let's set the difficulty : ";
	int r = 0; cin >> r;
	this->board->Difficulty(r);
	board->Generate();
	continueGame();
}

void GameManager::UndoAct()
{
	Command* copy;
	copy = &undo.pop();
	cout << copy->getType();
	redo.push(copy);
	copy->undo();

	cout << "Undo on ["	<< copy->getPertanyaan(0) << "][" << copy->getPertanyaan(1) << "]" << endl;
}

void GameManager::RedoAct()
{
	Command* copy;
	copy = &redo.pop();
	undo.push(copy);
	copy->redo();
	cout << "Redo on [" << copy->getPertanyaan(0) << "][" << copy->getPertanyaan(1) << "]" << endl;
}

void GameManager::fillCell(int x, int y, int value)
{
	CommandFill* copy = new CommandFill;
	copy->setBoard(board);
	if (board->getCellVal(x, y) != 0)
	{
		cout << endl << "Cell already has value!" << endl;
	}
	else
	{
		copy->execute(x, y, value);
	}
	undo.push(copy);
}

void GameManager::deleteCell(int x, int y)
{
	CommandDelete* copy = new CommandDelete;
	copy->setBoard(board);
	undo.push(copy);
	copy->execute(x, y);
}

void GameManager::continueGame()
{
	int userMenu = 10;
	int x, y, z;
	while (userMenu != 0)
	{
		if (this->board->SolRight())
		{
			cout << endl << "Congratulations!!" << endl << "you have finished the sudoku with " << (undo.getSize() + redo.getSize())
				<< " action!" << endl << endl;
			break;
		}
		board->draw();
		cout << endl
			<< " Choice List" << endl
			<< "[1] Fill" << endl
			<< "[2] Delete " << endl
			<< "[3] Undo " << endl
			<< "[4] Redo " << endl
			<< "[5] Check Wrong Cell" << endl
			<< "[0] Exit" << endl
			<< "Input [] : ";
		cin >> userMenu;

		switch (userMenu)
		{
		case 1:
			cout << "X     :";
			cin >> x;
			cout << "Y     :";
			cin >> y;
			cout << "Value :";
			cin >> z;

			fillCell(x, y, z);
			break;
		case 2:
			cout << "X     :";
			cin >> x;
			cout << "Y     :";
			cin >> y;

			deleteCell(x, y);
			break;
		case 3:
			UndoAct();
			break;
		
		case 4:
			RedoAct();
			break;;
			
		case 5:
			CheckWrongCell();
		default:;
		}
	}
}


