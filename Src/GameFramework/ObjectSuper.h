#pragma once
#include "RendererForGame.h"
#include "vector.h"

class CObjectSuper
{
public:
	CObjectSuper();
	~CObjectSuper();

	virtual void Draw(CRendererForGame* renderer, Camera camera);

	CVECTOR pos;

	double angle;
	int width;
	int height;
	std::string name;
private:

};

