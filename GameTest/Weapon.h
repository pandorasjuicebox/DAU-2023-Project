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
	Weapon(BackgroundData* backData, float speed);
	void FireWeapon(float xOrigin, float yOrigin, float xDest, float yDest);
	void Update(float dTime);

	Coord GetPosition();

private:

	BackgroundData* bgData; 

	float xPos = 0;
	float yPos = 0;
	float weaponSpeed = 0;

	float rightBorderX = 0; 
	float leftBorderX = 0;
	float upperBorderY = 0;
	float lowerBorderY = 0;
};

