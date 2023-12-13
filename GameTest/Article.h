#pragma once

#include "stdafx.h"
#include <string>


class Article {
	//For now: hardcoded Article data for encyclopedia
	//Future: Read it through a txt
	//Articles accessed by number

public: 
	Article(int index, std::string desc, int enemyEff, int playerEff);
	std::string *GetDescription(int index);
	int GetEnemyEffect(); 
	int GetPlayerEffect();
	int AddCardModifier(int enemyEff, int playerEff);

	bool isArticleLocked();
	bool HasPlayerEffect();
	bool HasEnemyEffect();

	void setArticleLock(bool toggle);

private:
	std::string *description; //flavour text
	bool isLocked = true; //default
	int articleNumber = 0;
	int effectOnEnemy = 0;
	int effectOnPlayer = 0;
};