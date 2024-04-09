#include "stdafx.h"
#include "GameObject.h"

LifeItems::LifeItems(CSimpleSprite* sprite, int lifeAmt, float spriteScale)
{
	objectSprite = sprite;
	numLife = lifeAmt;
	scale = spriteScale;

	objectSprite->SetScale(scale);
}

