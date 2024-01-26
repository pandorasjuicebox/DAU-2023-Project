#include "stdafx.h"
#include "MobUnit.h"

MobUnit::MobUnit(string name, int health, float speed, float scale, Coord spawnPoint, CSimpleSprite* sprite)
{
	unitName = name;
	unitHealth = health;
	unitSprite = sprite;
	xPos = spawnPoint.x;
	yPos = spawnPoint.y;
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
	float playerPositionX = playerX;
	float playerPositionY = playerY;
	float acceleration = unitSpeed * dTime;


	if (xPos < playerPositionX) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos + acceleration, yPos + acceleration);
	}
	if (xPos > playerPositionX) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos - acceleration, yPos - acceleration);
	}
	if (yPos < playerPositionY) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos + acceleration, yPos + acceleration);

	}
	if (yPos > playerPositionY) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos - acceleration, yPos - acceleration);
	}

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
