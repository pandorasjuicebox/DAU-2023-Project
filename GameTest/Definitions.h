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
	ANIM_IDLE,
};

struct Coord {
	float x;
	float y;
};

