#include "stdafx.h"
#include "MainGameLoop.h"

int main()
{
	GameLoop()->Initialize();

	GameLoop()->StartLoop();

	GameLoop()->Terminate();
}
