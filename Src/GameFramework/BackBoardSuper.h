#pragma once
#include "RendererForGame.h"
#include "vector.h"

class CBackBoardSuper
{
public:
	CBackBoardSuper();
	~CBackBoardSuper();
	virtual void Draw(CRendererForGame* renderer, CVECTOR screen);
private:

};

