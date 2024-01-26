#include "stdafx.h"
#include "MobUnit.h"

MobUnit::MobUnit(string name, int health, float speed, float xCoord, float yCoord, float scale, CSimpleSprite* sprite)
{
	unitName = name;
	unitHealth = health;
	unitSprite = sprite;
	xPos = xCoord;
	yPos = yCoord;
	unitSpeed = speed;
	unitScale = scale;

	unitSprite->SetPosition(xPos, yPos);
	unitSprite->SetScale(unitScale);
}

CSimpleSprite* MobUnit::GetUnitSprite()
{
	return unitSprite;
}

void MobUnit::Update(float dTime, float playerX, float playerY)
{
}

void MobUnit::SetPlayerLocation(float xCoord, float yCoord)
{
	playerXPos = xCoord;
	playerYPos = yCoord;
}

int MobUnit::getHealth()
{
	return unitHealth;
}

bool MobUnit::isDead()
{
	bool status;
	if (unitHealth == 0) {
		status = true;
	}
	else {
		unitHealth--;
		status = false;
	}
	return status;
}
