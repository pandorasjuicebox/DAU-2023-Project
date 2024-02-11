#include "stdafx.h"
#include "GameObject.h"

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
	health = mobDirectory->GetMobHealth(name);
	objectSprite = mobDirectory->GetSprite(name);
	xPos = spawnPoint.x;
	yPos = spawnPoint.y;
	speed = mobDirectory->GetMobSpeedList(name);
	scale = mobDirectory->GetMobScale(name);

	objectSprite->SetPosition(xPos, yPos);
	objectSprite->SetScale(scale);
}

CSimpleSprite* MobUnit::GetUnitSprite()
{
	return objectSprite;
}

void MobUnit::Update(float dTime, float playerX, float playerY)
{
	float playerPositionX = playerX;
	float playerPositionY = playerY;
	float acceleration = speed * dTime;
	objectSprite->Update(dTime);


	if (xPos < playerPositionX) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos + acceleration, yPos);
		objectSprite->SetAnimation(ANIM_RIGHT); //move right

		if (health == 0) {
			objectSprite->SetAnimation(UNIT_DEATH);
			deadStatus = false;
		}
		//else if ((playerPositionX - xPos <= 1) && IsKeyPressed(0x46)) {
		//		unitHealth--;
		//}
	}

	if (yPos < playerPositionY) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos, yPos + acceleration);
		objectSprite->SetAnimation(ANIM_FORWARDS); //move forward

		//if (unitHealth == 0) {
		//	unitSprite->SetAnimation(UNIT_DEATH);
		//	lifeStatus = false;
		//}
		//else if ((playerPositionY - yPos <= 1) && IsKeyPressed(0x46)) {
		//	unitHealth--;
		//}
	}

	if (xPos > playerPositionX) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos - acceleration, yPos);
		objectSprite->SetAnimation(ANIM_LEFT); //move left

		//if (unitHealth == 0) {
		//	unitSprite->SetAnimation(UNIT_DEATH);
		//	lifeStatus = false;
		//}
		//else if ((xPos - playerPositionX <= 1)  && IsKeyPressed(0x46)) {
		//		unitHealth--;
		//}
	}

	if (yPos > playerPositionY) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos, yPos - acceleration);
		objectSprite->SetAnimation(ANIM_BACKWARDS); //move backward
		
		//if (unitHealth == 0) {
		//	unitSprite->SetAnimation(UNIT_DEATH);
		//	lifeStatus = false;
		//}
		//else if ((yPos - playerPositionY <= 10) &&  IsKeyPressed(0x46)) {
		//	unitHealth--;
		//}
	}

}

void MobUnit::SetPlayerLocation(float xCoord, float yCoord)
{
	playerXPos = xCoord;
	playerYPos = yCoord;
}

int MobUnit::GetHealth()
{
	return health;
}

int MobUnit::GetType()
{
	return MOB_UNIT;
}

void MobUnit::SetHealth(int deduction)
{
	health = health - deduction;
}

bool MobUnit::isDead()
{
	if (health <= 0) {
		deadStatus = true;
	}
	return deadStatus;
}
