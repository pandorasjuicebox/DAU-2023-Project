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
#include "GameObject.h"
#include "PlayerState.h"
using namespace App;
using namespace std;
//------------------------------------------------------------------------

CSimpleSprite* playerSprite;
CSimpleSprite* tileWall;
CSimpleSprite* borderDecor;
CSimpleSprite* gameFloor;
CSimpleSprite* weaponSprite;

Player* playerObject;
PlayerState* playerState;
BackgroundData* bgData;
MobHandler* mobHandler;
MobUnit* mobUnits;

const int columns = 32;
const int rows = 25;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	bgData = new BackgroundData();
	mobHandler = new MobHandler();
	mobUnits = new MobUnit(mobHandler, bgData);

	float lowerInnerXOffset = 25;
	float lowerInnerYOffset = 20;
	float upperInnerXOffset = 25;
	float upperInnerYOffset = 10;
	float sideInnerXOffset = 20;
	float gameFloorXOffset = 20;

	//Weapon -------------------
	//playerWeapon = new Weapon(bgData, 100000, CreateSprite(".\\TestData\\bullet.png", 1, 1));
	//weaponSprite = playerWeapon->GetWeaponSprite();

	//The Player ---------------
	//positioned at the center
	playerObject = new Player(CreateSprite(".\\TestData\\player_full_sheet.png", 6, 10), bgData->GetX(bgData->GetSize() / 2), bgData->GetY(bgData->GetSize() / 2));
	playerSprite = playerObject->GetPlayerSprite();
	
	playerState = new PlayerState();


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
	mobHandler->AddMobSprite("docile_skeleton", 2, (1.0f / 20.0f), 1.5f, CreateSprite(".\\TestData\\docile_skeleton_sheet.png", 6, 2));
	mobHandler->AnimateMobUnit("docile_skeleton", { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 }, { 0,1,2,3,4,5 });
	mobHandler->AnimateMobDeath("docile_skeleton", { 6,7,8,9,10 });
	//mobHandler->RemoveSprite("docile_skeleton", { 11 });
	//---------------------------


	//Set up outer borders --------
	for (int i = 0; i < columns; i++) { 
		for (int k = 0; k < rows; k++) { 
			//Upper Wall Border
			if (i == 30 || i == 31 || k == 24 || k == 23) { bgData->AddOuterBorderLocation(bgData->GetX(i), bgData->GetY(k)); }
		}
	}
	for (int i = 0; i < columns; i++) { 
		for (int k = 0; k < rows; k++) { //row
			//Wall border (Lower and Sides)
			if (i == 0 || i == 1 || k == 0 || k == 1) { bgData->AddOuterBorderLocation(bgData->GetX(i), bgData->GetY(k)); }
		}
	}
	// ----------------------------
	
	//Set up inner border ---------
	//Upper Border Decor
	for (int i = 0; i < columns; i++) {
		for (int k = 0; k < rows; k++) {
			if ((i > 1) && (i < 22) && (k == 21)) {
				bgData->AddInnerBorderLocation((bgData->GetX(i) + upperInnerXOffset), (bgData->GetY(k) + upperInnerYOffset));
				upperInnerXOffset = upperInnerXOffset + ((borderDecor->GetWidth() / 4));
			}
		}
	}
	//Side Border Decor
	for (int i = columns; i > 1; i--) {
		for (int k = 21; k > 2; k--) {
			if (((i == 2) || (i == 28)) && ((k >= 2) || (k <= 10))) {
				bgData->AddInnerBorderLocation((bgData->GetX(i) + sideInnerXOffset), (bgData->GetY(k)));
			}
		}
	}
	//Lower Border Decor
	for (int i = 0; i < columns; i++) { 
		for (int k = 0; k < rows; k++) { 
			//Lower Border Trees
			if ((i > 1) && (i < 22) && (k == 2)) {
				bgData->AddInnerBorderLocation(bgData->GetX(i) + lowerInnerXOffset, bgData->GetY(k) + lowerInnerYOffset );
				lowerInnerXOffset = lowerInnerXOffset + (borderDecor->GetWidth() / 4);
			}
		}
	}
	//-----------------------------

	//Set up floor
	for (int i = 3; i < columns-3; i++) { // 32 - 3 = 29
		for (int k = 0; k < rows-3; k++) { // 25 - 3 = 22
			bgData->AddFloorLocation(bgData->GetX(i), bgData->GetY(k));
		}
	}

	bgData->CreateBorders();
	mobUnits->AddMobUnit("docile_skeleton");
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	playerObject->Update(deltaTime);
	mobUnits->Update(deltaTime, playerObject->GetXPos(), playerObject->GetYPos());
	playerObject->checkCollision(mobUnits);

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
	//Draw the floor
	for (int i = 0; i < bgData->GetFloorSize(); i++) {
		float xVal = bgData->GetFloorLocation(i).x;
		float yVal = bgData->GetFloorLocation(i).y;
		gameFloor->SetPosition(xVal, yVal);
		gameFloor->Draw();
	}
	//Draw the outer border
	for (int i = 0; i < bgData->GetOuterBorderSize(); i++) {
		float xVal = bgData->GetOuterBorderLocation(i).x;
		float yVal = bgData->GetOuterBorderLocation(i).y;
		tileWall->SetPosition(xVal,yVal);
		tileWall->Draw();
	}
	//Draw the inner bordering decor
	for (int i = 0; i < bgData->GetInnerBorderSize(); i++) {
		float xVal = bgData->GetInnerBorderLocation(i).x;
		float yVal = bgData->GetInnerBorderLocation(i).y;
		borderDecor->SetPosition(xVal, yVal);
		borderDecor->Draw();
	}

	if (!mobUnits->isDead()) {
		mobUnits->GetUnitSprite()->Draw();
	}

	//Draw the player
	playerSprite->Draw();

	if (IsKeyPressed(0x46)) {
		if (playerObject->GetGoingDirection() == GOING_EAST) {
			//Facing west, moving east
			playerSprite->SetAnimation(ANIM_ATTACK_WEST);
		}
		if (playerObject->GetGoingDirection() == GOING_WEST) {
			//Facing east, moving west
			playerSprite->SetAnimation(ANIM_ATTACK_EAST);
		}
		if (playerObject->GetGoingDirection() == GOING_NORTH) {
			//Facing south, walking north
			playerSprite->SetAnimation(ANIM_ATTACK_SOUTH);
		}
		if (playerObject->GetGoingDirection() == GOING_SOUTH) {
			//Facing north, walking south
			playerSprite->SetAnimation(ANIM_ATTACK_NORTH);
		}
	}
	else { //Reset actions
		if (playerObject->GetGoingDirection() == GOING_EAST) {
			//Facing west, moving east
			playerSprite->SetAnimation(ANIM_RIGHT);
		}
		if (playerObject->GetGoingDirection() == GOING_WEST) {
			//Facing east, moving west
			playerSprite->SetAnimation(ANIM_LEFT);
		}
		if (playerObject->GetGoingDirection() == GOING_NORTH) {
			//Facing south, walking north
			playerSprite->SetAnimation(ANIM_BACKWARDS);
		}
		if (playerObject->GetGoingDirection() == GOING_SOUTH) {
			//Facing north, walking south
			playerSprite->SetAnimation(ANIM_FORWARDS);
		}
	}



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