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

class GameObject {
public: 
	int GetHealth();
	CSimpleSprite* GetObjectSprite();
	void SetHealth(int deduction);

protected:
	float xPos;
	float yPos;
	float scale;
	CSimpleSprite* objectSprite;
	int health;
	float speed;
	bool deadStatus = false;
};

class Player: GameObject {
public: 
	Player(CSimpleSprite* sprite, int xCoord, int yCoord);
	void Update(float dTime);
	float GetXPos();
	float GetYPos();

	void SetGoing(int direction);
	int GetGoingDirection();

private:
	int facing;
};

class MobUnit : GameObject {
public:
	//Constructor
	MobUnit(MobHandler* mbHandler, BackgroundData* backData);
	void AddMobUnit(string name);
	CSimpleSprite* GetUnitSprite();
	void Update(float dTime, float playerX, float playerY);
	//Store the location of the player
	void SetPlayerLocation(float xCoord, float yCoord);
	//Get the health of the unit
	int GetHealth();
	//Get mob type
	int GetType();
	//Remove Health
	void SetHealth(int deduction);
	//Is it dead? If not, deduct health points only
	bool isDead();
private:
	MobHandler* mobDirectory;
	BackgroundData* bgData;
	string unitName;
	float playerXPos;
	float playerYPos;
};