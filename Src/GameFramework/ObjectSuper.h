#pragma once
#include "RendererForGame.h"

class CObjectSuper
{
public:
	CObjectSuper();
	~CObjectSuper();

	virtual void Draw(CRendererForGame* renderer, POINT screen);

	double posX;
	double posY;

	int width;
	int height;
	std::string name;
private:

};

