#pragma once
#include "ObjectSuper.h"

class CKartObject : public CObjectSuper
{
public:
	CKartObject();
	~CKartObject();

	virtual void Draw();

	void SteerWheel(int angle);
	void ControlSpeed(double velocity);

	int angle;
	double vel;

private:

	double maxVel;
};

