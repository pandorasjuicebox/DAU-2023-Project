#include "stdafx.h"
#include "Article.h"

//Article::Article(int index, std::string desc, int enemyEff, int playerEff, int numFloor, int mustBeEven, int mustBeOdd);
//{
//	articleNumber = index;
//	description = &desc;
//	effectOnEnemy = enemyEff;
//	effectOnPlayer = playerEff;
//}

Article::Article(int index, string desc, int enemyEff, int playerEff, int numFloor, bool mustBeEven, bool mustBeOdd)
{
	articleNumber = index;
	description = &desc;
	effectOnEnemy = enemyEff;
	effectOnPlayer = playerEff;
	floor = numFloor;
	even = mustBeEven;
	odd = mustBeOdd;
}

std::string *Article::GetDescription(int index)
{
	return this->description;
}

int Article::GetEnemyEffect()
{
	return this->effectOnEnemy;
}

int Article::GetPlayerEffect()
{
	return this->effectOnPlayer;
}

int Article::GetFloor()
{
	return floor;
}

int Article::AddCardModifier(int enemyEff, int playerEff)
{
	int modifiedValue = 0; 

	// 0 doesn't change any values, nonzeroes do.
	if (enemyEff > 0 || enemyEff < 0) {
		modifiedValue = GetEnemyEffect() + enemyEff;
	}
	else if (playerEff > 0 || playerEff < 0) {
		modifiedValue = GetPlayerEffect() + playerEff;
	}

	return modifiedValue;
}

bool Article::isArticleLocked()
{
	return this->isLocked;
}

bool Article::HasPlayerEffect()
{
	return effectOnPlayer > 0;
}

bool Article::HasEnemyEffect()
{
	return effectOnEnemy > 0;
}

bool Article::MustBeEven()
{
	return even;
}

bool Article::MustBeOdd()
{
	return odd;
}

void Article::setArticleLock(bool toggle)
{
	isLocked = toggle;
}
