#pragma once
#include "Header.h"

#define UKURAN 9

using namespace std;

class Board
{
private:
	bool InRegion(int, int, int);
	bool InCol(int, int);

	vector <bool> getRegionposs(int, int);
	vector <bool> getColposs(int);
	vector <bool> getRowposs(int);

	void copySol();
	void setCellSolved(int, int, int);
	void checkRegion(int, int);
	int checkCellSolv();

	int solution[UKURAN][UKURAN];
	int grid[UKURAN][UKURAN];
	vector <bool> possibles[UKURAN][UKURAN];

	int solutionChanges;
	int CellsRemove = 50;

public:
	Board();
	~Board() = default;

	bool solve();
	bool SolRight();

	int getCellSolVal(int, int);
	int getCellVal(int, int);

	void Difficulty(int);
	void Generate();
	void draw();
	void drawSolution();
	void setCell(int, int, int);
	void setSolCell(int, int, int);
	void FillCell(int, int, int);
	void DeleteCell(int, int);
	


};