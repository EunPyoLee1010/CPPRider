#pragma once
#include "RendererForGame.h"
#include "vector.h"
#include "camera.h"

class CBackBoardSuper		//���ݻ�Ȳ���� ���� �ʴ� Ŭ����
{
public:
	CBackBoardSuper();
	~CBackBoardSuper();
	virtual void Draw(CRendererForGame* renderer, Camera camera);
private:

};

