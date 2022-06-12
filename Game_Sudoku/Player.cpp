#include"Player.h"

using namespace std;

Player::Player()
{
	Username = " ";
	score = 0;
}

void Player::setUsername(string Username)
{
	this->Username = Username;
}

void Player::setScore(int score)
{
	this->score = score;
}

string Player::getUsername()
{
	return Username;
}

int Player::getScore()
{
	return score;
}