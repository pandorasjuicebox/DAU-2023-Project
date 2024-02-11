#include "stdafx.h"
#include "GameObject.h"

int GameObject::GetHealth()
{
    return health;
}

CSimpleSprite* GameObject::GetObjectSprite()
{
    return objectSprite;
}

void GameObject::SetHealth(int deduction)
{
    health = health - deduction;
}
