#include "stdafx.h"
#include "Player.h"

Player::Player(Deck& deck)
{
	this->playerDeck = &deck;
	this->playerEncyclopedia = Encyclopedia();
}

void Player::ReceiveHealthEffect(int healthPoints)
{
	this->health = health + healthPoints;
}

void Player::ReceiveCardEffect(int cardStat)
{
	this->playerDeck->SetCardStatus(cardStat);
}

bool Player::GetNewCard()
{
	return this->playerDeck->NewCard();
}

void Player::UnlockEncylopediaArticle(int index)
{
	this->playerEncyclopedia.UnlockArticle(index);
}



