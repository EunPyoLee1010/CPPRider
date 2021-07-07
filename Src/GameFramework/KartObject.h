#pragma once
#include "ObjectSuper.h"
#include "RendererForGame.h"

class CKartObject : public CObjectSuper
{
public:
	CKartObject();
	~CKartObject();

	virtual void Draw(CRendererForGame* renderer, CVECTOR screen);

	double vel;
	double maxVel;
	double acc;
private:
};

