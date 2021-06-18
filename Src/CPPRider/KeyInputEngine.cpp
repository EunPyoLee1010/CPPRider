#include "stdafx.h"
#include "KeyInputEngine.h"

int CKeyInputEngine::Query()
{
	int nCount = 0;
	extern CKartObject myKart;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		myKart.SteerWheel(-1);
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		myKart.SteerWheel(1);
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		myKart.ControlSpeed(0.5);
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		myKart.ControlSpeed(-0.5);
	}

	return nCount;
}

CKeyInputEngine::CKeyInputEngine()
{
}

CKeyInputEngine::~CKeyInputEngine()
{
}
