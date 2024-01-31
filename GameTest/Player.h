#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include "Weapon.h"
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
	void PlayerAttacking(int dir);
	int GetPlayerAttackDirection();

private:
	CSimpleSprite* playerSprite;
	Weapon* playerWeapon;
	float playerSpeed = 0;
	int playerLives = 3; //default, 3 chances
	float xPos = 0;
	float yPos = 0;
	int attackDirection = NO_ATTACK;
};

