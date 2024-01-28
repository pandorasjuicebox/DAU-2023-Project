#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(BackgroundData* backData, float speed)
{
	bgData = backData;
	weaponSpeed = speed;

	//Boundary
	rightBorderX = bgData->GetMaxInnerX();
	leftBorderX = bgData->GetMinInnerX();
	upperBorderY = bgData->GetMaxInnerY();
	lowerBorderY = bgData->GetMinInnerY();


}

void Weapon::FireWeapon(float xOrigin, float yOrigin, float xDest, float yDest)
{
}

void Weapon::Update(float dTime)
{
}

Coord Weapon::GetPosition()
{
	Coord pos = { xPos,yPos };
	return Coord();
}
