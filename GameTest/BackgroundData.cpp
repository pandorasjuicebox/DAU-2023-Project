#include "stdafx.h"
#include "BackgroundData.h"
using namespace std;

BackgroundData::BackgroundData() {

	//Set up coordinate system
	for (int i = 0; i < startValue; i++) {
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

float BackgroundData::GetLowerOuterBorderY()
{
	return yLowerOuterBorder;
}

float BackgroundData::GetUpperOuterBorderY()
{
	return yUpperOuterBorder;
}

float BackgroundData::GetLeftOuterBorderX()
{
	return xLeftOuterBorder;
}

float BackgroundData::GetRightOuterBorderX()
{
	return xRightOuterBorder;
}

float BackgroundData::GetLowerInnerBorderY()
{
	return yLowerInnerBorder;
}

float BackgroundData::GetUpperInnerBorderY()
{
	return yUpperInnerBorder;
}

float BackgroundData::GetLeftInnerBorderX()
{
	return xLeftInnerBorder;
}

float BackgroundData::GetRightInnerBorderX()
{
	return xRightInnerBorder;
}

float BackgroundData::MaxXValue(vector<Coord> list)
{

	vector<float>xValues;
	int maxVal = 0;

	for (int i = 0; i < list.size(); i++) {
		xValues.push_back(list.at(i).x);
	}

	maxVal = *max_element(xValues.begin(), xValues.end());

	return maxVal;
}

float BackgroundData::MinXValue(vector<Coord> list)
{
	vector<float>xValues;

	int minVal = 0;

	for (int i = 0; i < list.size(); i++) {
		xValues.push_back(list.at(i).x);
	}

	minVal = *min_element(xValues.begin(), xValues.end());

	return minVal;
}

float BackgroundData::MaxYValue(vector<Coord> list)
{
	vector<float>yValues;

	int maxVal = 0;

	for (int i = 0; i < list.size(); i++) {
		yValues.push_back(list.at(i).y);
	}

	maxVal = *max_element(yValues.begin(), yValues.end());

	return maxVal;
}

float BackgroundData::MinYValue(vector<Coord> list)
{
	vector<float>yValues;

	int minVal = 0;

	for (int i = 0; i < list.size(); i++) {
		yValues.push_back(list.at(i).y);
	}

	minVal = *min_element(yValues.begin(), yValues.end());

	return minVal;
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

void BackgroundData::CreateBorders(vector<Coord> &outerBorder, vector<Coord> &innerBorder)
{
	outerBorderFrame = outerBorder;
	innerBorderFrame = innerBorder;

	yLowerOuterBorder = MinYValue(outerBorderFrame);
	yUpperOuterBorder = MaxYValue(outerBorderFrame);
	xLeftOuterBorder = MinXValue(outerBorderFrame);
	xRightOuterBorder = MaxXValue(outerBorderFrame);

	yLowerInnerBorder = MinYValue(innerBorderFrame);
	yUpperInnerBorder = MaxYValue(innerBorderFrame);
	xLeftInnerBorder = MinXValue(innerBorderFrame);
	xRightInnerBorder = MaxXValue(innerBorderFrame);
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
