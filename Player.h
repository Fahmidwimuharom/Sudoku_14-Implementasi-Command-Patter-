#pragma once
#include<iostream>

class Player
{
protected:
	int score;
	std::string Username;

public:
	Player();
	void setUsername(std::string);
	std::string getUsername();
	void setScore(int);
	int getScore();


};