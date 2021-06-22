#include "stdafx.h"
#include "StatusObject.h"

CStatusObject::CStatusObject()
{
}

CStatusObject::~CStatusObject()
{
}

void CStatusObject::Draw(CRendererForGame* renderer)
{
	std::string text = "A: " + std::to_string(playerAngle);
	renderer->Text(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 100, RGB(0, 0, 0), text);
	text = "X: " + std::to_string(playerPosX);
	renderer->Text(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 80, RGB(0, 0, 0), text);
	text = "Y: " + std::to_string(playerPosY);
	renderer->Text(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 60, RGB(0, 0, 0), text);
}
