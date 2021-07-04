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

Camera view;

CMainGameLoop::CMainGameLoop() :
	loopFlag(true)
{
}

CMainGameLoop::~CMainGameLoop()
{
}

void CMainGameLoop::Initialize()
{
	loopFlag = true;
	GDI()->CreateGDI();

	updateEngineList.push_back(new CCollisionUpdateEngine());
	updateEngineList.push_back(new CStatusUpdateEngine());
	updateEngineList.push_back(new CCameraUpdateEngine());

	backboardList.push_back(&map);

	int x = 100;
	for (int i = 0; i < 4; i++)
	{
		int intervel = 200;
		otherKarts[i].posX = x + intervel * i;
		otherKarts[i].posY = 250;
		objList.push_back(&otherKarts[i]);
	}

	myKart.posX = 500;
	myKart.posY = 500;
	myKart.name = "ÀºÇ¥";
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
