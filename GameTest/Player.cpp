#include "stdafx.h"
#include "Player.h"

Player::Player(Deck& deck)
{
	this->playerDeck = &deck;
	this->playerEncyclopedia = Encyclopedia();
}

void Player::ReceiveEffect(int points)
{
	this->health = health + points;
}
