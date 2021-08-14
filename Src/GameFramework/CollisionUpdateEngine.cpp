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
	CVECTOR movePosition(obj->pos.X + obj->vel * cos(radian) * TIME_QUANTUM, obj->pos.Y + obj->vel * sin(radian) * TIME_QUANTUM);

	extern CMapObject map;
	if (map.isCollide(movePosition)) 
	{
		obj->pos.X -= obj->vel * cos(radian);
		obj->pos.Y -= obj->vel * sin(radian);
		obj->pos.X = ceil(obj->pos.X);
		obj->pos.Y = ceil(obj->pos.Y);
		obj->vel *= -0.2;
	}
}
