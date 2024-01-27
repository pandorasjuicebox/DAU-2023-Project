#include "stdafx.h"
#include "LevelMap.h"

LevelMap::LevelMap(BackgroundData* bgData, MobHandler* mbHandler)
{
	backgroundData = bgData;
	mobRecipes = mbHandler;
}

void LevelMap::NewLevel()
{
}

vector<MobUnit*> LevelMap::PopulateArea(string mobName, int amount)
{
	
	vector<MobUnit*>horde;

	for (int i = 0; i < amount; i++) {
		horde.push_back(new MobUnit(mobName, mobRecipes->GetMobHealth(mobName), mobRecipes->GetMobSpeedList(mobName), mobRecipes->GetMobScale(mobName), mobRecipes->getSpawnLocation(), mobRecipes->GetSprite(mobName)));
	}

	return horde;
}
