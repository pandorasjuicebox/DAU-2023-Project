#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include "BackgroundData.h"
using namespace std;
using namespace App;

class Weapon
{
public:
	Weapon(BackgroundData* backData, float speed, CSimpleSprite* bullet, string direction);
	void AddSprite(CSimpleSprite* bullet, string direction);
	void FireWeapon(float xOrigin, float yOrigin, float xDest, float yDest, string direction);
	void Update(float dTime, string direction);
	bool isActive();
	void Collided();

	CSimpleSprite* GetWeaponSprite(string name);

	Coord GetPosition();

private:

	BackgroundData* bgData; 
	map < string, CSimpleSprite* > spriteDirections;

	float xPos = 0;
	float yPos = 0;
	float weaponSpeed = 0;
	float weaponSpeedX = 0;
	float weaponSpeedY = 0;
	bool inAction = false;


	float rightBorderX = 0; 
	float leftBorderX = 0;
	float upperBorderY = 0;
	float lowerBorderY = 0;

};

