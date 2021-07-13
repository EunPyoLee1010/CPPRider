#pragma once
#include "BackBoardSuper.h"
#include "camera.h"

class CMapObject : public CBackBoardSuper
{
public:
	CMapObject();
	~CMapObject();

	static char mapContainer[1000][1000];

	virtual void Draw(CRendererForGame* renderer, Camera camera);
private:
	int mapIndexWidth;
	int mapIndexHeight;
};

