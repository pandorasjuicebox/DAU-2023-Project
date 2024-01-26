#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
using namespace std;
using namespace App;

class Player {
public:
	//Player();
	Player(CSimpleSprite* sprite, int xCoord, int yCoord);
	CSimpleSprite* GetPlayerSprite();
	void Update(float dTime);
	void ResetPlayerStats(); //Reset for a new game
	void AddLife(); //Adds one life
	float GetXPos();
	float GetYPos();

private:
	CSimpleSprite* playerSprite;
	float playerSpeed = 0;
	int playerLives = 3; //default, 3 chances
	float xPos = 0;
	float yPos = 0;
};

