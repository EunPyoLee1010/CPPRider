#include "stdafx.h"
#include "KeyInputEngine.h"

int CKeyInputEngine::Query()
{
	int nCount = 0;
	extern CKartObject myKart;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		myKart.angle -= 0.5 * (myKart.vel / myKart.maxVel);

		if (myKart.angle >= 360)
			myKart.angle -= 360;
		if (myKart.angle <= -360)
			myKart.angle += 360;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		myKart.angle += 0.5 *(myKart.vel / myKart.maxVel);

		if (myKart.angle >= 360)
			myKart.angle -= 360;
		if (myKart.angle <= -360)
			myKart.angle += 360;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		myKart.vel += myKart.acc * (myKart.maxVel - myKart.vel) * TIME_QUANTUM;
		if(myKart.vel < 0)
			myKart.vel += myKart.acc * (myKart.maxVel - myKart.vel) * TIME_QUANTUM;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		myKart.vel += -1 * myKart.acc * (myKart.maxVel - myKart.vel) * TIME_QUANTUM;
		if(myKart.vel > 0)
			myKart.vel += -1 * myKart.acc * (myKart.maxVel - myKart.vel) * TIME_QUANTUM;
	}

	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			myKart.angle -= 1.2 * (myKart.vel / myKart.maxVel);

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			myKart.angle += 1.2 * (myKart.vel / myKart.maxVel);

		myKart.boostGauge += abs(0.5 *(myKart.vel / myKart.maxVel) * (sin(myKart.angle * PI / 180)));
		if (myKart.boostGauge >= 100)
		{
			myKart.boosterCount >= 2? myKart.boosterCount : myKart.boosterCount++;
			myKart.boostGauge = 0;
		}

		myKart.vel *= 0.995;

		myKart.isDrift = true;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
	{
		if (!myKart.boosterCount || myKart.isBoost)
			return 0;
		myKart.vel += 2 * myKart.maxVel;
		myKart.boosterCount--;
		myKart.isBoost = true;
	}

	return nCount;
}

CKeyInputEngine::CKeyInputEngine()
{
}

CKeyInputEngine::~CKeyInputEngine()
{
}
