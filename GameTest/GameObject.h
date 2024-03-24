#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include "MobHandler.h"
#include "BackgroundData.h"
#include <string>
#include <vector>
#include <Windows.h>
#include <WinUser.h>

using namespace std;
using namespace App;

class GameObject {
public: 
	int GetHealth();
	CSimpleSprite* GetObjectSprite();
	void SetHealth(int deduction);
	void RefreshPosition();
	float GetXPos();
	float GetYPos();
	bool intersects(GameObject* object);
	void SetXPos(float x);
	void SetYPos(float y);


protected:
	float xPos;
	float yPos;
	CSimpleSprite* objectSprite;
	int health;
	float speed;
	float scale;
	bool deadStatus = false;
	//BackgroundData* bgData;
	float minXBorder;
	float minYBorder;
	float maxXBorder;
	float maxYBorder;

};

class Player: public GameObject {
public: 
	Player(CSimpleSprite* sprite, int xCoord, int yCoord, BackgroundData* backData);
	void Update(float dTime);

	void SetGoing(int direction);
	int GetGoingDirection();
	void AddPlayerAreaCoord(float x, float y);

	void CreateBorders();

private:
	int facing;
	vector<Coord>playerArea;
	bool CheckBoundaries(float x, float y);
	BackgroundData* bgData;
};

class MobUnit : public GameObject {
public:
	//Constructor
	MobUnit(CSimpleSprite* sprite, int healthPoints, float x, float y, float mobScale, float mobSpeed);
	//CSimpleSprite* GetUnitSprite();
	void Update(float dTime, float playerX, float playerY);
	void AnimateMobUnit(const std::vector<int>& backwards, const std::vector<int>& left, const std::vector<int>& right, const std::vector<int>& forwards);
	void AnimateMobDeath(const std::vector<int>& death);
	//Store the location of the player
	void SetPlayerLocation(float xCoord, float yCoord);
	//Get the health of the unit
	int GetHealth();
	//Get mob type
	int GetType();
	//Remove Health
	void DeductHealth(int deduction);
	//Is it dead? If not, deduct health points only
	bool IsDead();
	bool IsMarkedDead();
	void MarkDead();

private:
	string unitName;
	float playerXPos;
	float playerYPos;
	bool markedDead = false; //to ensure that the scores don't stack
};