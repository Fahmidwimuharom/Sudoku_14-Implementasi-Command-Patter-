#pragma once
#include<iostream>

using namespace std;

class Player
{
protected:
	int score;
	string Username;

public:
	Player();
	void setUsername(string);
	string getUsername();
	int getScore();


};