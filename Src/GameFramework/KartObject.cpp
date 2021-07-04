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

void CKartObject::Draw(CRendererForGame* renderer, POINT screen)
{
	//double radian = ((angle)) * PI / 180;
	//int left = posX - width * 0.5;
	//int right = posX + width * 0.5;
	//int top = (WINDOW_HEIGHT - posY) - height * 0.5;
	//int bottom = (WINDOW_HEIGHT - posY) + height * 0.5;
	//int textLength = strlen(name.c_str());

	//POINT edge[4];
	//edge[0] = { int((left - posX) * cos(radian) - (top - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((top - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	//edge[1] = { int((right - posX) * cos(radian) - (top - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((top - (WINDOW_HEIGHT - posY)) * cos(radian) + (right - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	//edge[2] = { int((right - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (right - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	//edge[3] = { int((left - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };

	//renderer->Polygon(edge, RGB(0, 0, 255));
	//renderer->Text(int((left - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX) - (textLength * 0.5) * 5,
	//	int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) + 5, RGB(0, 0, 0), name);

	double radian = (angle) * PI / 180;
	int left = screen.x - width * 0.5;
	int right = screen.x + width * 0.5;
	int top = (WINDOW_HEIGHT - screen.y) - height * 0.5;
	int bottom = (WINDOW_HEIGHT - screen.y) + height * 0.5;
	int textLength = strlen(name.c_str());

	POINT edge[4];
	edge[0] = { int((left - screen.x) * cos(radian) - (top - (WINDOW_HEIGHT - screen.y)) * sin(radian) + screen.x), int((top - (WINDOW_HEIGHT - screen.y)) * cos(radian) + (left - screen.x) * sin(radian) + (WINDOW_HEIGHT - screen.y)) };
	edge[1] = { int((right - screen.x) * cos(radian) - (top - (WINDOW_HEIGHT - screen.y)) * sin(radian) + screen.x), int((top - (WINDOW_HEIGHT - screen.y)) * cos(radian) + (right - screen.x) * sin(radian) + (WINDOW_HEIGHT - screen.y)) };
	edge[2] = { int((right - screen.x) * cos(radian) - (bottom - (WINDOW_HEIGHT - screen.y)) * sin(radian) + screen.x), int((bottom - (WINDOW_HEIGHT - screen.y)) * cos(radian) + (right - screen.x) * sin(radian) + (WINDOW_HEIGHT - screen.y)) };
	edge[3] = { int((left - screen.x) * cos(radian) - (bottom - (WINDOW_HEIGHT - screen.y)) * sin(radian) + screen.x), int((bottom - (WINDOW_HEIGHT - screen.y)) * cos(radian) + (left - screen.x) * sin(radian) + (WINDOW_HEIGHT - screen.y)) };

	renderer->Polygon(edge, RGB(0, 0, 255));
	renderer->Text(int((left - screen.x) * cos(radian) - (bottom - (WINDOW_HEIGHT - screen.y)) * sin(radian) + screen.x) - (textLength * 0.5) * 5,
		int((bottom - (WINDOW_HEIGHT - screen.y)) * cos(radian) + (left - screen.x) * sin(radian) + (WINDOW_HEIGHT - screen.y)) + 5, RGB(0, 0, 0), name);
}
