#pragma once
#include "stdafx.h"
#include "App\app.h"
#include <windows.h>
#include <math.h>  
#include <vector>
using namespace App;

enum
{
	ANIM_FORWARDS, ANIM_BACKWARDS, ANIM_LEFT, ANIM_RIGHT,
	ANIM_ATTACK_NORTH, ANIM_ATTACK_WEST, ANIM_ATTACK_EAST, ANIM_ATTACK_SOUTH,
	NO_ATTACK,
	UNIT_DEATH,
	GOING_NORTH, GOING_SOUTH, GOING_WEST, GOING_EAST,
	MOB_UNIT,
	NORTH, SOUTH, EAST, WEST,
	ANIM_TORCH
};

enum constants {
	NUM_COLUMNS = 32, NUM_ROWS = 25,
	PLAYER_FULL_HEALTH = 9,
	PLAYER_HALF_HEALTH = 4, //approx halfway
	PLAYER_NO_HEALTH = 0, 
	NUM_STARTING_UNITS = 10,
	PLAYER_LIVES_DEFAULT = 3
};

struct Coord {
	float x;
	float y;
};

