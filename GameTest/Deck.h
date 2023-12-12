#pragma once

#include "stdafx.h"
#include "Card.h"


class Deck {
public: 
	Deck();
	int DrawCard();
	void NewCard();

private: 
	Card maxCards[4];
	int maxCardsLength = sizeof(maxCards) / sizeof(Card);
	int cardCount = 0; //how many cards out of max 4
};