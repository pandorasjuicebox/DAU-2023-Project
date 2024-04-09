#include "stdafx.h"
#include "GameObject.h"
using namespace std;

BackgroundData::BackgroundData() {

	//Set up coordinate system
	for (int i = 0; i < startValue; i++) {
		coordinates.push_back({ startValue * i , startValue * i });
	}


	yLowerOuterBorder = 0;
	yUpperOuterBorder = 0;
	xLeftOuterBorder = 0;
	xRightOuterBorder = 0;
	yLowerInnerBorder = 0;
	yUpperInnerBorder = 0;
	xLeftInnerBorder = 0;
	xRightInnerBorder = 0;
}

void BackgroundData::Update(float deltaTime, CSimpleSprite* sprite) {
	sprite->Update(deltaTime);
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

bool BackgroundData::isThereAMedKit()
{
	return medKitState;
}

vector<Coord> BackgroundData::GetInnerBorderList()
{
	return innerBorderFrame;
}

vector<Coord> BackgroundData::GetOuterBorderList()
{
	return outerBorderFrame;
}

Coord BackgroundData::GetSpawnLocation(int direction)
{
	return spawnPoints[direction];
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

void BackgroundData::CreateBorders()
{

	yLowerOuterBorder = MinYValue(outerBorderFrame);
	yUpperOuterBorder = MaxYValue(outerBorderFrame);
	xLeftOuterBorder = MinXValue(outerBorderFrame);
	xRightOuterBorder = MaxXValue(outerBorderFrame);

	yLowerInnerBorder = MinYValue(innerBorderFrame);
	yUpperInnerBorder = MaxYValue(innerBorderFrame);
	xLeftInnerBorder = MinXValue(innerBorderFrame);
	xRightInnerBorder = MaxXValue(innerBorderFrame);

	CreateCardinalPoints();
}

void BackgroundData::CreateCardinalPoints()
{
	float offset = 100;
	//North
	spawnPoints[NORTH] = { (xRightOuterBorder / 2),yUpperOuterBorder - 100 };

	//South
	spawnPoints[SOUTH] = { (xRightOuterBorder / 2), yLowerOuterBorder };

	//East 
	spawnPoints[EAST] = { xRightOuterBorder - offset,(yUpperOuterBorder / 2) };

	//West
	spawnPoints[WEST] = { xLeftOuterBorder, (yUpperOuterBorder / 2) };
}

void BackgroundData::AddOuterBorderLocation(float x, float y)
{
	Coord coordinates = { x,y };
	outerBorderFrame.push_back(coordinates);
}

void BackgroundData::AddInnerBorderLocation(float x, float y)
{
	Coord coordinates = { x,y };
	innerBorderFrame.push_back(coordinates);
}

void BackgroundData::AddFloorLocation(float x, float y)
{
	Coord coordinates = { x,y };
	floorArea.push_back(coordinates);
}

void BackgroundData::SetMedKitStatus(bool status)
{
	medKitState = status;
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

Coord BackgroundData::GetOuterBorderLocation(int i)
{
	return outerBorderFrame.at(i);
}

Coord BackgroundData::GetInnerBorderLocation(int i)
{
	return innerBorderFrame.at(i);
}

Coord BackgroundData::GetFloorLocation(int i)
{
	return floorArea.at(i);
}

int BackgroundData::GetOuterBorderSize()
{
	return outerBorderFrame.size();
}

int BackgroundData::GetInnerBorderSize()
{
	return innerBorderFrame.size();
}

int BackgroundData::GetFloorSize()
{
	return floorArea.size();
}

float BackgroundData::GetMaxInnerX()
{
	return xRightInnerBorder;
}

float BackgroundData::GetMinInnerX()
{
	return xLeftInnerBorder;
}

float BackgroundData::GetMaxInnerY()
{
	return yUpperInnerBorder;
}

float BackgroundData::GetMinInnerY()
{
	return yLowerInnerBorder;
}

