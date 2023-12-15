#include "stdafx.h"
#include "Deck.h"


//Deck::Deck()
//{
//	//cardAmount = CARD_SIZE;
//}

void Deck::CreateFullDeck()
{
	//108 cards, 12 sets of cards 1-9
	//4 sets of color 1
	//4 sets of color 2
	//4 sets of color 3
	int counter = 1;
	int typeCounter = 0;
	Color colors[4] = { RED, GREEN, YELLOW, GREY };
	for (auto& i : deckOfCards) {
		if (counter <= 7) {
			i.SetNumber(counter);
			i.SetColor(colors[typeCounter]);
			cardAmount++;
			if (counter == 7) {
				counter = 0;
				typeCounter++;
			}
			counter++;
		}
	}
}

bool Deck::AddCard(Card card)
{
	bool result = false;
	if (cardAmount < deckOfCards.max_size()) {
		deckOfCards.at(cardAmount) = card;
		result = true;
	}
	return result;
}

void Deck::ShuffleCards()
{
	shuffle(deckOfCards.begin(), deckOfCards.end(),default_random_engine());
}

Card Deck::Draw()
{
	Card drawnCard = deckOfCards.at(cardAmount);
	cardAmount--;
	return drawnCard;
}
