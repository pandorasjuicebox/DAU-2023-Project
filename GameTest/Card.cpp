#include "stdafx.h"
#include "Card.h"


Card::Card()
{
	cardValue = GetCardValue(true); //assigned random number
	cardStatus = 0; //normal status
}

void Card::SetCardValue(int value)
{
	cardValue = value;
}


void Card::SetCardStatus(int statNumber)
{
	// 0 - default or normal
	// 1 - Disabled (for this fight)
	// 2 - Disabled, but can be enabled at a health cost
	cardStatus = statNumber;
}

void Card::SetDrawn(bool state)
{
	isDrawn = state;
}

int Card::GetCardStatus()
{
	return cardStatus;
}

int Card::GetCardValue()
{
	return cardValue;
}

int Card::GetCardValue(bool isRandom)
{
	int value = 0;

	//if random is OK and card status is 0 (DEFAULT) or 2 (DISABLED BUT UNLOCKABLE)
	//change the values to something random
	if ((isRandom && cardStatus == 0) || (isRandom && cardStatus == 2)){ 
		value = rand() % valueSetSize + 1; //change the value
		cardValue = value;
	}
	else { //don't change the value; for error catching
		value = cardValue; 
	}
	return value;
}

bool Card::isCardDrawn()
{
	return this->isDrawn;
}




