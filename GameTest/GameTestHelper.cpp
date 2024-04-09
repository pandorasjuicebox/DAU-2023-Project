#include "stdafx.h"
#include "GameTestHelper.h"

vector<MobUnit*> GameTestHelper::GenerateMobs(int numOfMobs, BackgroundData* bgData)
{

	vector<MobUnit*>units;

	int counter = 0;
	int minVar = 64;
	MobUnit* mob;

	for (int i = 0; i < numOfMobs; i++) {

		Coord dir;

		float xVal;
		float yVal;

		if (counter == 0) {
			dir = bgData->GetSpawnLocation(NORTH);
			xVal = dir.x + ((rand() % 500 - minVar + 1) + minVar);
			yVal = dir.y + ((rand() % 400 - minVar + 1) + minVar);
		}
		else if (counter == 1) {
			dir = bgData->GetSpawnLocation(SOUTH);
			xVal = dir.x + ((rand() % 500 - minVar + 1) + minVar);
			yVal = dir.y - ((rand() % 400 - minVar + 1) + minVar);
		}
		else if (counter == 2) {
			dir = bgData->GetSpawnLocation(EAST);
			xVal = dir.x + ((rand() % 40 - minVar + 1) + minVar);
			yVal = dir.y - ((rand() % 400 - minVar + 1) + minVar);
		}
		else if (counter == 3) {
			dir = bgData->GetSpawnLocation(WEST);
			xVal = dir.x - ((rand() % 500 - minVar + 1) + minVar);
			yVal = dir.y + ((rand() % 400 - minVar + 1) + minVar);
		}

		if (counter < 4) {
			counter++;
		}

		if (counter == 4) {
			counter = 0;
		}

		int mobChoice = (rand() % (2 - 0 + 1)  + 0);

		switch (mobChoice) {
		case 0: 
			mob = new MobUnit(CreateSprite(".\\TestData\\docile_skeleton_sheet.png", 6, 2), 2, xVal, yVal, 1.5f, (1.0f / 20.0f));
			mob->AnimateMobUnit({ 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 });
			break;

		case 1: 
			mob = new MobUnit(CreateSprite(".\\TestData\\dog_mob.png", 15, 1), 3, xVal, yVal, 1.5f, (1.0f / 25.0f));
			mob->AnimateMobUnit({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 }, { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 }, { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 }, { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 });
			break;
		
		case 2:
			mob = new MobUnit(CreateSprite(".\\TestData\\blue_slime.png", 3, 4), 2, xVal, yVal, 1.5f, (1.0f / 10.0f));
			mob->AnimateMobUnit({ 0,1,2, }, { 3,4,5 }, {6,7,8}, { 9,10,11 });
			break;
		}


		units.push_back(mob);
	}

    return units;
}

vector<CSimpleSprite*> GameTestHelper::GenerateHealthBar(int numOfBars, BackgroundData* bgData)
{
	vector<CSimpleSprite*>blocks;

	for (int i = 0; i < numOfBars; i++) {
		CSimpleSprite* lifeBlock = CreateSprite(".\\TestData\\one_bar.png", 1, 1);
		lifeBlock->SetScale(1.0f);
		lifeBlock->SetPosition(110, 590 + (10 * i));
		blocks.push_back(lifeBlock);
	}
	return blocks;
}

vector<CSimpleSprite*> GameTestHelper::GenerateLives(int numLives, BackgroundData* bgData)
{
	vector<CSimpleSprite*>lives;

	for (int i = 0; i < numLives; i++) {
		CSimpleSprite* lifeBlock = CreateSprite(".\\TestData\\player_icon.png", 1, 1);
		lifeBlock->SetScale(1.3f);
		lifeBlock->SetPosition(850 + (30* i), 620);
		lives.push_back(lifeBlock);
	}
	return lives;
}

CSimpleSprite* GameTestHelper::GenerateFloor(BackgroundData* bgData, int selection){

	CSimpleSprite* refVariable;
	switch (selection) {

	case 0:
		refVariable = bgData->GetFloorSprite("normal_grass");
		return refVariable;


	case 1:
		refVariable = bgData->GetFloorSprite("cobble");
		return refVariable;


	case 2:
		refVariable = bgData->GetFloorSprite("dirt");
		return refVariable;

	}
}

CSimpleSprite* GameTestHelper::GenerateBorderTiles(BackgroundData* bgData, int selection)
{

	CSimpleSprite* refVariable;

	switch (selection) {

	case 0:
		refVariable = bgData->GetBorderSprite("brown_stone");
		return refVariable;

	case 1:
		refVariable = bgData->GetBorderSprite("pink_stone");
		return refVariable;

	case 2:
		refVariable = bgData->GetBorderSprite("murky_stone");
		return refVariable;

	case 3:
		refVariable = bgData->GetBorderSprite("neon_stone");
		return refVariable;

	case 4:
		refVariable = bgData->GetBorderSprite("rust_stone");
		return refVariable;

	case 5:
		refVariable = bgData->GetBorderSprite("swamp_stone");
		return refVariable;
	}
	
}

	CSimpleSprite* GameTestHelper::GenerateDecor(BackgroundData * bgData, int selection)
	{
		CSimpleSprite* refVariable;

		switch (selection) {
		case 0:
			refVariable = bgData->GetDecorSprite("tree");
			return refVariable;

		case 1:
			refVariable = bgData->GetDecorSprite("blue_torch");
			return refVariable;

		case 2:
			refVariable = bgData->GetDecorSprite("bush");
			return refVariable;

		case 3:
			refVariable = bgData->GetDecorSprite("red_tree");
			return refVariable;

		case 4:
			refVariable = bgData->GetDecorSprite("rock");
			return refVariable;
		}
	
}
