#include "stdafx.h"
#include "Deck.h"

Deck::Deck()
{
	maxCards.at(cardCount) = Card();
	cardCount++;
}

int Deck::DrawCard()
{
	Card card;
	int value = 0;

	//for (int i = 0; i < cardCount; i++) {
	//	card = maxCards[i];
	//	if (!card.isCardDrawn()) { //if the card is not drawn, draw it.
	//		value = card.GetCardValue();
	//		card.SetDrawn(true);
	//		break;
	//	}
	//}

	for (auto& i : maxCards) {
		if (!i.isCardDrawn()) {
			value = i.GetCardValue();
			i.SetDrawn(true);
			break;
		}
	}
	return value; //if 0, then 
}

void Deck::NewCard()
{
	if (cardCount < 4) {

		maxCards.at(cardCount) = Card();
		cardCount++;
	}
	else {
		cout << "Limit exceeded.";
	}
}

