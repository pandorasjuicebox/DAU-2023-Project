#pragma once

#include "stdafx.h"
#include <string>
using namespace std;


class Article {
	//For now: hardcoded Article data for encyclopedia
	//Future: Read it through a txt
	//Articles accessed by number

public: 
	Article(int index, string desc, int enemyEff, int playerEff, int numFloor, bool mustBeEven, bool mustBeOdd);
	std::string *GetDescription(int index);
	int GetEnemyEffect(); 
	int GetPlayerEffect();
	int GetFloor();
	int AddCardModifier(int enemyEff, int playerEff);

	bool isArticleLocked();
	bool HasPlayerEffect();
	bool HasEnemyEffect();
	bool MustBeEven();
	bool MustBeOdd();

	void setArticleLock(bool toggle);

private:
	std::string *description; //flavour text
	bool isLocked = true; //default
	int articleNumber = 0;
	int effectOnEnemy = 0;
	int effectOnPlayer = 0;
	int floor = 0; //baseline number accepted

	//default
	bool even = false;
	bool odd = false;
};