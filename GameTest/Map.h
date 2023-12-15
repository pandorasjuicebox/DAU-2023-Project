#pragma once

#include "stdafx.h"
#include <vector>
#include "Tile.h"
#include "App/app.h"
#include "MapElements.h"
using namespace std;

class Map {
public:
	Map(float mapSize);
	void AddTile(int type, float x, float y, bool passable, bool exit);
	float GetMaxSize();
	Tile* GetTile(int index);
private:
	float gridSize;
	Coord exitLocation;
	Coord playerLocation;

	vector<Tile> tileLocations;

	//helper functions TODO --- for now, hardcode for V1
	//vector<float> availableX(float playerX, float exitX);
	//vector<float> availableY(float playerY, float exitY);
};