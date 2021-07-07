#include "stdafx.h"
#include "CameraUpdateEngine.h"

CCameraUpdateEngine::CCameraUpdateEngine()
{
}

CCameraUpdateEngine::~CCameraUpdateEngine()
{
}

void CCameraUpdateEngine::Update(CKartObject* obj)
{
	extern Camera view;
	view.objVector = obj->pos;
	
	view.centVector.X = WINDOW_WIDTH * 0.5;
	view.centVector.Y = WINDOW_HEIGHT * 0.5;
	view.angle = obj->angle;
	view.name = obj->name;
}
