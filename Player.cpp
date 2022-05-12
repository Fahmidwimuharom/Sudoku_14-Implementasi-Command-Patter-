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

string Player::getUsername()
{
	return Username;
}

int Player::getScore()
{
	return score;
}