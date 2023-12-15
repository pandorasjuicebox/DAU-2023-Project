#include "stdafx.h"
#include "Map.h"

Map::Map(float mapSize){
	gridSize = mapSize;
}

void Map::AddTile(int type, float x, float y, bool passable, bool exit)
{
	Tile newTile = Tile(type, x, y, passable, exit);
	tileLocations.push_back(newTile);
}

float Map::GetMaxSize()
{
	return gridSize;
}

Tile* Map::GetTile(int index)
{
	return &tileLocations.at(index);
}



