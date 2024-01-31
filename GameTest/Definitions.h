#pragma once
#include "stdafx.h"
#include "App\app.h"
#include <windows.h>
#include <math.h>  
#include <vector>
using namespace App;

enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
	ANIM_ATTACK_NORTH,
	ANIM_ATTACK_WEST,
	ANIM_ATTACK_EAST,
	ANIM_ATTACK_SOUTH,
	NO_ATTACK,
	UNIT_DEATH
};

struct Coord {
	float x;
	float y;
};

