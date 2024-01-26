#pragma once
#include "stdafx.h"
#include "Definitions.h"
#include "App/app.h"
#include <windows.h> 
#include <vector>
#include <string>
using namespace std;

class BackgroundData
{
public:
	BackgroundData();

	//Get x-value coordinates from vector x
	float GetX(int index);
	//Get y-value coordinates from vector y
	float GetY(int index);

	//Adding a sprite to a Map as a key-value pair
	void AddBorderSprite(CSimpleSprite* sprite, float scale, string spriteName);
	void AddDecorSprite(CSimpleSprite* sprite, float scale, string spriteName);
	void AddFloorSprite(CSimpleSprite* sprite, float scale, string spriteName);

	//Getters
	CSimpleSprite* GetBorderSprite(string spriteName);
	CSimpleSprite* GetDecorSprite(string spriteName);
	CSimpleSprite* GetFloorSprite(string spriteName);
	int GetSize();

private:
	//Stores x and y coord
	//multiples of 32
	vector<Coord>coordinates;

	//Stores decor, border, and floor sprites as key-value pairs
	//Used by the AddDecorSprite, AddBorderSprite, and AddFloorSprite methods
	map< string, CSimpleSprite*> decor;
	map< string, CSimpleSprite* >border;
	map< string, CSimpleSprite* >floor;

	// Set up coordination system that goes by multiples of 32
	// This is what the Tiles will use to position themselves across the game area
	float startValue = 32;
};

