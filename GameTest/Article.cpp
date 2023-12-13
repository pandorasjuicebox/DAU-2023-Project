#include "stdafx.h"
#include "Article.h"

Article::Article(int index, std::string desc, int enemyEff, int playerEff)
{
	articleNumber = index;
	description = &desc;
	effectOnEnemy = enemyEff;
	effectOnPlayer = playerEff;
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

void Article::setArticleLock(bool toggle)
{
	isLocked = toggle;
}
