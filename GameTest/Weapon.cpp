#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(BackgroundData* backData, float speed, CSimpleSprite* bullet)
{
	bgData = backData;
	weaponSpeed = speed;
	weaponSprite = bullet;

	//Boundary
	rightBorderX = bgData->GetMaxInnerX();
	leftBorderX = bgData->GetMinInnerX();
	upperBorderY = bgData->GetMaxInnerY();
	lowerBorderY = bgData->GetMinInnerY();
	weaponSprite->SetScale(2.0);
}

void Weapon::FireWeapon(float xStart, float yStart, float xDest, float yDest)
{

	//inAction = true;
	xPos = xStart;
	yPos = yStart;


	float gradient = (xStart - xDest) / (yStart - yDest);


	// Position the bullet ready to be drawn
	weaponSprite->SetPosition(xPos, yPos);
	

}

void Weapon::Update(float dTime)
{
	// Update the bullet position variables


	if (xPos < leftBorderX || xPos > rightBorderX ||
		yPos < upperBorderY || yPos > lowerBorderY)
	{
		inAction = false;
	}
}

bool Weapon::isActive()
{
	return inAction;
}

void Weapon::Stop() {
	inAction = false;
}


CSimpleSprite* Weapon::GetWeaponSprite()
{
	return weaponSprite;
}

void Weapon::GetPosition(float x, float y)
{
	xPos = x;
	yPos = y;
	weaponSprite->SetPosition(xPos, yPos);
}

float Weapon::GetXPos()
{
	return xPos;
}

float Weapon::GetYPos()
{
	return yPos;
}
