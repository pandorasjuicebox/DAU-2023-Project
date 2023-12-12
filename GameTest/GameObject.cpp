
#include "stdafx.h"
#include "GameObject.h"
#include "App/app.h"

//GameObject::GameObject(const char* fileName, unsigned int nColumns, unsigned int nRows)
//{
//	objectSprite = App::CreateSprite(fileName, nColumns, nRows);
//}

void GameObject::SetObjSprite(CSimpleSprite* sprite)
{
	objectSprite = sprite;
}

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

//const char* GameObject::GetSpriteName()
//{
//	return spriteName;
//}

void GameObject::SetObjVisible(bool state)
{
	isVisible = state; 
}

void GameObject::SetObjHitbox(float x, float y)
{
	float boxRight = x + objectSprite->GetWidth();
	float boxTop = y + objectSprite->GetHeight();
	objHitBox.SetBoxBottom(y);
	objHitBox.SetBoxRight(boxRight);
	objHitBox.SetBoxTop(boxTop);
	objHitBox.SetBoxLeft(x);

}

void GameObject::SetMoveableObj(bool state)
{
	isMoveable = state; 
}
