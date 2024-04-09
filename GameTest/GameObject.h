#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include "MobHandler.h"
#include <string>
#include <vector>
#include <Windows.h>
#include <WinUser.h>

using namespace std;
using namespace App;

class GameObject {
public:
	float GetHealth();
	CSimpleSprite* GetObjectSprite();
	void RemoveHealth(float deduction);
	void GainHealth(int addition);
	void RefreshPosition();
	float GetXPos();
	float GetYPos();
	bool intersects(GameObject* object);
	void SetXPos(float x);
	void SetYPos(float y);
	bool IsDead();


protected:
	float xPos = 0;
	float yPos = 0;
	CSimpleSprite* objectSprite;
	float health = 0;
	float speed = 0;
	float scale = 0;
	bool deadStatus = false;
	//BackgroundData* bgData;
	float minXBorder = 0;
	float minYBorder = 0;
	float maxXBorder = 0;
	float maxYBorder = 0;

};

class MedItems : public GameObject {
public:
	MedItems(CSimpleSprite* sprite, int healthPoints, float spriteScale);
};

class LifeItems : public GameObject {
public:
	LifeItems(CSimpleSprite* sprite, int lifeAmount, float spriteScale);

private:
	int numLife = 0;
};

class MobUnit : public GameObject {
public:
	//Constructor
	MobUnit(CSimpleSprite* sprite, int healthPoints, float x, float y, float mobScale, float mobSpeed);
	//CSimpleSprite* GetUnitSprite();
	void Update(float dTime, float playerX, float playerY);
	void AnimateMobUnit(const std::vector<int>& backwards, const std::vector<int>& left, const std::vector<int>& right, const std::vector<int>& forwards);
	//Store the location of the player
	void SetPlayerLocation(float xCoord, float yCoord);
	//Get the health of the unit
	int GetHealth();
	//Get mob type
	int GetType();
	//Remove Health
	void RemoveHealth(int deduction);

private:
	float playerXPos;
	float playerYPos;
	float fullHealth;
	
};


class BackgroundData : public GameObject {
public:

	//Constructor
	BackgroundData();
	void Update(float deltaTime, CSimpleSprite* sprite);
	//Get x-value coordinates from vector x
	float GetX(int index);
	//Get y-value coordinates from vector y
	float GetY(int index);

	//Adding a sprite to a Map as a key-value pair
	void AddBorderSprite(CSimpleSprite* sprite, float scale, string spriteName);
	void AddDecorSprite(CSimpleSprite* sprite, float scale, string spriteName);
	void AddFloorSprite(CSimpleSprite* sprite, float scale, string spriteName);

	void CreateBorders();

	void AddOuterBorderLocation(float x, float y);
	void AddInnerBorderLocation(float x, float y);
	void AddFloorLocation(float x, float y);

	void SetMedKitStatus(bool status);

	//GETTERS -----------------------------------------

	CSimpleSprite* GetBorderSprite(string spriteName);
	CSimpleSprite* GetDecorSprite(string spriteName);
	CSimpleSprite* GetFloorSprite(string spriteName);

	//Coord Getters 
	Coord GetOuterBorderLocation(int i);
	Coord GetInnerBorderLocation(int i);
	Coord GetFloorLocation(int i);
	Coord GetSpawnLocation(int direction);

	//Value Getters
	int GetOuterBorderSize();
	int GetInnerBorderSize();
	int GetFloorSize();

	float GetMaxInnerX();
	float GetMinInnerX();
	float GetMaxInnerY();
	float GetMinInnerY();

	float MaxXValue(vector<Coord>list);
	float MinXValue(vector<Coord>list);
	float MaxYValue(vector<Coord>list);
	float MinYValue(vector<Coord>list);

	int GetSize();

	bool isThereAMedKit();

	//Vector Getters
	vector<Coord> GetInnerBorderList();
	vector<Coord> GetOuterBorderList();

private:
	//Stores x and y coord
	//multiples of 32
	vector<Coord>coordinates;

	//coordinates of non-playable areas
	vector<Coord>outerBorderFrame;
	vector<Coord>innerBorderFrame;

	//coordinates of playable floor area
	vector<Coord>floorArea;

	//Stores decor, border, and floor sprites as key-value pairs
	//Used by the AddDecorSprite, AddBorderSprite, and AddFloorSprite methods
	map< string, CSimpleSprite* > decor;
	map< string, CSimpleSprite* > border;
	map< string, CSimpleSprite* > floor;

	//Key-value pairs where int values are the 
	//enums of NORTH, SOUTH, EAST, WEST to get the corresponding Coord
	map< int, Coord> spawnPoints;

	//Outer Borders
	float yLowerOuterBorder;
	float yUpperOuterBorder;
	float xLeftOuterBorder;
	float xRightOuterBorder;

	//Inner Borders
	float yLowerInnerBorder;
	float yUpperInnerBorder;
	float xLeftInnerBorder;
	float xRightInnerBorder;

	// Set up coordination system that goes by multiples of 32
	// This is what the Tiles will use to position themselves across the game area
	float startValue = 32;

	//Helper function that generate Coords for NORTH, SOUTH, EAST, WEST
	void CreateCardinalPoints();

	//Medkit Status
	bool medKitState = false;


};

class Player : public GameObject {
public:
	Player(CSimpleSprite* sprite, int xCoord, int yCoord, BackgroundData* backData);
	void Update(float dTime);

	void SetGoing(int direction);
	int GetGoingDirection();
	void AddPlayerAreaCoord(float x, float y);
	bool intersects(GameObject* object); //override
	void CreateBorders();

private:
	int facing;
	vector<Coord>playerArea;
	bool CheckBoundaries(float x, float y);
	BackgroundData* bgData;
};

