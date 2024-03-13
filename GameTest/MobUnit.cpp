#include "stdafx.h"
#include "GameObject.h"

MobUnit::MobUnit(MobHandler* mbHandler, BackgroundData* backData) 
{
	playerXPos = 0;
	playerYPos = 0;

	mobDirectory = mbHandler;
	bgData = backData;
}

void MobUnit::SetMobUnit(string name, int direction)
{
	Coord spawnPoint = bgData->GetSpawnLocation(direction);

	unitName = name;
	health = mobDirectory->GetMobHealth(name);
	objectSprite = mobDirectory->GetSprite(name);
	xPos = spawnPoint.x;
	yPos = spawnPoint.y;
	speed = mobDirectory->GetMobSpeedList(name);
	scale = mobDirectory->GetMobScale(name);

	objectSprite->SetPosition(xPos, yPos);
	objectSprite->SetScale(scale);

//	hitBox.left = xPos;
//	hitBox.top = yPos;
//	hitBox.right = xPos + objectSprite->GetWidth();
//	hitBox.bottom = yPos + objectSprite->GetHeight();
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

	if (health == 0) {
		objectSprite->SetAnimation(UNIT_DEATH);
	}


	if (xPos < playerPositionX) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos + acceleration, yPos);
		objectSprite->SetAnimation(ANIM_RIGHT); //move right
	}

	if (yPos < playerPositionY) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos, yPos + acceleration);
		objectSprite->SetAnimation(ANIM_FORWARDS); //move forward
	}

	if (xPos > playerPositionX) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos - acceleration, yPos);
		objectSprite->SetAnimation(ANIM_LEFT); //move left

	}

	if (yPos > playerPositionY) {
		objectSprite->GetPosition(xPos, yPos);
		objectSprite->SetPosition(xPos, yPos - acceleration);
		objectSprite->SetAnimation(ANIM_BACKWARDS); //move backward

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

void MobUnit::DeductHealth(int deduction)
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
