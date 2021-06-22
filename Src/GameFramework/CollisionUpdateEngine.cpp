#include "stdafx.h"
#include "CollisionUpdateEngine.h"

CCollisionUpdateEngine::CCollisionUpdateEngine()
{
}

CCollisionUpdateEngine::~CCollisionUpdateEngine()
{
}

void CCollisionUpdateEngine::Update(CKartObject* obj)
{
	double radian = obj->angle * PI / 180;
	int moveX = obj->posX + obj->vel * cos(radian) * TIME_QUANTUM;
	int moveY = obj->posY + obj->vel * sin(radian) * TIME_QUANTUM;
	if (moveX < 0)
	{
		obj->posX = 1;
		obj->vel *= -0.1;
	}
	if (moveX > 1000)
	{
		obj->posX = 999;
		obj->vel *= -0.1;
	}
	if (moveY < 0)
	{
		obj->posY = 1;
		obj->vel *= -0.1;
	}
	if (moveY > 1000)
	{
		obj->posY = 999;
		obj->vel *= -0.1;
	}
}
