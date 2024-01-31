#include "stdafx.h"
#include "MobHandler.h"

void MobHandler::AddMobSprite(string name, int health, float speed, float scale, CSimpleSprite* sprite)
{
	spriteList[name] = sprite;
	mobHealthList[name] = health;
	mobSpeedList[name] = speed;
	mobScale[name] = scale;
}

void MobHandler::AnimateMobUnit(string name, const std::vector<int>& backwards, const std::vector<int>& left, const std::vector<int>& right, const std::vector<int>& forwards)
{
	spriteList[name]->CreateAnimation(ANIM_BACKWARDS, mobSpeedList[name], backwards);
	spriteList[name]->CreateAnimation(ANIM_LEFT, mobSpeedList[name], left);
	spriteList[name]->CreateAnimation(ANIM_RIGHT, mobSpeedList[name], right);
	spriteList[name]->CreateAnimation(ANIM_FORWARDS, mobSpeedList[name], forwards);
}

void MobHandler::AnimateMobDeath(string name, const std::vector<int>& death) {
	spriteList[name]->CreateAnimation(UNIT_DEATH, mobSpeedList[name], death);
}

CSimpleSprite* MobHandler::GetSprite(string name)
{
	return spriteList[name];
}

int MobHandler::GetMobHealth(string name)
{
	return mobHealthList[name];
}

float MobHandler::GetMobSpeedList(string name)
{
	return mobSpeedList[name];
}

float MobHandler::GetMobScale(string name)
{
	return mobScale[name];
}

