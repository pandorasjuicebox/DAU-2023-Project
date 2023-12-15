#include "stdafx.h"
#include "Card.h"

Card::Card(int value, Color type)
{
	cardValue = value;
	cardColor = type;
}

void Card::SetNumber(int value)
{
	cardValue = value;
}

void Card::SetColor(Color color)
{
	cardColor = color;
}

int Card::GetValue()
{
	return cardValue;
}

bool Card::LessThan(int value)
{
	bool result = false;
	if (cardValue < value) {
		result = true;
	}
	return result;
}

bool Card::GreaterThan(int value)
{
	bool result = false;
	if (cardValue > value) {
		result = true;
	}
	return result;
}




