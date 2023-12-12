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
	return description;
}

int Article::GetEnemyEffect()
{
	return effectOnEnemy;
}

int Article::GetPlayerEffect()
{
	return effectOnPlayer;
}

bool Article::isArticleLocked()
{
	return isLocked;
}

void Article::setArticleLock(bool toggle)
{
	isLocked = toggle;
}
