#pragma once
#include "ObjectSuper.h"
#include "RendererForGame.h"

class CKartObject : public CObjectSuper
{
public:
	CKartObject();
	~CKartObject();

	virtual void Draw(CRendererForGame* renderer, Camera camera);

	double vel;
	double maxVel;
	double acc;
private:
};

