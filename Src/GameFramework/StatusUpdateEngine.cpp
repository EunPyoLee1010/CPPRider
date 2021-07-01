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
	
	CMapObject::mapContainer[int(obj->posY)][int(obj->posX)] = 2;

	obj->posX += obj->vel * sin(radian);
	obj->posY += obj->vel * cos(radian);

	CStatusObject::playerAngle = obj->angle;
	CStatusObject::playerPosX = obj->posX;
	CStatusObject::playerPosY = obj->posY;
}

