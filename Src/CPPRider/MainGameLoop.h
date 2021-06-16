#pragma once
#include <vector>
#include "../GameFramework/ObjectSuper.h"
#include "../GameFramework/BackBoardSuper.h"
#include "../GameFramework/FrontBoardSuper.h"
#include "../GameFramework/UpdateEngineSuper.h"

class CMainGameLoop
{
public:
	void Initialize();
	void StartLoop();
	void Terminate();

	static CMainGameLoop* getInstance()
	{
		CMainGameLoop instance;
		return &instance;
	}

private:
	bool loopFlag;
	std::vector<CBackBoardSuper*> backboardList;
	std::vector<CObjectSuper*> objList;
	std::vector<CFrontBoardSuper*> frontboardList;
	std::vector<CUpdateEngineSuper*>updateEngineList;
	CMainGameLoop();
	~CMainGameLoop();
};

CMainGameLoop* GameLoop()
{
	return CMainGameLoop::getInstance();
}

