#include"Board.h"

using namespace std;

Board::Board()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = 0;
		}
	}
}

void Board::generate_num()
{

}

bool Board::checkRegion()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

		}
	}
	return true;
}

bool Board::checkRow()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (k < 8)
				{
					k = 0;
					if (board[i][j] == board[i][k])
					{
						return false;
					}
				}
				else
				{
					if (board[i][j] == board[i][k])
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

bool Board::checkColumn()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (k < 8)
				{
					k = 0;
					if (board[j][i] == board[k][j])
					{
						return false;
					}
				}
				else
				{
					if (board[j][i] == board[k][j])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

void Board::printBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				cout << " ";
			}
			else
			{
				cout << board[i][j];
				cout << " ";
			}

			if ((j + 1) % 3 == 0)
			{
				if (j != 8)
					cout << " | ";
			}
		}
		cout << std::endl;

		if ((i + 1) % 3 == 0)
		{
			cout << "-----------------------" <<endl;
		}
	}
}

void Board::Fill(int x, int y, int value)
{
	board[x][y] = value;
}

void Board::Delete(int x, int y)
{
	board[x][y] = 0;
}