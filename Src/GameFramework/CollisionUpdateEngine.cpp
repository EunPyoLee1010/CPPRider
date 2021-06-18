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
	if (moveX < 0 || moveX > 1000)
		obj->vel *= -0.1;
	if (moveY < 0 || moveY > 1000)
		obj->vel *= -0.1;
}
