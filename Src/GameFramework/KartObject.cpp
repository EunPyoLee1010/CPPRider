#include "stdafx.h"
#include "KartObject.h"

CKartObject::CKartObject() :
	angle(0),
	vel(0),
	acc(0.1),
	maxVel(1.5)
{
}

CKartObject::~CKartObject()
{
}

void CKartObject::Draw(CRendererForGame* renderer)
{
	//double radian = 0;
	//angle > 0 ? radian = (angle - 90) * PI / 180 : 0;
	double radian = ((angle)) * PI / 180;
	int left = posX - width * 0.5;
	int right = posX + width * 0.5;
	int top = (WINDOW_HEIGHT - posY) - height * 0.5;
	int bottom = (WINDOW_HEIGHT - posY) + height * 0.5;
	int textLength = strlen(name.c_str());

	POINT edge[4];
	edge[0] = { int((left - posX) * cos(radian) - (top - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((top - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	edge[1] = { int((right - posX) * cos(radian) - (top - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((top - (WINDOW_HEIGHT - posY)) * cos(radian) + (right - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	edge[2] = { int((right - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (right - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	edge[3] = { int((left - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };

	//renderer->Rectangle(left, top, right, bottom, RGB(0, 0, 255));
	//renderer->Text(left, bottom + 10, RGB(0, 0, 0), name);
	renderer->Polygon(edge, RGB(0, 0, 255));
	renderer->Text(int((left - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX) - (textLength * 0.5) * 5,
		int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) + 5, RGB(0, 0, 0), name);
}
