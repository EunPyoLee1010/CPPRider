#include "stdafx.h"
#include "ObjectSuper.h"

CObjectSuper::CObjectSuper()
{
}

CObjectSuper::~CObjectSuper()
{
}

void CObjectSuper::Draw()
{
}

void CObjectSuper::Move(double vel, int angle)
{
	double radian = angle * PI / 180;
	this->posX += vel * cos(radian) * TIME_QUANTUM;
	this->posY += vel * sin(radian) * TIME_QUANTUM;
}
