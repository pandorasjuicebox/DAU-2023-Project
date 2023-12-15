#include "stdafx.h"
#include "Tile.h"

Tile::Tile(int type, float xPos, float yPos, bool passable, bool exit)
{
	tileType = type;
	location.x = xPos;
	location.y = yPos;
	isPassable = passable; 
	isExitPoint = exit;
}

void Tile::SetPosition(float xPos, float yPos)
{
	location.x = xPos;
	location.y = yPos;
}

int Tile::GetType()
{
	return tileType;
}

float Tile::GetXPos()
{
	return location.x;
}

float Tile::GetYPos() {
	return location.y;
}

bool Tile::IsPassable() {
	return isPassable;
}

bool Tile::IsExitPoint() {
	return isExitPoint;
}
