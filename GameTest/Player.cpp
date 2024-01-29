#include "stdafx.h"
#include "Player.h"

Player::Player(CSimpleSprite* sprite, int xCoord, int yCoord)
{
	playerSpeed = 1.0f / 15.0f;
	playerSprite = sprite;
	playerSprite->CreateAnimation(ANIM_BACKWARDS, playerSpeed, { 0,1,2,3,4,5 });
	playerSprite->CreateAnimation(ANIM_LEFT, playerSpeed, { 24,25,26,27,28,29 });
	playerSprite->CreateAnimation(ANIM_RIGHT, playerSpeed, { 6,7,8,9,10,11 });
	playerSprite->CreateAnimation(ANIM_FORWARDS, playerSpeed, { 30,31,32,33,34,35 });
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
		//float x, y;
		playerSprite->GetPosition(xPos, yPos);
		xPos += 1.0f;
		playerSprite->SetPosition(xPos, yPos);
		playerFacing = ANIM_RIGHT;
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		playerSprite->SetAnimation(ANIM_LEFT);
		//float x, y;
		playerSprite->GetPosition(xPos, yPos);
		xPos -= 1.0f;
		playerSprite->SetPosition(xPos, yPos);
		playerFacing = ANIM_LEFT;
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_FORWARDS);
		//float x, y;
		playerSprite->GetPosition(xPos, yPos);
		yPos += 1.0f;
		playerSprite->SetPosition(xPos, yPos);
		playerFacing = ANIM_FORWARDS;
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		playerSprite->SetAnimation(ANIM_BACKWARDS);
		//float x, y;
		playerSprite->GetPosition(xPos, yPos);
		yPos -= 1.0f;
		playerSprite->SetPosition(xPos, yPos);
		playerFacing = ANIM_BACKWARDS;
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

int Player::GetPlayerFacing()
{
	return playerFacing;
}




