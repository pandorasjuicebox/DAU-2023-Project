#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include "MobHandler.h"
#include "BackgroundData.h"
#include <string>
#include <vector>
using namespace std;
using namespace App;

class MobUnit {
public:
	//Constructor
	MobUnit(MobHandler* mbHandler, BackgroundData* backData);
	void AddMobUnit(string name);
	CSimpleSprite* GetUnitSprite();
	void Update(float dTime, float playerX, float playerY);
	//Store the location of the player
	void SetPlayerLocation(float xCoord, float yCoord);
	//Get the health of the unit
	int getHealth();
	//Is it dead? If not, deduct health points only
	bool isDead();
	
	void SetFacing(int direction);
	int GetFacing();

private:

	MobHandler* mobDirectory;
	BackgroundData* bgData;
	int unitHealth;
	string unitName;
	CSimpleSprite* unitSprite;
	float xPos;
	float yPos;
	float unitSpeed;
	float unitScale;

	float playerXPos;
	float playerYPos;
	bool lifeStatus = false;

	int facing;

};