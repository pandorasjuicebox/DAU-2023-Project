#pragma once
#include "stdafx.h"
#include "Definitions.h"
#include "App/app.h"
#include <vector>
#include <string>
using namespace std;
using namespace App;

class MobHandler {

public:

	void AddMobSprite(string name, int health, float speed, float scale, CSimpleSprite* sprite);
	void AnimateMobUnit(string name, const std::vector<int>& backwards, const std::vector<int>& left, const std::vector<int>& right, const std::vector<int>& forwards);
	void AnimateMobDeath(string name, const std::vector<int>& death);
	//void RemoveSprite(string name, const std::vector<int>& afterDeath);
	CSimpleSprite* GetSprite(string name);
	int GetMobHealth(string name);
	float GetMobSpeedList(string name);
	float GetMobScale(string name);

private:

	//Key-Value Pairs
	map< string, CSimpleSprite* >spriteList;
	map< string, int > mobHealthList;
	map< string, float > mobSpeedList;
	map< string, float> mobScale;

	

};

