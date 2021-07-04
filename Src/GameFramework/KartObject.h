#pragma once
#include "ObjectSuper.h"
#include "RendererForGame.h"

class CKartObject : public CObjectSuper
{
public:
	CKartObject();
	~CKartObject();

	virtual void Draw(CRendererForGame* renderer, POINT screen);

	double angle;
	double vel;
	double maxVel;
	double acc;
private:
};

