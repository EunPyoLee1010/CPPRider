#pragma once
#include "GameFramework.h"

struct Camera
{
	//CVECTOR objVector;
	CVECTOR centerPosition;
	double angle;
	std::string name;
	Camera() :
		angle(0),
		//objVector(0, 0),
		centerPosition(500 * 0.5, 500 * 0.5),
		name("")
	{}
};