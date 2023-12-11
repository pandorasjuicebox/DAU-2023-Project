#include "stdafx.h"
#include "Deck.h"
#include <iostream>

Deck::Deck()
{
	maxCards[cardCount] = Card();
	cardCount++;
}

int Deck::DrawCard()
{
	Card card;
	int value = 0;

	for (int i = 0; i < cardCount; i++) {
		card = maxCards[i];
		if (!card.isCardDrawn()) { //if the card is not drawn, draw it.
			value = card.GetCardValue();
			card.SetDrawn(true);
			break;
		}
	}
	return value; //if 0, then 
}

void Deck::NewCard()
{
	if (cardCount < maxCardsLength) {
		maxCards[cardCount] = Card();
		cardCount++;
	}
	else {
		std::cout << "Limit exceeded.";
	}
}

