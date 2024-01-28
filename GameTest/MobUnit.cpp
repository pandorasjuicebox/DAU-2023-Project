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
		unitSprite->SetAnimation(ANIM_RIGHT);
	}
	if (xPos > playerPositionX) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos - acceleration, yPos);
		unitSprite->SetAnimation(ANIM_LEFT);
	}
	if (yPos < playerPositionY) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos, yPos + acceleration);
		unitSprite->SetAnimation(ANIM_FORWARDS);
	}
	if (yPos > playerPositionY) {
		unitSprite->GetPosition(xPos, yPos);
		unitSprite->SetPosition(xPos, yPos - acceleration);
		unitSprite->SetAnimation(ANIM_BACKWARDS);
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
