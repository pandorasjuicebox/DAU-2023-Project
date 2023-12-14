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

bool Deck::NewCard()
{
	bool result = false;
	if (cardCount < 4) {
		maxCards.at(cardCount) = Card();
		cardCount++;
		result = true;
	}
	else {
		//TODO: comment out later
		cout << "Limit exceeded.";
	}
	return result;
}

void Deck::SetCardStatus(int cardStatus) 
{
	for (auto& i : maxCards) {
	
		if (i.isCardDrawn() && i.GetCardValue() == 0) {
			i.SetCardStatus(cardStatus); 
			
		}
		//Disabled but can be enabled at a health cost
		else if (i.isCardDrawn() && cardStatus == 2) {
			i.SetCardStatus(cardStatus); //since cardStat 2 can still be enabled during the fight
		}
		
	}
}

void Deck::SetMultipleCardStatus(int cardStatus, int numCards)
{
	int cardsAffected = numCards;
	int counter = 0;

	for (auto& i : maxCards) {
		if (counter < numCards) {
			//Disabled for the fight
			if (i.isCardDrawn() && cardStatus == 1) {
				i.SetCardStatus(1);
				counter++;
			}
			//Disabled but can be enabled at a health cost
			else if (i.isCardDrawn() && cardStatus == 2) {
				i.SetCardStatus(2);
				counter++;
			}
		}
	}
}

void Deck::ResetDeck()
{
	for (auto& i : maxCards) {
		if (i.isCardDrawn()) {
			i.SetCardStatus(0); //enable all cards again
		}
	}
}



