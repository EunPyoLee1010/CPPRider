#include "stdafx.h"
#include "MainGameLoop.h"
#include "KeyInputEngine.h"
#include "Renderer.h"

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
