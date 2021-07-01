#pragma once
#include "BackBoardSuper.h"
class CMapObject : public CBackBoardSuper
{
public:
	CMapObject();
	~CMapObject();

	static char mapContainer[1000][1000];

	virtual void Draw(CRendererForGame* renderer);
private:
};

