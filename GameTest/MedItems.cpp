#include "stdafx.h"
#include "GameObject.h"

MedItems::MedItems(CSimpleSprite* sprite, int healthPoints, float spriteScale)
{
	objectSprite = sprite;
	health = healthPoints;
	scale = spriteScale;

	objectSprite->SetScale(scale);
}