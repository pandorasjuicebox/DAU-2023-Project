#pragma once

#include "stdafx.h"
#include "GameObject.h"

class Enemy : public GameObject {
public: 
	Enemy(Deck& Deck);

	void ReceiveCardEffect(int cardStat);
	void 

private:
	Deck* enemyDeck;
	Encyclopedia
};