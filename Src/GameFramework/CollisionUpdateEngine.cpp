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
	CVECTOR moveVec(obj->pos.X + obj->vel * cos(radian) * TIME_QUANTUM, obj->pos.Y + obj->vel * sin(radian) * TIME_QUANTUM);

	if (moveVec.X < 0)
	{
		obj->pos.X = 1;
		obj->vel *= -0.1;
	}
	if (moveVec.X > 999)
	{
		obj->pos.X = 999;
		obj->vel *= -0.1;
	}
	if (moveVec.Y < 0)
	{
		obj->pos.Y = 1;
		obj->vel *= -0.1;
	}
	if (moveVec.Y > 999)
	{
		obj->pos.Y = 999;
		obj->vel *= -0.1;
	}
}
