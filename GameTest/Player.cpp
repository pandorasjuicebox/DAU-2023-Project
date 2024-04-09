#include "stdafx.h"
#include "GameObject.h"

Player::Player(CSimpleSprite* sprite, int xCoord, int yCoord, BackgroundData* backData)
{
	speed = 1.0f / 15.0f;
	objectSprite = sprite;
	objectSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5 });
	objectSprite->CreateAnimation(ANIM_LEFT, speed, { 6,7,8,9,10,11 });
	objectSprite->CreateAnimation(ANIM_RIGHT, speed, { 24,25,26,27,28,29 });
	objectSprite->CreateAnimation(ANIM_FORWARDS, speed, { 30,31,32,33,34,35 });

	//Facing south, walking north
	objectSprite->CreateAnimation(ANIM_ATTACK_SOUTH, speed, { 36,37,38,39 });
	//Facing east, moving west
	objectSprite->CreateAnimation(ANIM_ATTACK_EAST, speed, { 42,43,44 });
	//Facing west, moving east
	objectSprite->CreateAnimation(ANIM_ATTACK_WEST, speed, { 47,46,45 });
	//Facing north, walking south
	objectSprite->CreateAnimation(ANIM_ATTACK_NORTH, speed, { 48,49,50,51 });
	
	//Death
	objectSprite->CreateAnimation(UNIT_DEATH, 10, {54,55,56});

	objectSprite->SetScale(1.5f);
	objectSprite->SetPosition(xCoord, yCoord);

	SetGoing(GOING_EAST);

	xPos = xCoord;
	yPos = yCoord;

	health = PLAYER_FULL_HEALTH;

}


void Player::Update(float dTime)
{
	//dTime = deltaTime

	objectSprite->Update(dTime); //call CSimpleSprite update function

	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		SetGoing(GOING_EAST);
		objectSprite->SetAnimation(ANIM_RIGHT);
		objectSprite->GetPosition(xPos, yPos);

		if (!CheckBoundaries(xPos, yPos)) {
			xPos += 1.0f;
		}
		if (CheckBoundaries(xPos, yPos)) {
			xPos -= 2.0f;
		}

		objectSprite->SetPosition(xPos, yPos);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		SetGoing(GOING_WEST);
		objectSprite->SetAnimation(ANIM_LEFT);

		objectSprite->GetPosition(xPos, yPos);

		if (!CheckBoundaries(xPos, yPos)) {
			xPos -= 1.0f;
		}
		if (CheckBoundaries(xPos, yPos)) {
			xPos += 2.0f;
		}

		objectSprite->SetPosition(xPos, yPos);
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		SetGoing(GOING_NORTH);
		objectSprite->SetAnimation(ANIM_BACKWARDS);
		objectSprite->GetPosition(xPos, yPos);

		if (!CheckBoundaries(xPos, yPos)) {
			yPos += 1.0f;
		}
		if (CheckBoundaries(xPos, yPos)) {
			yPos -= 2.0f;
		}

		objectSprite->SetPosition(xPos, yPos);
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		SetGoing(GOING_SOUTH);
		objectSprite->SetAnimation(ANIM_FORWARDS);
		objectSprite->GetPosition(xPos, yPos);

		if (!CheckBoundaries(xPos, yPos)) {
			yPos -= 1.0f;
		}
		if (CheckBoundaries(xPos, yPos)) {
			yPos += 2.0f;
		}
		
		objectSprite->SetPosition(xPos, yPos);

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	{
		objectSprite->SetScale(objectSprite->GetScale() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{
		objectSprite->SetScale(objectSprite->GetScale() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{
		objectSprite->SetAngle(objectSprite->GetAngle() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{
		objectSprite->SetAngle(objectSprite->GetAngle() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		objectSprite->SetAnimation(-1);
	}

	objectSprite->GetPosition(xPos, yPos);
	objectSprite->SetPosition(xPos, yPos);

}


void Player::SetGoing(int direction)
{
	if (direction == GOING_NORTH) {
		facing = GOING_NORTH;
	}
	else if (direction == GOING_SOUTH) {
		facing = GOING_SOUTH;
	}
	else if (direction == GOING_WEST) {
		facing = GOING_WEST;
	}
	else if (direction == GOING_EAST) {
		facing = GOING_EAST;
	}
}


int Player::GetGoingDirection()
{
	return facing;
}

void Player::AddPlayerAreaCoord(float x, float y)
{
	Coord coordinates = { x,y };
	playerArea.push_back(coordinates);
}

void Player::CreateBorders()
{
	minXBorder = bgData->MinXValue(playerArea);
	minYBorder = bgData->MinYValue(playerArea);
	maxXBorder = bgData->MaxXValue(playerArea);
	maxYBorder = bgData->MaxYValue(playerArea);
}

bool Player::CheckBoundaries(float x, float y)
{

	//north
	if (y > maxYBorder) {
		return true;
	}
	//south
	else if (y < minYBorder) {
		return true;
	}
	//west
	else if (x < minXBorder) {
		return true;
	}
	//east
	else if (x > maxXBorder) {
		return true;
	}
	return false;
}

bool Player::intersects(GameObject* object)
{

	object->RefreshPosition();
	RefreshPosition();

	float yValue = 0;
	float xValue = 0;
	float xPosWithOffset = xPos + 8;
	float yPosWithOffset = yPos - 10;


	yValue = object->GetYPos();
	xValue = object->GetXPos();

	double calculation = 0;


	calculation = sqrt(abs(pow(xPosWithOffset - xValue, 2)) + abs(pow((yPosWithOffset - yValue), 2)));

	if (calculation < 20) {
		return true;

	}

	return false;
}



	






