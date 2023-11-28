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
}

void HitBox::SetBoxRight(float &boxRight)
{
}

void HitBox::SetBoxHeight(float &height)
{
}
