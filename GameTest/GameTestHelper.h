#pragma once

#include <math.h>  
#include "GameObject.h"
#include "GameTestHelper.h"
using namespace std;

class GameTestHelper {
public:
	vector<MobUnit*> GenerateMobs(int numOfMobs, BackgroundData* bgData);
	vector<CSimpleSprite*> GenerateHealthBar(int numOfBars, BackgroundData* bgData);
	vector<CSimpleSprite*> GenerateLives(int numLives, BackgroundData* bgData);
	CSimpleSprite* GenerateFloor(BackgroundData* bgData, int selection);
	CSimpleSprite* GenerateBorderTiles(BackgroundData* bgData, int selection);
	CSimpleSprite* GenerateDecor(BackgroundData* bgData, int selection);

private:

};
