#pragma once
#include "stdafx.h"
#include "Definitions.h"
#include "App/app.h"
#include "BackgroundData.h"
#include "MobHandler.h"
#include "MobUnit.h"
#include <vector>
#include <string>
using namespace std;
using namespace App;

class LevelMap
{
public:
	//Passes background and mob data (so far)
	LevelMap(BackgroundData* bgData, MobHandler* mbHandler);
	void NewLevel();
	vector<MobUnit*> PopulateArea(string mobName, int amount);

private: 
	BackgroundData* backgroundData;
	MobHandler* mobRecipes;
};

