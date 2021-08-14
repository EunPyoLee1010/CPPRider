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

	if (obj->isBoost)//���� �ð����� �ν�Ʈ ���� ������ -> ���� ���� ��� -> 3�� ���̸� GettickCount 3000
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
		//�׳� 1 �������� 1�� ���� �׺��� ���ڰ� �۴ٸ� ���������ʱ� ������ 4���� ������ lap�� 1 �ø��� lapcount 0���� �ʱ�ȭ
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

