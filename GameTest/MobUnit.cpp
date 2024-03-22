#include "stdafx.h"
#include "GameObject.h"

MobUnit::MobUnit(CSimpleSprite* sprite, int healthPoints, float x, float y, float mobScale, float mobSpeed)
{
	
	objectSprite = sprite;
	health = healthPoints;
	xPos = x;
	yPos = y;
	scale = mobScale;
	speed = mobSpeed;

	objectSprite->SetScale(scale);
	objectSprite->SetPosition(xPos, yPos);

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

void MobUnit::AnimateMobUnit(const std::vector<int>& backwards, const std::vector<int>& left, const std::vector<int>& right, const std::vector<int>& forwards)
{
	objectSprite->CreateAnimation(ANIM_BACKWARDS, speed, backwards);
	objectSprite->CreateAnimation(ANIM_LEFT, speed, left);
	objectSprite->CreateAnimation(ANIM_RIGHT, speed, right);
	objectSprite->CreateAnimation(ANIM_FORWARDS, speed, forwards);
}

void MobUnit::AnimateMobDeath(const std::vector<int>& death) {
	objectSprite->CreateAnimation(UNIT_DEATH, speed, death);
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
