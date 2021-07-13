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
			myKart.angle -= 0.5 * (myKart.vel / myKart.maxVel);

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			myKart.angle += 0.5 * (myKart.vel / myKart.maxVel);

		myKart.vel *= 1.01;

		myKart.isDrift = true;
	}

	return nCount;
}

CKeyInputEngine::CKeyInputEngine()
{
}

CKeyInputEngine::~CKeyInputEngine()
{
}
