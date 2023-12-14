#pragma once


#include "stdafx.h"
#include <array>
#include "GameObject.h"
#include "App/app.h"
#include "stdlib.h"
using namespace std;

class Card : public GameObject {
public: 
	Card();

	//Set Card value with the inputted value
	void SetCardValue(int value); 
	
	//Set the status of the card
	// 0 - default or normal
	// 1 - Disabled (for this fight)
	// 2 - Disabled, but can be enabled at a health cost
	void SetCardStatus(int statNumber); 

	//Set if a Card is drawn/active
	void SetDrawn(bool state);

	//Get the status of the card
	// 0 - default or normal
	// 1 - Disabled (for this fight)
	// 2 - Disabled, but can be enabled at a health cost
	int GetCardStatus();

	//get the cardValue
	int GetCardValue(); 
	//get the cardValue that is now randomised
	int GetRandomCardValue(); 
	
	//Is the card drawn?
	bool isCardDrawn();

private:
	int cardValue = 1; //default
	array<int, 4> possibleValues = { 1,2,3,4 };
	//int possibleValues[4] = { 1,2,3,4 };
	//int valueSetSize = sizeof(possibleValues) / sizeof(int);

	int cardStatus = 0; //0 is default or normal
	bool isDrawn = false;
};