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

void GameObject::RefreshPosition()
{
    objectSprite->GetPosition(xPos, yPos);
    objectSprite->SetPosition(xPos, yPos);
}

float GameObject::GetXPos()
{
    return xPos;
}

float GameObject::GetYPos()
{
    return yPos;
}

bool GameObject::intersects(GameObject* object)
{
    
    object->RefreshPosition();
    RefreshPosition();

    float yValue = 0;
    float xValue = 0;


    yValue = yPos - object->GetYPos();
    xValue = xPos - object->GetXPos();

    if (yValue >= 0 && yValue <= objectSprite->GetWidth() && xValue >= 0 && xValue <= objectSprite->GetWidth()) {
        return true;
    }
    
    if (xValue <= 0 && xValue + objectSprite->GetWidth() >= xValue) {
        return true;
    }


    return false;
}

void GameObject::SetXPos(float x)
{
    xPos = x;
}

void GameObject::SetYPos(float y)
{
    yPos = y;
}


