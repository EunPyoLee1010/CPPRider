#include "stdafx.h"
#include "MainGameLoop.h"
#include "KeyInputEngine.h"
#include "Renderer.h"

CKartObject myKart;
CKartObject otherKarts[4];
CMapObject map;
char CMapObject::mapContainer[1000][1000];

int CStatusObject::playerAngle;
int CStatusObject::playerPosX;
int CStatusObject::playerPosY;

Camera camera;	//뷰도 말이 안된다. camera

CMainGameLoop::CMainGameLoop() :
	loopFlag(true)
{
}

CMainGameLoop::~CMainGameLoop()
{
}

void CMainGameLoop::Initialize()
{
	GDI()->CreateGDI();

	updateEngineList.push_back(new CCollisionUpdateEngine());
	updateEngineList.push_back(new CStatusUpdateEngine());
	updateEngineList.push_back(new CCameraUpdateEngine());

	backboardList.push_back(&map);

	int x = 50;
	for (int i = 0; i < 4; i++)
	{
		int intervel = 100;
		otherKarts[i].pos.X = (x + intervel * i);
		otherKarts[i].pos.Y = 30;
		objList.push_back(&otherKarts[i]);
	}

	myKart.pos.X = 200;
	myKart.pos.Y = 30;
	myKart.name = "은표";
	objList.push_back(&myKart);

	frontboardList.push_back(new CStatusObject());
}

void CMainGameLoop::StartLoop()
{
	while (loopFlag)
	{
		KeyInput()->Query();

		for (auto engine : updateEngineList)
			engine->Update(&myKart);

		GDI()->Render();

		Sleep(TIME_QUANTUM);
	}
}

void CMainGameLoop::Terminate()
{
	loopFlag = false;
}
