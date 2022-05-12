#pragma once
#include<iostream>

class Board
{
protected:
	int board[9][9];

public:
	void generate_num();
	bool checkRegion();
	bool checkRow();
	bool checkColumn();
	void printBoard();
	void Fill(int, int);
	void Delete(int, int);


};