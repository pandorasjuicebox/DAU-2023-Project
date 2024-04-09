//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
#include <vector>
#include <string>
#include <Windows.h>
#include <WinUser.h>
#include <ctime>
//------------------------------------------------------------------------
#include "app\app.h"
#include "Definitions.h"
#include "GameObject.h"
#include "MobHandler.h"
#include "PlayerState.h"
#include "GameTestHelper.h"
using namespace App;
using namespace std;

//------------------------------------------------------------------------
CSimpleSprite* playerSprite;
CSimpleSprite* tileWall;
CSimpleSprite* borderDecor;
CSimpleSprite* gameFloor;
CSimpleSprite* weaponSprite;

CSimpleSprite* scoreBoard;
CSimpleSprite* healthBar;
MedItems* medKit;
MedItems* jumboKit;
LifeItems* lifeVial;
CSimpleSprite* personalBest;
CSimpleSprite* lifeBar;
CSimpleSprite* secretLevelPopUp;
CSimpleSprite* darkOverlay;
CSimpleSprite* openerPopUp;
CSimpleSprite* gameOverPopup;
CSimpleSprite* buttonUnpress;
CSimpleSprite* buttonPress;

Player* playerObject;
PlayerState* playerState;
BackgroundData* bgData;
GameTestHelper* gtHelper;

vector<MobUnit*>units;
vector<CSimpleSprite*>healthBlocks;
vector<CSimpleSprite*>livesSprites;

int directionList[4] = { NORTH, SOUTH, WEST, EAST };

const int columns = NUM_COLUMNS;
const int rows = NUM_ROWS;

//int scoreCounter = 0;

string scoreText = "Current Score: ";
string personalBestText = "Personal Best: ";
int numUnits = NUM_STARTING_UNITS;
int bodyCount;
int counter = 0;
int pageNumber = 0;


//Game States
bool preGame = true;
bool secretLevel = false;
bool gameOver = false;

bool keyPressState = false;


//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	srand(time(NULL));
	bgData = new BackgroundData();
	
	float lowerInnerXOffset = 25;
	float lowerInnerYOffset = 20;
	float upperInnerXOffset = 25;
	float upperInnerYOffset = 10;
	float sideInnerXOffset = 25;
	float gameFloorXOffset = 20;

	//Weapon -------------------
	//playerWeapon = new Weapon(bgData, 100000, CreateSprite(".\\TestData\\bullet.png", 1, 1));
	//weaponSprite = playerWeapon->GetWeaponSprite();

	//The Player ---------------
	//positioned at the center
	playerObject = new Player(CreateSprite(".\\TestData\\player_full_sheet.png", 6, 10), bgData->GetX(bgData->GetSize() / 2), bgData->GetY(bgData->GetSize() / 2), bgData);
	playerSprite = playerObject->GetObjectSprite();
	
	playerState = new PlayerState();


	//Border Tiles --------------
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\brown_tile.png", 1, 1), 1.0f, "brown_stone");
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\pink_tile.png", 1, 1), 1.0f, "pink_stone");
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\murky_tile.png", 1, 1), 1.0f, "murky_stone");
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\neon_tile.png", 1, 1), 1.0f, "neon_stone");
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\rust_tile.png", 1, 1), 1.0f, "rust_stone");
	bgData->AddBorderSprite(CreateSprite(".\\TestData\\swamp_tile.png", 1, 1), 1.0f, "swamp_stone");
	tileWall = bgData->GetBorderSprite("brown_stone");

	//Decor Tiles --------------
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\tree.png", 1, 1), 1.2f, "tree");
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\blue_torch.png", 3, 1), 2.0f, "blue_torch");
	bgData->GetDecorSprite("blue_torch")->CreateAnimation(ANIM_TORCH,(1.0f/5.0f),{0,1,2});
	bgData->GetDecorSprite("blue_torch")->SetAnimation(ANIM_TORCH);
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\bush.png", 1, 1), 1.5f, "bush");
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\red_tree.png", 1, 1), 1.2f, "red_tree");
	bgData->AddDecorSprite(CreateSprite(".\\TestData\\rock.png", 1, 1), 1.2f, "rock");



	borderDecor = bgData->GetDecorSprite("tree");

	//Floor Tiles ---------------
	bgData->AddFloorSprite(CreateSprite(".\\TestData\\normal_grass.png", 1, 1), 2.0f, "normal_grass");
	bgData->AddFloorSprite(CreateSprite(".\\TestData\\cobble_floor.png", 1, 1), 1.0f, "cobble");
	bgData->AddFloorSprite(CreateSprite(".\\TestData\\dirt_floor.png", 1, 1), 1.0f, "dirt");
	gameFloor = bgData->GetFloorSprite("normal_grass");

	//UI stuff ------------------
	scoreBoard = CreateSprite(".\\TestData\\scoreboard_wpaper.png", 1, 1);
	scoreBoard->SetScale(1.8f);
	scoreBoard->SetPosition(170, 105);

	healthBar = CreateSprite(".\\TestData\\healthbar.png", 1, 1);
	healthBar->SetScale(1.4f);
	healthBar->SetPosition(110, 630);

	personalBest = CreateSprite(".\\TestData\\personal_best.png", 1, 1);
	personalBest->SetScale(1.8f);
	personalBest->SetPosition(850, 680);

	lifeBar = CreateSprite(".\\TestData\\life_bar.png", 1, 1);
	lifeBar->SetScale(1.8f);
	lifeBar->SetPosition(880, 620);

	darkOverlay = CreateSprite(".\\TestData\\dark_overlay.png", 1, 1);
	darkOverlay->SetScale(2.0f);

	openerPopUp = CreateSprite(".\\TestData\\opening_card.png", 1, 1);
	openerPopUp->SetScale(3.0f);
	openerPopUp->SetPosition((bgData->GetX(bgData->GetSize() / 2) + 5), (bgData->GetY(bgData->GetSize() / 2) - 100));

	gameOverPopup = CreateSprite(".\\TestData\\game_over.png", 1, 1);
	gameOverPopup->SetScale(3.0f);
	gameOverPopup->SetPosition((bgData->GetX(bgData->GetSize() / 2)+5), (bgData->GetY(bgData->GetSize() / 2)-100));

	buttonUnpress = CreateSprite(".\\TestData\\enter_unpressed.png", 1, 1);
	buttonUnpress->SetScale(2.0f);
	buttonUnpress->SetPosition((bgData->GetX(bgData->GetSize() / 2) + 5), (bgData->GetY(bgData->GetSize() / 2) - 180));

	buttonPress = CreateSprite(".\\TestData\\enter_pressed.png", 1, 1);
	buttonPress->SetScale(2.0f);
	buttonPress->SetPosition((bgData->GetX(bgData->GetSize() / 2) + 5), (bgData->GetY(bgData->GetSize() / 2) - 180));

	//Set up outer borders --------
	for (int i = 0; i < columns; i++) { 
		for (int k = 0; k < rows; k++) { 
			//Upper Wall Border
			if (i == 30 || i == 31 || k == 24 || k == 23) { bgData->AddOuterBorderLocation(bgData->GetX(i)+10, bgData->GetY(k)); }
		}
	}
	for (int i = 0; i < columns; i++) { 
		for (int k = 0; k < rows; k++) { //row
			//Wall border (Lower and Sides)
			if (i == 0 || i == 1 || k == 0 || k == 1) { bgData->AddOuterBorderLocation(bgData->GetX(i)+11, bgData->GetY(k)); }
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
			int iValue;

			if (borderDecor->GetScale() >= 2.0f) {
				iValue = 25;
			}
			else {
				iValue = 22;
			}
			if ((i > 1) && (i < iValue) && (k == 2)) {
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

	//Set up playable game floor
	for (int i = 4; i < columns - 4; i++) { // 32 - 3 = 29
		for (int k = 5; k < rows - 4; k++) { // 25 - 3 = 22
			playerObject->AddPlayerAreaCoord(bgData->GetX(i), bgData->GetY(k));
		}
	}

	bgData->CreateBorders();
	playerObject->CreateBorders();

	bodyCount = 0;

	units = gtHelper->GenerateMobs(10, bgData);
	healthBlocks = gtHelper->GenerateHealthBar(PLAYER_FULL_HEALTH, bgData);
	livesSprites = gtHelper->GenerateLives(PLAYER_LIVES_DEFAULT, bgData);

	//----------------------------

}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime){
	
		if (!playerObject->IsDead() && playerState->GetLives() > 0 && !gameOver && !preGame) {

			if (!secretLevel) {

				playerObject->Update(deltaTime);
				borderDecor->Update(deltaTime);


				if (bgData->isThereAMedKit() && playerObject->intersects(medKit)) {
					playerObject->GainHealth(medKit->GetHealth());
					bgData->SetMedKitStatus(false);
				}

				for (int i = 0; i < units.size(); i++) {
					units.at(i)->Update(deltaTime / 2, playerObject->GetXPos(), playerObject->GetYPos());

					if (!units.at(i)->IsDead()) {
						//Units keep their distance from each other
						if (i > 0 && i < numUnits - 1) {

							if (units.at(i)->intersects(units.at(i - 1)) || units.at(i)->intersects(units.at(i + 1))) {
								float xPos;
								float yPos;
								units.at(i)->GetObjectSprite()->GetPosition(xPos, yPos);
								units.at(i)->GetObjectSprite()->SetPosition(xPos - ((rand() % 2 + 1 - 1) + 1), yPos - ((rand() % 2 + 1 - 1) + 1));
							}
						}


						if ((IsKeyPressed(0x46)) && playerObject->intersects(units.at(i)) && playerObject->GetGoingDirection() == GOING_SOUTH) {
							units.at(i)->RemoveHealth(1);
						}
						if ((IsKeyPressed(0x46)) && playerObject->intersects(units.at(i)) && playerObject->GetGoingDirection() == GOING_NORTH) {
							units.at(i)->RemoveHealth(1);
						}
						if ((IsKeyPressed(0x46)) && playerObject->intersects(units.at(i)) && playerObject->GetGoingDirection() == GOING_WEST) {
							units.at(i)->RemoveHealth(1);
						}
						if ((IsKeyPressed(0x46)) && playerObject->intersects(units.at(i)) && playerObject->GetGoingDirection() == GOING_EAST) {
							units.at(i)->RemoveHealth(1);
						}

						if (units.at(i)->IsDead()) {
							playerState->AddScore(1);
							bodyCount++;
						}

						if (units.at(i)->intersects(playerObject)) {
							playerObject->RemoveHealth(0.5);
						}

					}


					if (playerObject->GetHealth() < PLAYER_FULL_HEALTH && !bgData->isThereAMedKit()) {
						float medKitX = ((rand() % (500 - 400 +1) + 400));
						float medKitY = ((rand() % (500 - 400  +1) + 400));
						medKit = new MedItems(CreateSprite(".\\TestData\\aid_kit.png", 1, 1), 2, 2.0f);
						medKit->GetObjectSprite()->SetPosition(medKitX, medKitY);
						bgData->SetMedKitStatus(true);

					}


					//Write the Update(deltaTime) code for the mobs, and put the loop in that class
					//Make a level class which handles the mobs

					//------------------------------------------------------------------------
					// Sample Sound.
					//------------------------------------------------------------------------
					if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
					{
						App::PlaySound(".\\TestData\\Test.wav");
					}
				}

				if (playerObject->IsDead()) {
					if (playerState->GetLives() > 0) {
						playerState->RemoveLife();
						playerObject->GainHealth(PLAYER_FULL_HEALTH);
					}
				}

				if (bodyCount == numUnits) {

					numUnits = ((rand() % (numUnits + 10) - 10 + 1) + 10);

					if (numUnits % 2 == 0 && !secretLevel) {
						tileWall = bgData->GetBorderSprite("pink_stone");

						jumboKit = new MedItems(CreateSprite(".\\TestData\\jumbo_aid_kit.png", 1, 1), 9, 1.5f);
						lifeVial = new LifeItems(CreateSprite(".\\TestData\\life_vial.png", 1, 1), 1, 1.0f);
						secretLevelPopUp = CreateSprite(".\\TestData\\secret_level_popup.png", 1, 1);
						secretLevelPopUp->SetScale(2.9f);

						borderDecor->SetAnimation(ANIM_TORCH);
						secretLevelPopUp->SetPosition((bgData->GetX(bgData->GetSize() / 2)), (bgData->GetY(bgData->GetSize() / 2)) - 100);
						jumboKit->GetObjectSprite()->SetPosition(510, 435);
						lifeVial->GetObjectSprite()->SetPosition(510, 355);
						secretLevel = true;
					}
					else {
						units.clear();
						units = gtHelper->GenerateMobs(numUnits, bgData);
						int borderSelect = (rand() % (5 - 0 ) + 0);
						int decorSelect = (rand() % (4 - 0) + 0);
						int floorSelect = (rand() %( 2 - 0 ) + 0);
						tileWall = gtHelper->GenerateBorderTiles(bgData, borderSelect);
						borderDecor = gtHelper->GenerateDecor(bgData, decorSelect);
						gameFloor = gtHelper->GenerateFloor(bgData, floorSelect);
					}

					bodyCount = 0;
				}
			}
			
			
			if (secretLevel) {

				//Pressed A: More Health
				if (IsKeyPressed(0x41)) {
					playerObject->GainHealth(jumboKit->GetHealth());
					secretLevel = false;
					tileWall = bgData->GetBorderSprite("brown_stone");
				}
				//Pressed B: More Life
				else if (IsKeyPressed(0x42)) {
					playerState->AddLife();
					secretLevel = false;
					tileWall = bgData->GetBorderSprite("brown_stone");
				}

				if (IsKeyPressed(0x41) || IsKeyPressed(0x42)) {
					units.clear();
					units = gtHelper->GenerateMobs(numUnits, bgData);
					int borderSelect = (rand() % (5 - 0 ) + 0);
					int decorSelect = (rand() % (4 - 0 ) + 0);
					int floorSelect = (rand() % (2 - 0 ) + 0);
					tileWall = gtHelper->GenerateBorderTiles(bgData, borderSelect);
					borderDecor = gtHelper->GenerateDecor(bgData, decorSelect);
					gameFloor = gtHelper->GenerateFloor(bgData, floorSelect);
					bodyCount = 0;
				}
			}
		}

		playerState->SetPersonalBest(playerState->GetScore());

		if (playerState->GetLives() <= 0) {
			gameOver = true;

			if (IsKeyPressed(VK_RETURN)) {
				playerState->ResetPlayerStats();
				playerObject->GainHealth(PLAYER_FULL_HEALTH);

				units.clear();
				units = gtHelper->GenerateMobs(numUnits, bgData);
				int borderSelect = (rand() % (5 - 0) + 0);
				int decorSelect = (rand() % (4 - 0) + 0);
				int floorSelect = (rand() % (2 - 0) + 0);
				tileWall = gtHelper->GenerateBorderTiles(bgData, borderSelect);
				borderDecor = gtHelper->GenerateDecor(bgData, decorSelect);
				gameFloor = gtHelper->GenerateFloor(bgData, floorSelect);

				bodyCount = 0;

				gameOver = false;
				
			}
		}
	
}


//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	//Draw the floor
	//vector<int>mapData;
	if (preGame) {
		App::Print(441, 600, "WHERE AM I?", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(440, 600, "WHERE AM I?", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(442, 600, "WHERE AM I?", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

		App::Print(350, 550, "You pick up a piece of paper by your feet.");
	
		App::Print(400, 500, "The handwriting is kinda messy...");

		App::Print(350, 450, "\"Before you insult my handwriting,", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(400, 430, "worry about yourself first.", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(370, 410, "You are not the first.", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

		App::Print(350, 390, "But before I leave this place,", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(390, 370, "let me give you some advice:", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		
		App::Print(440, 320, "The game ends at 100.\"", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

		App::Print(350, 280, "You looked at the sword beside the note,");
		App::Print(350, 260, "and as soon as you picked it up, a chorus of");
		App::Print(420, 230, "low grumbles approach.");
		
		if (IsKeyPressed(VK_RETURN)) {
			buttonPress->SetPosition(515, 150);
			buttonPress->Draw();
			preGame = false;
		}
		else {
			buttonUnpress->SetPosition(515, 150);
			buttonUnpress->Draw();
		}
		
		App::Print(485, 150, "[ENTER]");
	}
	else if (gameOver) {

		double gameArea = bgData->GetInnerBorderSize() + bgData->GetOuterBorderSize() + bgData->GetFloorSize();

		for (int i = 0; i < gameArea; i++) {

			float xVal;
			float yVal;

			if (i < bgData->GetInnerBorderSize()) {
				xVal = bgData->GetInnerBorderLocation(i).x;
				yVal = bgData->GetInnerBorderLocation(i).y;
				darkOverlay->SetPosition(xVal, yVal);
				darkOverlay->Draw();
			}

			if (i < bgData->GetOuterBorderSize()) {
				xVal = bgData->GetOuterBorderLocation(i).x;
				yVal = bgData->GetOuterBorderLocation(i).y;
				darkOverlay->SetPosition(xVal, yVal);
				darkOverlay->Draw();
			}

			if (i < bgData->GetFloorSize()) {
				xVal = bgData->GetFloorLocation(i).x;
				yVal = bgData->GetFloorLocation(i).y;
				darkOverlay->SetPosition(xVal, yVal);
				darkOverlay->Draw();
			}
		}

		gameOverPopup->Draw();
		App::Print(441, 420, "GAME  OVER",1.0f,1.0f,1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(440, 420, "GAME  OVER", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		App::Print(442, 420, "GAME  OVER", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

		App::Print(440, 350, "[ENTER] Try Again");
	}

	else if (!secretLevel) {

		for (int i = 0; i < bgData->GetFloorSize(); i++) {
			int number = ((rand() % 1 + 1 - 0) + 0);
			float xVal = bgData->GetFloorLocation(i).x;
			float yVal = bgData->GetFloorLocation(i).y;
			gameFloor->SetPosition(xVal, yVal);
			gameFloor->Draw();
		}

		for (int i = 0; i < units.size(); i++) {
			if (!units.at(i)->IsDead()) {
				units.at(i)->GetObjectSprite()->Draw();
			}
		}

		if (bgData->isThereAMedKit()) {
			medKit->GetObjectSprite()->Draw();
		}

		if (!playerObject->IsDead()) {
			playerSprite->Draw();
		}


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

		//Draw the inner bordering decor
		for (int i = 0; i < bgData->GetInnerBorderSize(); i++) {
			float xVal = bgData->GetInnerBorderLocation(i).x;
			float yVal = bgData->GetInnerBorderLocation(i).y;
			borderDecor->SetPosition(xVal, yVal);
			borderDecor->Draw();
		}


		//Draw the outer border
		for (int i = 0; i < bgData->GetOuterBorderSize(); i++) {
			float xVal = bgData->GetOuterBorderLocation(i).x;
			float yVal = bgData->GetOuterBorderLocation(i).y;
			tileWall->SetPosition(xVal, yVal);
			tileWall->Draw();
		}

		scoreBoard->Draw();
		string score = to_string(playerState->GetScore());
		App::Print(100, 100, (scoreText + score).c_str(), 0, 0, 0);

		healthBar->Draw();
		personalBest->Draw();
		lifeBar->Draw();

		string newPersonalBest = to_string(playerState->GetPesonalBest());
		App::Print(780, 685, personalBestText.c_str(), 0, 0, 0);
		App::Print(790, 665, newPersonalBest.c_str(), 0, 0, 0);

		for (int i = 0; i < playerObject->GetHealth(); i++) {
			healthBlocks.at(i)->Draw();
		}

		for (int i = 0; i < playerState->GetLives(); i++) {
			livesSprites.at(i)->Draw();
		}

	}
	else {

		secretLevelPopUp->Draw();
		jumboKit->GetObjectSprite()->Draw();
		lifeVial->GetObjectSprite()->Draw();
		App::Print(440, 500, "YOU CAN ONLY");
		App::Print(465, 470, "PICK ONE:");
		App::Print(425, 400, "Press A: More Health");
		App::Print(440, 310, "Press B: New Life");
	}

	//Draw the player
	//playerSprite->Draw();

	

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
	delete weaponSprite;

	delete scoreBoard;
	delete healthBar;
	delete medKit;
	delete personalBest;

	delete playerObject;
	delete playerState;
	delete bgData;
	delete gtHelper;
	//------------------------------------------------------------------------
}