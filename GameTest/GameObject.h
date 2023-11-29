#pragma once

#include "HitBox.h"

class GameObject {
public: 
	void SetMoveable(); //false by default
	bool IsMoveable(); //return isMoveable value
	//void SetObjHealth(int healthTotal);
	//void ReduceObjHealth(int lostHealth);



private:
	HitBox objHitBox; //each object has its own HitBox
	//int objHealth; note: still thinking about this variable
	bool isObstacle = false; //default
	//TODO: make a HitBox object
	bool isActiveObject = true; //is it interactable or not
	bool isVisibleObject = true; //is it on the map right now
	bool isMoveable = false; //default
	const char* spriteFileName; 

	//default is that it's only one square/one tile unit
	unsigned int nColumns = 0; 
	unsigned int nRows = 0;



};
