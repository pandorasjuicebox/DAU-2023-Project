//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
#include <vector>
#include <string>
//------------------------------------------------------------------------
#include "app\app.h"
#include "Player.h"
#include "Definitions.h"
#include "BackgroundData.h"
#include "MobHandler.h"
#include "MobUnit.h"
using namespace App;
using namespace std;
//------------------------------------------------------------------------

//CSimpleSprite *testSprite;


CSimpleSprite* playerSprite;
//CSimpleSprite* slimeEnemy1;
CSimpleSprite* tileWall;
CSimpleSprite* tree;
CSimpleSprite* gameFloor;

Player* playerObject;
BackgroundData* bgData;
MobHandler* mobHandler;

vector<Coord>decorBorderLocations;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	bgData = new BackgroundData();
	mobHandler = new MobHandler();

	vector<Coord>outerBorders;
	vector<Coord>innerBorders;

	int lowerInnerXOffset = 25;
	int lowerInnerYOffset = 20;
	int upperInnerXOffset = 25;
	int upperInnerYOffset = 10;
	int sideInnerXOffset = 20;
	int gameFloorXOffset = 20;

	//Set up outer borders --------
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Upper Wall Border
			if (i == 30 || i == 31 || k == 24 || k == 23) {outerBorders.push_back({ bgData->GetX(i),bgData->GetY(k) });}}
	}
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Wall border (Lower and Sides)
			if (i == 0 || i == 1 || k == 0 || k == 1) { outerBorders.push_back({ bgData->GetX(i),bgData->GetY(k) });}
		}
	}
	// ----------------------------

	//Set up inner border ---------
	//Upper Border Trees
	for (int i = 0; i < 32; i++) { 
		for (int k = 0; k < 25; k++) { 
			if ((i > 1) && (i < 22) && (k == 21)) {innerBorders.push_back({ bgData->GetX(i) + upperInnerXOffset,bgData->GetY(k) + upperInnerYOffset });}
		}
	}
	//Side Border Trees
	for (int i = 32; i > 1; i--) {
		for (int k = 21; k > 2; k--) {
			if (((i == 2) || (i == 28)) && ((k >= 2) || (k <= 10))) {innerBorders.push_back({ bgData->GetX(i) + sideInnerXOffset,bgData->GetY(k) });}
		}
	}
	//Lower Border Trees and Lower + Side Wall Borders
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Wall border (Lower and Sides)
			if (i == 0 || i == 1 || k == 0 || k == 1) {innerBorders.push_back({ bgData->GetX(i) + lowerInnerXOffset,bgData->GetY(k) + lowerInnerYOffset });}
		}
	}
	//-----------------------------

	//The Player ---------------
	//positioned at the center
	playerObject = new Player(CreateSprite(".\\TestData\\player_general_movement.png", 6, 6), bgData->GetX(bgData->GetSize() / 2), bgData->GetY(bgData->GetSize() / 2));
	playerSprite = playerObject->GetPlayerSprite();

	//Border Tiles --------------
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\stone2_dark3.png", 1, 1), 1.5f, "dark_stone");
	tileWall = bgData->GetBorderSprite("dark_stone");

	//Decor Tiles --------------
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\tree.png", 1, 1), 1.0f, "tree");
	tree = bgData->GetDecorSprite("tree");

	//Floor Tiles ---------------
	bgData->AddFloorSprite(CreateSprite(".\\TestData\\normal_grass.png", 1, 1), 2.0f, "normal_grass");
	gameFloor = bgData->GetFloorSprite("normal_grass");

	//Enemy Mobs ----------------
	mobHandler->AddMobSprite("docile_skeleton", 1, (1.0f / 20.0f), 2.0f, CreateSprite(".\\TestData\\docile_skeleton.png", 6, 1));
	mobHandler->AnimateMobUnit("docile_skeleton", { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 });
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	playerObject->Update(deltaTime);

	if (IsKeyPressed(VK_SHIFT))
	{
		//playerSprite->SetPosition(x[15], y[15]);
		//gameFloor = bgData->GetBorderSprite(1);
	}


	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
}


//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	int lowerTreeXOffset = 25;
	int lowerTreeYOffset = 20;
	int upperTreeXOffset = 25;
	int upperTreeYOffset = 10;
	int sideTreeXOffset = 20;
	int gameFloorXOffset = 20;

	//Ground / Floor
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Floor
			if ((i > 1) && (i < 29) && (k < 22)) {
				gameFloor->SetPosition(bgData->GetX(i) + gameFloorXOffset, bgData->GetY(k));
				gameFloor->Draw();
			}
		}
	}


	//Upper Wall Border
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row

			//Upper Wall Border
			if (i == 30 || i == 31 || k == 24 || k == 23) {
				tileWall->SetPosition(bgData->GetX(i), bgData->GetY(k));
				tileWall->Draw();
				decorBorderLocations.push_back({ bgData->GetX(i),bgData->GetY(k) });
			}
		}
	}

	//Upper Border Trees
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row

			if ((i > 1) && (i < 22) && (k == 21)) {
				tree->SetPosition(bgData->GetX(i) + upperTreeXOffset, bgData->GetY(k) + upperTreeYOffset);
				tree->Draw();
				decorBorderLocations.push_back({ bgData->GetX(i) + upperTreeXOffset,bgData->GetY(k) + upperTreeYOffset });
				upperTreeXOffset = upperTreeXOffset + (tree->GetWidth() / 4);
			}
		}
	}

	//Side Border Trees
	for (int i = 32; i > 1; i--) {
		for (int k = 21; k > 2; k--) {

			if (((i == 2) || (i == 28)) && ((k >= 2) || (k <= 10))) {
				tree->SetPosition(bgData->GetX(i) + sideTreeXOffset, bgData->GetY(k));
				tree->Draw();
				decorBorderLocations.push_back({ bgData->GetX(i) + sideTreeXOffset,bgData->GetY(k) });
			}
		}
	}

	//Lower Border Trees and Lower + Side Wall Borders
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row

			//Lower Border Trees
			if ((i > 1) && (i < 22) && (k == 2)) {
				tree->SetPosition(bgData->GetX(i) + lowerTreeXOffset, bgData->GetY(k) + lowerTreeYOffset);
				tree->Draw();
				decorBorderLocations.push_back({ bgData->GetX(i) + lowerTreeXOffset,bgData->GetY(k) + lowerTreeYOffset });
				lowerTreeXOffset = lowerTreeXOffset + (tree->GetWidth() / 4);
			}

			//Wall border (Lower and Sides)
			if (i == 0 || i == 1 || k == 0 || k == 1) {
				tileWall->SetPosition(bgData->GetX(i), bgData->GetY(k));
				tileWall->Draw();
			}
		}
	}

	playerSprite->Draw();

	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	App::Print(100, 100, "Sample Text");

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete playerSprite;
	delete tileWall;
	delete tree;
	delete gameFloor;
	//------------------------------------------------------------------------
}