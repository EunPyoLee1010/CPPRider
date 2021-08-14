#include "stdafx.h"
#include "MainGameLoop.h"
#include "KeyInputEngine.h"
#include "Renderer.h"

CKartObject myKart;
CKartObject otherKarts[4];
CMapObject map;
char CMapObject::mapContainer[1000][1000];
int CMapObject::laps = 3;

int CStatusObject::playerAngle;
int CStatusObject::playerPosX;
int CStatusObject::playerPosY;
int CStatusObject::playerLaps;
bool CMainGameLoop::loopFlag;

Camera camera;	//�䵵 ���� �ȵȴ�. camera

CMainGameLoop::CMainGameLoop()
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
		int intervel = 70;
		otherKarts[i].pos.X = (x + intervel * i);
		otherKarts[i].pos.Y = 30;
		objList.push_back(&otherKarts[i]);
	}

	myKart.pos.X = 160;
	myKart.pos.Y = 30;
	myKart.name = "��ǥ";
	objList.push_back(&myKart);

	frontboardList.push_back(new CStatusObject());

	CMainGameLoop::loopFlag = true;
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
