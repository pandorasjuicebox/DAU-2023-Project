#pragma once

#include "stdafx.h"
#include "Card.h"
#include "CardElements.h"
#include <algorithm>
#include <random>
using namespace std;

#define CARD_SIZE 84

class Deck {
public:
	//Deck();
	void CreateFullDeck(); //create a full deck with all the cards, not shuffled
	bool AddCard(Card card);
	void ShuffleCards();
	Card Draw();

	

private:
	array<Card, CARD_SIZE>deckOfCards;
	int cardAmount = 0;
};