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
	view.objectX = obj->posX;
	view.objectY = obj->posY;
	view.centeredScreenX = WINDOW_WIDTH * 0.5;
	view.centeredScreenY = WINDOW_HEIGHT * 0.5;
	view.name = obj->name;
}
