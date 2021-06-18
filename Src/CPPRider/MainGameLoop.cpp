#include "stdafx.h"
#include "MainGameLoop.h"
#include "KeyInputEngine.h"
#include "Renderer.h"

CKartObject myKart;

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
	updateEngineList.push_back(new CVectorUpdateEngine());
	updateEngineList.push_back(new CCameraUpdateEngine());

	backboardList.push_back(new CMapObject());

	CKartObject otherKart1;
	CKartObject otherKart2;
	CKartObject otherKart3;
	CKartObject otherKart4;

	objList.push_back(&myKart);
	objList.push_back(&otherKart1);
	objList.push_back(&otherKart2);
	objList.push_back(&otherKart3);
	objList.push_back(&otherKart4);


}

void CMainGameLoop::StartLoop()
{
	while (loopFlag)
	{
		KeyInput()->Query();

		for (auto engine : updateEngineList)
			engine->Update();

		GDI()->Render();

		Sleep(TIME_QUANTUM);
	}
}

void CMainGameLoop::Terminate()
{
	loopFlag = false;
}
