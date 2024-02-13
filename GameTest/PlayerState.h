#pragma once
#include "stdafx.h"
#include "app/app.h"
#include "Definitions.h"
#include "GameObject.h"
using namespace std;
using namespace App;

class PlayerState
{
public:
	void ResetPlayerStats(); // for a new game
	void AddLife(); // +1 
	void RemoveLife(); // -1
	void AddScore(int amount);
	void SetPersonalBest(int amount); // for this current run

	int GetLives(); // current player lives
	int GetScore(); 


private: 
	int playerLives = 3; // default
	int score = 0;
	int personalBest = 0;
};

