#include "stdafx.h"
#include "Player.h"

Player::Player(const char* fileName, unsigned int nColumns, unsigned int nRows)
{
	objectSprite = CSimpleSprite(fileName, nColumns, nRows);
}
