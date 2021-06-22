#include "stdafx.h"
#include "StatusUpdateEngine.h"
#include "StatusObject.h"

CStatusUpdateEngine::CStatusUpdateEngine()
{
}

CStatusUpdateEngine::~CStatusUpdateEngine()
{
}

void CStatusUpdateEngine::Update(CKartObject* obj)
{
	double radian = obj->angle * (PI / 180);
	obj->posX += obj->vel * sin(radian);// *TIME_QUANTUM;
	obj->posY += obj->vel * cos(radian);// *TIME_QUANTUM;

	CStatusObject::playerAngle = obj->angle;
	CStatusObject::playerPosX = obj->posX;
	CStatusObject::playerPosY = obj->posY;
}

