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
		//obj->vel -= 0.01 * obj->vel;
		obj->isDrift = false;
	}

	if (obj->isBoost)//게임 시간에서 부스트 시작 시점과 -> 종료 시점 기록 -> 3초 차이를 GettickCount 3000
	{
		//datetime start = now;
		//end = now;
		obj->boostTime++;
		if (obj->boostTime > 300) {
			obj->isBoost = false;
			obj->boostTime = 0;
		}
	}

	CStatusObject::playerAngle = obj->angle;
	CStatusObject::playerPosX = obj->pos.X;
	CStatusObject::playerPosY = obj->pos.Y;
}

