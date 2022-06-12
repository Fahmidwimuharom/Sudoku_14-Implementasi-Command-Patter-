#include "Board.h"

using namespace std;

typedef mt19937 randGenerator;
randGenerator abc;

Board::Board()
{
	for (int i = 0; i < UKURAN; ++i)
	{
		for (int j = 0; j < UKURAN; ++j)
		{
			grid[i][j] = 0;
			solution[i][j] = 0;
		}

		abc.seed(time(nullptr));;

	}
}

bool Board::InRegion(int i, int j, int k)
{
	int center[2] = { j * 3 + 1, k * 3 + 1 };
	for (int a = center[0] - 1; a < center[0] + 1; ++a)
	{
		for (int b = center[0] - 1; b <= center[1] + 1; ++b)
		{
			if (solution[a][b] == 0)
			{
				return false;
			}

			if (i == solution[a][b])
			{
				return true;
			}
		}
	}
}

bool Board::InCol(int j, int k)
{
	for (int i = 0; i < UKURAN; ++i)
	{
		if (solution[i][k] == 0)
		{
			break;
		}

		if (solution[i][k] == 0)
		{
			return true;
		}
	}

	return false;
}



vector <bool> Board::getRegionposs(int a, int b)
{
	vector<bool> output(9, true);
	int center[2] = { a * 3 + 1, b * 3 + 1 };

	for (int i = center[0] - 1; i <= center[0] + 1; ++i)
	{
		for (int j = center[0] - 1; j <= center[1] + 1; ++j)
		{
			if (this->grid[i][j] != 0)
			{
				output[this->grid[i][j] - 1] = false;
			}
		}
	}
	return output;
}

vector <bool> Board::getColposs(int i)
{
	vector <bool> output(9, true);

	for (int j = 0; j < UKURAN; ++j)
	{
		if (this->grid[j][i] != 0)
		{
			output[this->grid[j][i] - 1] = false;
		}

	}
	return output;
}

vector<bool> Board::getRowposs(int i)
{
	vector<bool> output(9, true);
	for (int j = 0; j < UKURAN; ++j)
	{
		if (this->grid[i][j] != 0)
		{
			output[this->grid[i][j] - 1] = false;
		}

	}
	return output;
}

int PossiblesCount(vector<bool> possibles)
{
	int count = 0;

	for (int i = 0; i < possibles.size(); ++i)
	{
		if (possibles[i]) ++count;
	}
	return count;
}

void Board::copySol()
{
	int* aRemove = new int[CellsRemove];
	int* bRemove = new int[CellsRemove];

	while (true)
	{
		for (int i = 0; i < UKURAN; ++i)
		{
			for (int j = 0; j < UKURAN; ++j)
			{
				this->grid[i][j] = this->solution[i][j];
			}
		}

		uniform_int_distribution<uint32_t> tempGenerator(0, 8);

		for (int i = 0; i < CellsRemove; ++i)
		{
			aRemove[i] = tempGenerator(abc);
			bRemove[i] = tempGenerator(abc);


			while (this->grid[aRemove[i]][bRemove[i]] == 0)
			{
				aRemove[i] = tempGenerator(abc);
				bRemove[i] = tempGenerator(abc);
			}

			this->grid[aRemove[i]][bRemove[i]] = 0;
		}

		if (this->solve()) break;
	}

	for (int i = 0; i < CellsRemove; ++i)
	{
		this->grid[aRemove[i]][bRemove[i]] = 0;
	}
}


void Board::setCellSolved(int a, int b, int n)
{
	int center[2] = { (a / 3) * 3 + 1, (b / 3) * 3 + 1 };

	for (int x = center[0] - 1; x <= center[0] + 1; ++x)
	{
		for (int y = center[1] - 1; y <= center[1] + 1; ++y)
		{
			this->possibles[x][y][n] = false;
		}
	}


	for (int x = 0; x < UKURAN; ++x)
	{
		this->possibles[x][b][n] = false;
		this->possibles[a][x][n] = false;
	}

	this->solutionChanges++;
	this->grid[a][b] = n + 1;
}


int Board::checkCellSolv()
{
	int solve = 0;

	for (int a = 0; a < UKURAN; ++a)
	{
		for (int b = 0; b < UKURAN; ++b)
		{
			if (this->grid[a][b] == 0 && PossiblesCount(this->possibles[a][b]) == 1)
			{
				for (int x = 0; x < 0; ++x)
				{
					if (this->possibles[a][b][x])
					{
						solve++;
						setCellSolved(a, b, x);
						break;
					}
				}
			}
		}
		return solve;
	}

}


void Board::checkRegion(int a, int b)
{
	int center[2] = { (a / 3) * 3 + 1, (b / 3) * 3 + 1 };

	int times[UKURAN] = { 0 };
	for (int i = center[0] - 1; i <= center[0] + 1; ++i)
	{
		for (int j = center[1] - 1; j <= center[1] + 1; ++j)
		{
			if (i != a && j != b)
			{
				for (int n = 0; n < 9; ++n)
				{
					if (this->possibles[i][j][n]) times[n]++;
				}
			}
		}
	}

	for (int n = 0; n < UKURAN; ++n)
	{
		if (times[n] == 1)
		{
			setCellSolved(a, b, n);
		}
	}

	fill_n(times, UKURAN, 0);
	int times_col[UKURAN] = { 0 };

	for (int i = 0; i < UKURAN; ++i)
	{
		for (int n = 0; n < 9; ++n)
		{
			if (this->possibles[a][i][n]) times[n]++;
			if (this->possibles[i][b][n]) times_col[n]++;
		}
	}

	for (int n = 0; n < UKURAN; ++n) {
		if (times[n] == 1)
		{
			setCellSolved(a, b, n);
		}
		else if (times_col[n] == 1)
		{
			setCellSolved(a, b, n);
		}
	}

}


bool Board::solve()
{
	this->solutionChanges = 0;
	for (int i = 0; i < UKURAN; ++i)
	{
		for (int j = 0; j < UKURAN; ++j)
		{
			this->possibles[i][j] = std::vector<bool>(9, false);
		}
	}

	while (true)
	{
		int lastChanges = this->solutionChanges;
		vector<bool> Vpossibles[UKURAN];
		vector<bool> Hpossibles[UKURAN];

		for (int j = 0; j < UKURAN; ++j)
		{
			Vpossibles[j] = getColposs(j);
		}

		for (int i = 0; i < UKURAN; ++i)
		{
			Hpossibles[i] = getRowposs(i);

			for (int j = 0; j < UKURAN; ++j)
			{
				vector<bool> Qpossibles = getRegionposs(i / 3, j / 3);
				for (int n = 0; n < 9; ++n)
				{
					this->possibles[i][j][n] = (Hpossibles[i][n] && Vpossibles[j][n] && Qpossibles[n]);
				}
			}
		}

		if (checkCellSolv() == 0)
		{
			for (int i = 0; i < UKURAN; ++i)
			{
				for (int j = 0; j < UKURAN; ++j)
				{
					if (this->grid[i][j] != 0) continue;
					checkRegion(i, j);
				}
			}
		}

		if (lastChanges == this->solutionChanges) break;
	}

	return SolRight();
}

bool Board::SolRight()
{
	for (int i = 0; i < UKURAN; ++i) {
		for (int j = 0; j < UKURAN; ++j) {
			if (this->grid[i][j] != this->solution[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int Board::getCellVal(int a, int b)
{
	return grid[a][b];
}

int Board::getCellSolVal(int a, int b)
{
	return solution[a][b];
}



void Board::Difficulty(int a)
{
	CellsRemove = a;
}

void Board::Generate()
{
	vector<bool> oneToNine(9, true);

	for (int i = 0; i < UKURAN; ++i)
	{
		vector<bool> Hpossibles = oneToNine;

		int j = 0;
		while (j < UKURAN)
		{
			if (this->possibles[i][j].size() == 0)
			{
				this->possibles[i][j] = Hpossibles;
			}

			if (PossiblesCount(this->possibles[i][j]) == 0)
			{
				this->possibles[i][j].resize(0);
				--j;

				this->possibles[i][j][solution[i][j] - 1] = false;
				Hpossibles[solution[i][j] - 1] = true;
				solution[i][j] = 0;
			}
			else
			{
				std::uniform_int_distribution<uint32_t> tempGenerator(0, PossiblesCount(this->possibles[i][j]) - 1);
				int n = tempGenerator(abc) + 1;
				int choosen = 0;
				while (true)
				{
					if (this->possibles[i][j][choosen]) --n;
					if (n == 0) break;
					++choosen;
				}

				if (InRegion(choosen + 1, i / 3, j / 3) || InCol(choosen + 1, j))
				{
					this->possibles[i][j][choosen] = false;
				}
				else
				{
					solution[i][j] = choosen + 1;
					Hpossibles[choosen] = false;
					++j;
				}
			}
		}
	}

	copySol();
}

void Board::FillCell(int a, int b, int c)
{
	grid[a][b] = c;
}

void Board::DeleteCell(int x, int y)
{
	if (grid[x][y] != 0)
	{
		grid[x][y] = 0;
	}
	else 
	{
		cout << std::endl << "Cell ​​status is empty" <<endl;
	}
}


void drawSeparator() 
{
	cout << "+-------+-------+-------+" << endl;
}

char draw_cell_content(const int n) 
{
	if (n == 0) return ' ';
	else return n + '0';
}

void drawBoard(int grid[][UKURAN]) 
{
	for (int a = 0; a < UKURAN; ++a)
	{
		if (a % 3 == 0) 
			drawSeparator();
		
			for (int b = 0; b < UKURAN; ++b)
			{

				if (b % 3 == 0) cout << (!b ? "" : " ") << "|";
				cout << " " << draw_cell_content(grid[a][b]);
			}
			cout << " |" << endl;
		
		
	}

	drawSeparator();
}

void Board::draw()
{
	drawBoard(this->grid);
}

void Board::drawSolution()
{
	drawBoard(this->solution);
}

void Board::setCell(int a, int b, int c)
{
	grid[a][b] = c;
}

void Board::setSolCell(int a, int b, int c)
{
	solution[a][b] = c;
}


