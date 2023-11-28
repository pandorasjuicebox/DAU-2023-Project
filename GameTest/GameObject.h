#pragma once

#include "HitBox.h"

class GameObject {
public: 
	



private:
	HitBox objectHitBox; //each object has its own HitBox
	//int health; note: still thinking about this variable
	bool isObstacle = false; //default
	//TODO: make a HitBox object
	bool isActiveObject = true; //is it interactable or not
	bool isVisibleObject = true; //is it on the map right now
	const char* spriteFileName; 

	//default is that it's only one square/one tile unit
	unsigned int nColumns = 0; 
	unsigned int nRows = 0;


};
