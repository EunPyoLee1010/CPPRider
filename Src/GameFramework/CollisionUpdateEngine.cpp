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
	extern CMapObject map;

	for (int y = int(obj->pos.Y + obj->vel * sin(radian) * TIME_QUANTUM) - 2; y < int(obj->pos.Y + obj->vel * sin(radian) * TIME_QUANTUM) + 2; y++)
	{
		for (int x = int(obj->pos.X + obj->vel * cos(radian) * TIME_QUANTUM) - 2; x < int(obj->pos.X + obj->vel * cos(radian) * TIME_QUANTUM) + 2; x++)
		{
			CVECTOR movePosition(x, y);
			if (map.isCollide(movePosition))
			{
				obj->pos.X -= obj->vel * cos(radian);
				obj->pos.Y -= obj->vel * sin(radian);
				obj->pos.X = ceil(obj->pos.X);
				obj->pos.Y = ceil(obj->pos.Y);
				obj->vel *= -0.2;
			}
		}
	}
}
