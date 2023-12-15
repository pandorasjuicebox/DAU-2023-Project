#pragma once

#include "stdafx.h"
#include "CardElements.h"

class Card {
public:

	Card(int value, Color type);

	void SetNumber(int value);
	void SetColor(Color color);

	int GetValue();
	bool LessThan(int value); //this vs. inputted CardValue
	bool GreaterThan(int value); //this vs. inputted CardValue


private:
	int cardValue;
	Color cardColor;
};