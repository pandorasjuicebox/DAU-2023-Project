#pragma once
#include "stdafx.h"
#include "App/app.h"
#include <string>
#include "MapElements.h"
using namespace std;
using namespace App;

struct Coord {
	float x; float y;
};

class Tile {
public:
	Tile(int type, float xPos, float yPos, bool passable, bool exit);
	void SetPosition(float xPos, float yPos);

	int GetType();

	float GetXPos();
	float GetYPos();

	bool IsPassable();
	bool IsExitPoint();

	//CSimpleSprite* tileSprite;

private:
	int tileType;
	//string path;
	Coord location;
	bool isPassable = true; //default
	bool isExitPoint = false; //default
};