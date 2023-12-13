#pragma once

#include "stdafx.h"
#include "Card.h"
#include <array>
#include <iostream>
using namespace std;

class Deck {
public: 
	Deck();
	int DrawCard();
	void NewCard();

private: 
	array<Card, 4> maxCards;
	//Card maxCards[4];
	//int maxCardsLength = sizeof(maxCards) / sizeof(Card);
	int cardCount = 0; //how many cards out of max 4
};