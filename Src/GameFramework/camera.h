#pragma once
#include "GameFramework.h"

struct Camera
{
	CVECTOR centerPosition;
	double angle;
	std::string name;
	Camera() :
		angle(0),
		centerPosition(500 * 0.5, 500 * 0.5),
		name("")
	{}
};