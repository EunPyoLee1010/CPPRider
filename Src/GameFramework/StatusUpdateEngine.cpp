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
	
	obj->pos.X += obj->vel * sin(radian);
	obj->pos.Y += obj->vel * cos(radian);

	if (obj->isDrift) 
	{
		CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)] = 2;
		obj->vel -= 0.01 * obj->vel;
		obj->isDrift = false;
	}

	CStatusObject::playerAngle = obj->angle;
	CStatusObject::playerPosX = obj->pos.X;
	CStatusObject::playerPosY = obj->pos.Y;
}

