#include "stdafx.h"
#include "Card.h"


Card::Card()
{
	cardStatus = 0; //normal status
	cardValue = GetRandomCardValue();
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
	this->isActive = true;
}

int Card::GetCardStatus()
{
	return cardStatus;
}

int Card::GetCardValue()
{
	return cardValue;
}

int Card::GetRandomCardValue()
{
	int value = 0;

	//if random is OK and card status is 0 (DEFAULT) or 2 (DISABLED BUT UNLOCKABLE)
	//change the values to something random
	if ((cardStatus == 0) || (cardStatus == 2)){ 
		value = rand() % possibleValues.size() + 1; //change the value
		cardValue = value;
	}
	return value;
}

bool Card::isCardDrawn()
{
	return this->isDrawn;
}




