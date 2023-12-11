#pragma once

#include "GameObject.h"
#include "Card.h"
#include "Deck.h"

class Player : public GameObject {
public:
	Player(Deck &deck);

private:
	Deck* playerDeck;
};