#pragma once

#include "HitBox.h"

class GameObject {
public: 
	void SetCrosssable(bool state); //false by default; toggle if the player can walk on this object
	void SetObjVisible(bool state);
	void SetObjHitbox(); //Sets or Updates the hitbox based on location in the world
	void SetMoveableObj(bool state);
	
	bool* IsMoveableObj(); //return isMoveable value
	bool* IsActiveObj(); 
	bool* IsVisibleObj();

	//void SetObjHealth(int healthTotal);
	//void ReduceObjHealth(int lostHealth);



private:
	HitBox objHitBox; //each object has its own HitBox
	//int objHealth; note: still thinking about this variable
	bool isMoveable = false;
	//TODO: make a HitBox object
	bool isActive = true; //is it interactable or not
	bool isVisible = true; //is it on the map right now
	bool isCrossable = false; //default
	const char* spriteFileName; 
	//default is that it's only one square/one tile unit
	unsigned int nColumns = 0; 
	unsigned int nRows = 0;
	



};
