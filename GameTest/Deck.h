#pragma once

#include "stdafx.h"
#include "Card.h"
#include <array>
#include <iostream>
using namespace std;

class Deck {
public: 
	Deck(); //initialise a new Deck

	//Draw a Card, and get the amount
	int DrawCard();

	//Add a new a new Card to the player Deck 
	bool NewCard();
	
	//Set the status of the Card(s)
	// 0 - default or normal
	// 1 - Disabled (for this fight)
	// 2 - Disabled, but can be enabled at a health cost
	void SetCardStatus(int cardStatus);
	void SetMultipleCardStatus(int cardStatus, int numCards);
	
	//Enable all cards from being disabled via CardStatus
	void ResetDeck();

private: 
	array<Card, 4> maxCards;
	//Card maxCards[4];
	//int maxCardsLength = sizeof(maxCards) / sizeof(Card);
	int cardCount = 0; //how many cards out of max 4
};