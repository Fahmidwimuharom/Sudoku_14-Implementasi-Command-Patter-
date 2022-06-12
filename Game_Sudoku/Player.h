#pragma once
#include"Header.h"


using namespace std;

class Player
{
protected:
	int score;
	string Username;

public:
	Player();
	~Player() = default;
	void setUsername(string);
	void setScore(int);
	string getUsername();
	int getScore();

};