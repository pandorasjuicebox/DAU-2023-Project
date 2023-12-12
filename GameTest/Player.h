#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "Card.h"
#include "Deck.h"
#include "Encylopedia.h"

class Player : public GameObject {
public:
	Player(Deck &deck);

private:
	Deck* playerDeck;
	Encyclopedia playerEncyclopedia;

};