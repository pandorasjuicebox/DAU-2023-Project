#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(BackgroundData* backData, float speed, CSimpleSprite* bullet, string direction)
{
	bgData = backData;
	weaponSpeed = speed;
	spriteDirections[direction] = bullet;

	//Boundary
	rightBorderX = bgData->GetMaxInnerX();
	leftBorderX = bgData->GetMinInnerX();
	upperBorderY = bgData->GetMaxInnerY();
	lowerBorderY = bgData->GetMinInnerY();
}

void Weapon::AddSprite(CSimpleSprite* bullet, string direction)
{
	spriteDirections[direction] = bullet;
}

void Weapon::FireWeapon(float xOrigin, float yOrigin, float xDest, float yDest, string direction)
{
	xPos = xOrigin;
	yPos = yOrigin;
	inAction = true;

	if (xOrigin > xDest) {
		weaponSpeedX = weaponSpeedX * -1;
	}

	if (yOrigin > yDest) {
		weaponSpeedY = weaponSpeedY * -1;
	}

	spriteDirections[direction]->SetPosition(xPos, yPos);
}

void Weapon::Update(float dTime, string direction)
{
	spriteDirections[direction]->GetPosition(xPos, yPos);
	spriteDirections[direction]->SetPosition(xPos + weaponSpeedX * dTime, yPos + weaponSpeedY * dTime);
	spriteDirections[direction]->Update(dTime);

	if (xPos < leftBorderX || xPos > rightBorderX || yPos < lowerBorderY || yPos > upperBorderY) {
		inAction = false; 
	}
}

bool Weapon::isActive()
{
	return inAction;
}

void Weapon::Collided()
{
	inAction = false;
}

CSimpleSprite* Weapon::GetWeaponSprite(string name)
{
	return spriteDirections[name];
}

Coord Weapon::GetPosition()
{
	Coord pos = { xPos,yPos };
	return Coord();
}
