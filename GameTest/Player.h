#pragma once

#include "GameObject.h"
#include "Card.h"

class Player : public GameObject {
public:
	//Player(const char* fileName, unsigned int nColumns, unsigned int nRows);

private:
	Card skillList[4];
};