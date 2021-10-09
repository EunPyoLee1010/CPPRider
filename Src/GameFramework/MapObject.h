#pragma once
#include "BackBoardSuper.h"
#include "camera.h"

class CMapObject : public CBackBoardSuper
{
public:
	CMapObject();
	~CMapObject();

	static char mapContainer[1000][1000];
	static int laps;
	virtual void Draw(CRendererForGame* renderer, Camera camera);
	bool isCollide(CVECTOR position);
private:
	int mapIndexWidth;
	int mapIndexHeight;
};
