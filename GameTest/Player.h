#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "Card.h"
#include "Deck.h"
#include "Encylopedia.h"

class Player : public GameObject {
public:

	//Initialise a new Player
	Player(Deck &deck);

	//Receive a Health Effect that affect the Player (good or bad)
	void ReceiveHealthEffect(int healthPoints);
	//Receive an Effect that impacts the state/status of a Card
	void ReceiveCardEffect(int cardStat);
	//Unlock Article in the Player's Encyclopedia
	void UnlockEncylopediaArticle(int index);

	//Player gets a new card in their deck (if possible)
	bool GetNewCard();  


private:
	Deck* playerDeck;
	Encyclopedia playerEncyclopedia;
	int health = 10;
};