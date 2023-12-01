#include "GameObject.h"

void GameObject::SetCrosssable(bool state)
{
	isCrossable = state;
}

bool* GameObject::IsMoveableObj()
{
	return &isMoveable;
}

bool* GameObject::IsActiveObj()
{
	return &isActive;
}

bool* GameObject::IsVisibleObj()
{
	return &isVisible;
}

void GameObject::SetObjVisible(bool state)
{
	isVisible = state; 
}

void GameObject::SetObjHitbox()
{
}

void GameObject::SetMoveableObj(bool state)
{
	isMoveable = state; 
}
