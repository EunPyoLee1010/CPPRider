#pragma once
#include "FrontBoardSuper.h"
#include "RendererForGame.h"
class CStatusObject : public CFrontBoardSuper
{
public:
	CStatusObject();
	~CStatusObject();
	static int playerPosX;
	static int playerPosY;
	static int playerAngle;

	virtual void Draw(CRendererForGame* renderer);
};

