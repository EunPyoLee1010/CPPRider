#include "stdafx.h"
#include "KartObject.h"

CKartObject::CKartObject() :
	angle(0),
	vel(0),
	maxVel(2)
{
}

CKartObject::~CKartObject()
{
}

void CKartObject::Draw()
{
}

void CKartObject::SteerWheel(int angle)
{
	this->angle += angle;

	if (this->angle >= 360)
		this->angle -= 360;
	if (this->angle <= -360)
		this->angle += 360;
}

void CKartObject::ControlSpeed(double velocity)
{
	this->vel += velocity;

	if (vel >= this->maxVel)
		vel = maxVel;
	if (vel <= -1 * this->maxVel)
		vel = -1 * maxVel;
}

int CKartObject::getAngle()
{
	return angle;
}

double CKartObject::getVel()
{
	return vel;
}
