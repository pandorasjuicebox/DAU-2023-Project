#include "stdafx.h"
#include "GameObject.h"

Player::Player(CSimpleSprite* sprite, int xCoord, int yCoord)
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
	objectSprite->CreateAnimation(UNIT_DEATH, speed, {54,55,56});

	objectSprite->SetScale(1.5f);
	objectSprite->SetPosition(xCoord, yCoord);

	xPos = xCoord;
	yPos = yCoord;

	SetGoing(GOING_EAST);

}

void Player::Update(float dTime)
{
	//dTime = deltaTime

	objectSprite->Update(dTime); //call CSimpleSprite update function

	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		SetGoing(GOING_EAST);
		objectSprite->SetAnimation(ANIM_RIGHT);
		//movingDirection = ANIM_RIGHT;
		objectSprite->GetPosition(xPos, yPos);
		xPos += 1.0f;
		objectSprite->SetPosition(xPos, yPos);

		//if (IsKeyPressed(0x46)) {
		//	//Facing west, moving east
		//	playerSprite->SetAnimation(ANIM_ATTACK_WEST);
		//	PlayerAttacking(ANIM_ATTACK_WEST);
		//}
		//PlayerAttacking(NO_ATTACK);
		//playerSprite->SetAnimation(ANIM_RIGHT);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		SetGoing(GOING_WEST);
		objectSprite->SetAnimation(ANIM_LEFT);
		//movingDirection = ANIM_LEFT;
		objectSprite->GetPosition(xPos, yPos);
		xPos -= 1.0f;
		objectSprite->SetPosition(xPos, yPos);

		//if (IsKeyPressed(0x46)) {
		//	//Facing east, moving west
		//	playerSprite->SetAnimation(ANIM_ATTACK_EAST);
		//	PlayerAttacking(ANIM_ATTACK_EAST);
		//}
		////PlayerAttacking(NO_ATTACK);
		//playerSprite->SetAnimation(ANIM_LEFT);
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		SetGoing(GOING_NORTH);
		objectSprite->SetAnimation(ANIM_BACKWARDS);
		//movingDirection = ANIM_BACKWARDS;
		objectSprite->GetPosition(xPos, yPos);
		yPos += 1.0f;
		objectSprite->SetPosition(xPos, yPos);

		//if (IsKeyPressed(0x46)) {
		//	//Facing south, walking north
		//	playerSprite->SetAnimation(ANIM_ATTACK_SOUTH);
		//	PlayerAttacking(ANIM_ATTACK_SOUTH);
		//}
		////PlayerAttacking(NO_ATTACK);
		//playerSprite->SetAnimation(ANIM_BACKWARDS);
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		SetGoing(GOING_SOUTH);
		objectSprite->SetAnimation(ANIM_FORWARDS);
		//movingDirection = ANIM_FORWARDS;
		objectSprite->GetPosition(xPos, yPos);
		yPos -= 1.0f;
		objectSprite->SetPosition(xPos, yPos);

		//if (IsKeyPressed(0x46)) {
		//	//Facing north, walking south
		//	playerSprite->SetAnimation(ANIM_ATTACK_NORTH);
		//	PlayerAttacking(ANIM_ATTACK_NORTH);
		//}
		////PlayerAttacking(NO_ATTACK);
		//playerSprite->SetAnimation(ANIM_FORWARDS);
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

}

//void Player::ResetPlayerStats()
//{
//	playerLives = 3;
//}
//
//void Player::AddLife()
//{
//	playerLives++;
//}
//
//void Player::RemoveLife()
//{
//	playerLives--;
//
//	if (playerLives == 0) {
//		playerSprite->SetAnimation(UNIT_DEATH);
//	}
//}
//
//int Player::GetLives()
//{
//	return playerLives;
//}

float Player::GetXPos()
{
	return xPos;
}

float Player::GetYPos()
{
	return yPos;
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

	






