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
	
	CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)] = 2;

	obj->pos.X += obj->vel * sin(radian);
	obj->pos.Y += obj->vel * cos(radian);
	

	CStatusObject::playerAngle = obj->angle;
	CStatusObject::playerPosX = obj->pos.X;
	CStatusObject::playerPosY = obj->pos.Y;
}

