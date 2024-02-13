#pragma once
#include "stdafx.h"
#include "Definitions.h"
#include "App/app.h"
#include <windows.h> 
#include <vector>
#include <string>
#include <iostream>
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

	void CreateBorders();

	void AddOuterBorderLocation(float x, float y);
	void AddInnerBorderLocation(float x, float y);
	void AddFloorLocation(float x, float y);

	//Getters
	CSimpleSprite* GetBorderSprite(string spriteName);
	CSimpleSprite* GetDecorSprite(string spriteName);
	CSimpleSprite* GetFloorSprite(string spriteName);

	Coord GetOuterBorderLocation(int i);
	Coord GetInnerBorderLocation(int i);
	Coord GetFloorLocation(int i);

	int GetOuterBorderSize();
	int GetInnerBorderSize();
	int GetFloorSize();

	float GetMaxInnerX();
	float GetMinInnerX();
	float GetMaxInnerY();
	float GetMinInnerY();

	int GetSize();

	vector<Coord> GetSpawnPoints();
	Coord GetSpawnLocation();

private:
	//Stores x and y coord
	//multiples of 32
	vector<Coord>coordinates;

	vector<Coord>outerBorderFrame; //coordinates of non-playable area
	vector<Coord>innerBorderFrame; 
	vector<Coord>floorArea;

	vector<Coord>spawnPoints;

	//Stores decor, border, and floor sprites as key-value pairs
	//Used by the AddDecorSprite, AddBorderSprite, and AddFloorSprite methods
	map< string, CSimpleSprite* > decor;
	map< string, CSimpleSprite* > border;
	map< string, CSimpleSprite* > floor;

	//Outer Border
	float yLowerOuterBorder; 
	float yUpperOuterBorder; 
	float xLeftOuterBorder; 
	float xRightOuterBorder; 

	//Inner Border
	float yLowerInnerBorder;
	float yUpperInnerBorder;
	float xLeftInnerBorder;
	float xRightInnerBorder;

	// Set up coordination system that goes by multiples of 32
	// This is what the Tiles will use to position themselves across the game area
	float startValue = 32;

	float MaxXValue(vector<Coord>list);
	float MinXValue(vector<Coord>list);
	float MaxYValue(vector<Coord>list);
	float MinYValue(vector<Coord>list);
	void CreateCardinalPoints();

};

