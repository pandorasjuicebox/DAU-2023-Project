#include "stdafx.h"
#include "MobUnit.h"

MobUnit::MobUnit(MobHandler* mbHandler, BackgroundData* backData) 
{
	playerXPos = 0;
	playerYPos = 0;

	mobDirectory = mbHandler;
	bgData = backData;
}

void MobUnit::AddMobUnit(string name)
{
	Coord spawnPoint = bgData->GetSpawnLocation();

	unitName = name;
	unitHealth = mobDirectory->GetMobHealth(name);
	unitSprite = mobDirectory->GetSprite(name);
	xPos = spawnPoint.x;
	yPos = spawnPoint.y;
	unitSpeed = mobDirectory->GetMobSpeedList(name);
	unitScale = mobDirectory->GetMobScale(name);

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
	unitSprite->Update(dTime);


	if (xPos < playerPositionX) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos + acceleration, yPos);
		unitSprite->SetAnimation(ANIM_RIGHT); //move right

		if (unitHealth == 0) {
			unitSprite->SetAnimation(UNIT_DEATH);
			lifeStatus = false;
		}
		else if ((playerPositionX - xPos <= 1) && IsKeyPressed(0x46)) {
				unitHealth--;
		}
	}

	if (yPos < playerPositionY) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos, yPos + acceleration);
		unitSprite->SetAnimation(ANIM_FORWARDS); //move forward

		if (unitHealth == 0) {
			unitSprite->SetAnimation(UNIT_DEATH);
			lifeStatus = false;
		}
		else if ((playerPositionY - yPos <= 1) && IsKeyPressed(0x46)) {
			unitHealth--;
		}
	}

	if (xPos > playerPositionX) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos - acceleration, yPos);
		unitSprite->SetAnimation(ANIM_LEFT); //move left

		if (unitHealth == 0) {
			unitSprite->SetAnimation(UNIT_DEATH);
			lifeStatus = false;
		}
		else if ((xPos - playerPositionX <= 1)  && IsKeyPressed(0x46)) {
				unitHealth--;
		}
	}

	if (yPos > playerPositionY) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos, yPos - acceleration);
		unitSprite->SetAnimation(ANIM_BACKWARDS); //move backward
		
		if (unitHealth == 0) {
			unitSprite->SetAnimation(UNIT_DEATH);
			lifeStatus = false;
		}
		else if ((yPos - playerPositionY <= 10) &&  IsKeyPressed(0x46)) {
			unitHealth--;
		}
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
	if (unitHealth == 0) {
		lifeStatus = true;
	}
	return lifeStatus;
}
