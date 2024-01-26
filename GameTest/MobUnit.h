#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include <string>
#include <vector>
using namespace std;
using namespace App;

class MobUnit {
public:
	//Constructor
	MobUnit(string name, int health, float speed, float xCoord, float yCoord, float scale, CSimpleSprite* sprite);
	CSimpleSprite* GetUnitSprite();
	void Update(float dTime, float playerX, float playerY);
	//Store the location of the player
	void SetPlayerLocation(float xCoord, float yCoord);
	//Get the health of the unit
	int getHealth();
	//Is it dead? If not, deduct health points only
	bool isDead();

private:

	int unitHealth;
	string unitName;
	CSimpleSprite* unitSprite;
	float xPos;
	float yPos;
	float unitSpeed;
	float unitScale;

	float playerXPos = 0;
	float playerYPos = 0;

};