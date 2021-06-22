#include "stdafx.h"
#include "KartObject.h"

CKartObject::CKartObject() :
	angle(0),
	vel(0),
	acc(0.01),
	maxVel(2)
{
}

CKartObject::~CKartObject()
{
}

void CKartObject::Draw(CRendererForGame* renderer)
{
	int left = posX - width * 0.5;
	int right = posX + width * 0.5;
	int top = (WINDOW_HEIGHT - posY) - height * 0.5;
	int bottom = (WINDOW_HEIGHT - posY) + height * 0.5;

	renderer->Rectangle(left, top, right, bottom, RGB(0, 0, 255));
	renderer->Text(left, bottom + 10, RGB(0, 0, 0), name);
}
