#pragma once
#include "RendererForGame.h"
#include "vector.h"

class CBackBoardSuper		//지금상황에서 맞지 않는 클래스
{
public:
	CBackBoardSuper();
	~CBackBoardSuper();
	virtual void Draw(CRendererForGame* renderer, Camera camera);
private:

};

