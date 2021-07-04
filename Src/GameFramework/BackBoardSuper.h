#pragma once
#include "RendererForGame.h"

class CBackBoardSuper
{
public:
	CBackBoardSuper();
	~CBackBoardSuper();
	virtual void Draw(CRendererForGame* renderer, POINT screen);
private:

};

