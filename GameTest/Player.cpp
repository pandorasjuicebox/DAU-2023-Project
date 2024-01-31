#include "stdafx.h"
#include "Player.h"

Player::Player(CSimpleSprite* sprite, int xCoord, int yCoord)
{
	playerSpeed = 1.0f / 15.0f;
	playerSprite = sprite;
	playerSprite->CreateAnimation(ANIM_BACKWARDS, playerSpeed, { 0,1,2,3,4,5 });
	playerSprite->CreateAnimation(ANIM_LEFT, playerSpeed, { 6,7,8,9,10,11 });
	playerSprite->CreateAnimation(ANIM_RIGHT, playerSpeed, { 24,25,26,27,28,29 });
	playerSprite->CreateAnimation(ANIM_FORWARDS, playerSpeed, { 30,31,32,33,34,35 });

	//Facing south, walking north
	playerSprite->CreateAnimation(ANIM_ATTACK_SOUTH, playerSpeed, { 36,37,38,39 });
	//Facing east, moving west
	playerSprite->CreateAnimation(ANIM_ATTACK_EAST, playerSpeed, { 42,43,44 });
	//Facing west, moving east
	playerSprite->CreateAnimation(ANIM_ATTACK_WEST, playerSpeed, { 47,46,45 });
	//Facing north, walking south
	playerSprite->CreateAnimation(ANIM_ATTACK_NORTH, playerSpeed, { 48,49,50,51 });

	playerSprite->SetScale(1.5f);
	playerSprite->SetPosition(xCoord, yCoord);

	xPos = xCoord;
	yPos = yCoord;

}

CSimpleSprite* Player::GetPlayerSprite()
{
	return playerSprite;
}

void Player::Update(float dTime)
{
	//dTime = deltaTime

	playerSprite->Update(dTime); //call CSimpleSprite update function

	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_RIGHT);

		playerSprite->GetPosition(xPos, yPos);
		xPos += 1.0f;
		playerSprite->SetPosition(xPos, yPos);

		if (IsKeyPressed(0x46)) {
			//Facing west, moving east
			playerSprite->SetAnimation(ANIM_ATTACK_WEST);
			PlayerAttacking(ANIM_ATTACK_WEST);
		}
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		playerSprite->SetAnimation(ANIM_LEFT);

		playerSprite->GetPosition(xPos, yPos);
		xPos -= 1.0f;
		playerSprite->SetPosition(xPos, yPos);

		if (IsKeyPressed(0x46)) {
			//Facing east, moving west
			playerSprite->SetAnimation(ANIM_ATTACK_EAST);
			PlayerAttacking(ANIM_ATTACK_EAST);
		}
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_BACKWARDS);

		playerSprite->GetPosition(xPos, yPos);
		yPos += 1.0f;
		playerSprite->SetPosition(xPos, yPos);

		if (IsKeyPressed(0x46)) {
			//Facing south, walking north
			playerSprite->SetAnimation(ANIM_ATTACK_SOUTH);
			PlayerAttacking(ANIM_ATTACK_SOUTH);
		}
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		playerSprite->SetAnimation(ANIM_FORWARDS);

		playerSprite->GetPosition(xPos, yPos);
		yPos -= 1.0f;
		playerSprite->SetPosition(xPos, yPos);

		if (IsKeyPressed(0x46)) {
			//Facing north, walking south
			playerSprite->SetAnimation(ANIM_ATTACK_NORTH);
			PlayerAttacking(ANIM_ATTACK_NORTH);
		}
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	{
		playerSprite->SetScale(playerSprite->GetScale() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{
		playerSprite->SetScale(playerSprite->GetScale() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{
		playerSprite->SetAngle(playerSprite->GetAngle() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{
		playerSprite->SetAngle(playerSprite->GetAngle() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		playerSprite->SetAnimation(-1);
	}
}

void Player::ResetPlayerStats()
{
	playerLives = 3;
}

void Player::AddLife()
{
	playerLives++;
}

float Player::GetXPos()
{
	return xPos;
}

float Player::GetYPos()
{
	return yPos;
}

void Player::PlayerAttacking(int dir)
{
	attackDirection = dir;
}

int Player::GetPlayerAttackDirection() {
	return attackDirection;
}




