#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "Card.h"
#include "Deck.h"
#include "Encylopedia.h"

class Player : public GameObject {
public:
	Player(Deck &deck);
	void ReceiveEffect(int points);


private:
	Deck* playerDeck;
	Encyclopedia playerEncyclopedia;
	int health = 10;
};