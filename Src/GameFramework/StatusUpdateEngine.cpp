#include "stdafx.h"
#include "StatusUpdateEngine.h"
#include "StatusObject.h"
#include "../CPPRider/MainGameLoop.h"

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
		if(CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)] == 0)
			CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)] = 2;

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
	if (CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)] > 2)
	{
		//그냥 1 지나가면 1로 갱신 그보다 숫자가 작다면 갱신하지않기 갱신이 4까지 됐으면 lap을 1 올리고 lapcount 0으로 초기화
		if (CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)] - obj->lapCount == 1)
		{
			obj->lapCount++;
		}
		if (obj->lapCount == 6) { obj->lap++; obj->lapCount = 2; }
		if (obj->lap > CMapObject::laps) CMainGameLoop::loopFlag = false;
		
		printf("obj's lapCount : %d, map: %d\n", obj->lapCount, CMapObject::mapContainer[int(obj->pos.Y)][int(obj->pos.X)]);
	}

	CStatusObject::playerAngle = obj->angle;
	CStatusObject::playerPosX = obj->pos.X;
	CStatusObject::playerPosY = obj->pos.Y;
	CStatusObject::playerLaps = obj->lap;
}

