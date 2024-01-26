#include "stdafx.h"
#include "BackgroundData.h"
#include <string>
using namespace std;

BackgroundData::BackgroundData() {

	//Set up coordinate system
	for (int i = 0; i < startValue; i++) {
		//x.push_back(startValue * i);
		//y.push_back(startValue * i);
		coordinates.push_back({ startValue * i , startValue * i });
	}
}

float BackgroundData::GetX(int index) {
	return coordinates.at(index).x;
}

float BackgroundData::GetY(int index) {
	return coordinates.at(index).y;
}

int BackgroundData::GetSize() {
	return coordinates.size();
}

void BackgroundData::AddBorderSprite(CSimpleSprite* sprite, float scale, string spriteName) {
	border[spriteName] = sprite;
	border[spriteName]->SetScale(scale);
}

void BackgroundData::AddDecorSprite(CSimpleSprite* sprite, float scale, string spriteName) {
	decor[spriteName] = sprite;
	decor[spriteName]->SetScale(scale);
}

void BackgroundData::AddFloorSprite(CSimpleSprite* sprite, float scale, string spriteName) {
	floor[spriteName] = sprite;
	floor[spriteName]->SetScale(scale);
}

CSimpleSprite* BackgroundData::GetBorderSprite(string spriteName) {
	return border[spriteName];
}

CSimpleSprite* BackgroundData::GetDecorSprite(string spriteName) {
	return decor[spriteName];
}

CSimpleSprite* BackgroundData::GetFloorSprite(string spriteName) {
	return floor[spriteName];
}
