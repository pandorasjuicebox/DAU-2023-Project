#pragma once

#include "GameObject.h"
#include "stdafx.h"
#include "App/app.h"
#include "stdlib.h"

class Card : public GameObject {
public: 
	Card();
	void SetCardValue(int value); //manual card override
	void SetCardStatus(int statNumber); //manual status override
	void SetDrawn(bool state);

	int GetCardStatus();

	//Overloaded Methods
	int GetCardValue(); //get the cardValue
	int GetCardValue(bool isRandom); //get the cardValue that is now randomised if isRandom is true
	
	bool isCardDrawn();

private:
	int cardValue = 1; //default
	int possibleValues[4] = { 1,2,3,4 };
	int valueSetSize = sizeof(possibleValues) / sizeof(int);
	int cardStatus = 0; //0 is default or normal
	bool isDrawn = false;
};