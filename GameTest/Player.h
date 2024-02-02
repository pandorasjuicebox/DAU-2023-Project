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
	//void AddLife(); //Adds one life
	//void RemoveLife(); // Removes one life

	//int GetLives();
	float GetXPos();
	float GetYPos();
	
	void SetGoing(int direction);
	int GetGoingDirection();

private:
	CSimpleSprite* playerSprite;
	float playerSpeed;
	//int playerLives = 3; //default, 3 chances
	float xPos;
	float yPos;
	int facing;
};

