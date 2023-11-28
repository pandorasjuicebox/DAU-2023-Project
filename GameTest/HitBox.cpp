#include "stdafx.h"
#include "HitBox.h"

#include "app\app.h"

bool HitBox::Collides(HitBox hitBox)
{

	return false;
}

float* HitBox::GetBoxLeft()
{
	return boxLeft;
}

float* HitBox::GetBoxHeight()
{
	return boxHeight;
}

void HitBox::SetBoxTop(float &boxTop)
{
	this->boxTop = &boxTop;
}

void HitBox::SetBoxLeft(float &boxLeft)
{
	this->boxLeft = &boxLeft;
}

void HitBox::SetBoxBottom(float &boxBottom)
{
	this->boxBottom = &boxBottom;
}

void HitBox::SetBoxRight(float &boxRight)
{
	this->boxRight = &boxRight;
}

void HitBox::SetBoxHeight(float &boxHeight)
{
	this->boxHeight = &boxHeight;
}
