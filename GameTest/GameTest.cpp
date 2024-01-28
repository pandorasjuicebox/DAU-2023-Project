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
CSimpleSprite* tileWall;
CSimpleSprite* borderDecor;
CSimpleSprite* gameFloor;

Player* playerObject;
BackgroundData* bgData;
MobHandler* mobHandler;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	bgData = new BackgroundData();
	mobHandler = new MobHandler();

	float lowerInnerXOffset = 25;
	float lowerInnerYOffset = 20;
	float upperInnerXOffset = 25;
	float upperInnerYOffset = 10;
	float sideInnerXOffset = 20;
	float gameFloorXOffset = 20;

	//The Player ---------------
	//positioned at the center
	playerObject = new Player(CreateSprite(".\\TestData\\player_general_movement.png", 6, 6), bgData->GetX(bgData->GetSize() / 2), bgData->GetY(bgData->GetSize() / 2));
	playerSprite = playerObject->GetPlayerSprite();

	//Border Tiles --------------
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\stone2_dark3.png", 1, 1), 1.5f, "dark_stone");
	tileWall = bgData->GetBorderSprite("dark_stone");

	//Decor Tiles --------------
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\tree.png", 1, 1), 1.0f, "tree");
	borderDecor = bgData->GetDecorSprite("tree");

	//Floor Tiles ---------------
	bgData->AddFloorSprite(CreateSprite(".\\TestData\\normal_grass.png", 1, 1), 2.0f, "normal_grass");
	gameFloor = bgData->GetFloorSprite("normal_grass");

	//Enemy Mobs ----------------
	mobHandler->AddMobSprite("docile_skeleton", 1, (1.0f / 20.0f), 2.0f, CreateSprite(".\\TestData\\docile_skeleton.png", 6, 1));
	mobHandler->AnimateMobUnit("docile_skeleton", { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 });

	//---------------------------


	//Set up outer borders --------
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Upper Wall Border
			if (i == 30 || i == 31 || k == 24 || k == 23) { bgData->AddOuterBorderLocation(bgData->GetX(i), bgData->GetY(k)); }
		}
	}
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Wall border (Lower and Sides)
			if (i == 0 || i == 1 || k == 0 || k == 1) { bgData->AddOuterBorderLocation(bgData->GetX(i), bgData->GetY(k)); }
		}
	}
	// ----------------------------
	
	//Set up inner border ---------
	//Upper Border Trees
	for (int i = 0; i < 32; i++) {
		for (int k = 0; k < 25; k++) {
			if ((i > 1) && (i < 22) && (k == 21)) {
				bgData->AddInnerBorderLocation((bgData->GetX(i) + upperInnerXOffset), (bgData->GetY(k) + upperInnerYOffset));
				upperInnerXOffset = upperInnerXOffset + ((borderDecor->GetWidth() / 4));
			}
		}
	}
	//Side Border Trees
	for (int i = 32; i > 1; i--) {
		for (int k = 21; k > 2; k--) {
			if (((i == 2) || (i == 28)) && ((k >= 2) || (k <= 10))) {
				bgData->AddInnerBorderLocation((bgData->GetX(i) + sideInnerXOffset), (bgData->GetY(k)));
			}
		}
	}
	//Lower Border Trees and Lower + Side Wall Borders
	for (int i = 0; i < 32; i++) { //column
		for (int k = 0; k < 25; k++) { //row
			//Lower Border Trees
			if ((i > 1) && (i < 22) && (k == 2)) {
				bgData->AddInnerBorderLocation(bgData->GetX(i) + lowerInnerXOffset, bgData->GetY(k) + lowerInnerYOffset );
				lowerInnerXOffset = lowerInnerXOffset + (borderDecor->GetWidth() / 4);
			}
		}
	}
	//-----------------------------

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

	for (int i = 0; i < bgData->getOuterBorderSize(); i++) {
		float xVal = bgData->GetOuterBorderLocation(i).x;
		float yVal = bgData->GetOuterBorderLocation(i).y;
		tileWall->SetPosition(xVal,yVal);
		tileWall->Draw();
	}

	for (int i = 0; i < bgData->getInnerBorderSize(); i++) {
		float xVal = bgData->GetInnerBorderLocation(i).x;
		float yVal = bgData->GetInnerBorderLocation(i).y;
		borderDecor->SetPosition(xVal, yVal);
		borderDecor->Draw();
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
	delete borderDecor;
	delete gameFloor;
	//------------------------------------------------------------------------
}