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
	Weapon(BackgroundData* backData, float speed, CSimpleSprite* bullet);
	void FireWeapon(float xStart, float yStart, float xDest, float yDest);
	void Update(float dTime);
	bool isActive();
	void Collided();
	void Stop();

	CSimpleSprite* GetWeaponSprite();

	void GetPosition(float x, float y);

	float GetXPos();
	float GetYPos();

private:

	BackgroundData* bgData; 
	CSimpleSprite* weaponSprite;
	//map < string, CSimpleSprite* > spriteDirections;

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

