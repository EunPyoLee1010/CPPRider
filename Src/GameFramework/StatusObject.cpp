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
	{
		std::string text = "A: " + std::to_string(playerAngle);
		renderer->Text(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 100, RGB(0, 0, 0),15, text);
		text = "X: " + std::to_string(playerPosX);
		renderer->Text(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 80, RGB(0, 0, 0),15, text);
		text = "Y: " + std::to_string(playerPosY);
		renderer->Text(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 60, RGB(0, 0, 0),15, text);
		text = "laps :" + (playerLaps > 3 ? std::to_string(3) : std::to_string(playerLaps)) + " / " + std::to_string(CMapObject::laps);
		renderer->Text(WINDOW_WIDTH - 50, 10, RGB(0, 0, 0),15, text);
	}

	{
		renderer->Rectangle(10, 10, 60, 60, RGB(255, 212, 0));
		renderer->Rectangle(70, 10, 120, 60, RGB(255, 212, 0));

		renderer->Text(WINDOW_WIDTH * 0.5 - 130, WINDOW_HEIGHT - 70, RGB(0, 0, 0),15, "Gauge");
		renderer->Rectangle(WINDOW_HEIGHT * 0.5 - 100, WINDOW_HEIGHT - 70, WINDOW_HEIGHT * 0.5 + 100, WINDOW_HEIGHT - 50, RGB(255, 212, 0));
	}

	{
		extern CKartObject myKart;
		for (int i = 0; i < myKart.boosterCount; i++)
		{
			renderer->Rectangle(i * 60 + 15, 15, i * 60 + 55, 55, RGB(255, 0, 0));
			renderer->Text(i * 60 + 35, 27, RGB(255, 255, 255),15, "N2O");
		}
		renderer->Rectangle(WINDOW_HEIGHT * 0.5 - 100, WINDOW_HEIGHT - 70, WINDOW_HEIGHT * 0.5 - 100 + myKart.boostGauge * 2, WINDOW_HEIGHT - 50, RGB(255, 0, 255));
	}
}
