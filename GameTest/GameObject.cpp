#include "stdafx.h"
#include "GameObject.h"

float GameObject::GetHealth()
{
    return health;
}

CSimpleSprite* GameObject::GetObjectSprite()
{
    return objectSprite;
}

void GameObject::RemoveHealth(float deduction)
{
    if (health - deduction < PLAYER_NO_HEALTH) {
        health = PLAYER_NO_HEALTH;
    }
    else {
        health = health - deduction;
    }
}

void GameObject::GainHealth(int addition)
{

    if (health + addition > PLAYER_FULL_HEALTH) {
        health = PLAYER_FULL_HEALTH;
    }
    else {
        health = health + addition;
    }
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
    float xPosWithOffset = xPos -  5;
    float yPosWithOffset = yPos + 2;


    yValue = object->GetYPos();
    xValue = object->GetXPos();

    double calculation = 0;


    calculation = sqrt(abs(pow(xPosWithOffset - xValue, 2)) + abs(pow((yPosWithOffset - yValue), 2)));

    if (calculation < 10){
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

bool GameObject::IsDead()
{
    if (health <= 0) {
        deadStatus = true;
    }
    else {
        deadStatus = false;
    }
    return deadStatus;
}


