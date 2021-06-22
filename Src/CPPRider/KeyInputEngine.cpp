#include "stdafx.h"
#include "KeyInputEngine.h"

int CKeyInputEngine::Query()
{
	int nCount = 0;
	extern CKartObject myKart;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		myKart.angle -= 0.5 *(myKart.vel / myKart.maxVel);
		if(myKart.angle > 370)
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		myKart.angle += 0.5 *(myKart.vel / myKart.maxVel);
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		double velocity = myKart.acc * (myKart.maxVel - myKart.vel) * TIME_QUANTUM;
		if (velocity >= myKart.maxVel)
			myKart.vel += myKart.maxVel * TIME_QUANTUM;
		if (velocity < myKart.maxVel)
			myKart.vel += velocity;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		double velocity = -1 * myKart.acc * (myKart.maxVel - myKart.vel) * TIME_QUANTUM;
		if (velocity <= -1 * myKart.maxVel)
			myKart.vel += myKart.maxVel * TIME_QUANTUM;
		if (velocity > -1 * myKart.maxVel)
			myKart.vel += velocity;
	}

	return nCount;
}

CKeyInputEngine::CKeyInputEngine()
{
}

CKeyInputEngine::~CKeyInputEngine()
{
}
