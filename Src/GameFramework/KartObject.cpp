#include "stdafx.h"
#include "KartObject.h"

CKartObject::CKartObject() :
	vel(0),
	acc(0.5),
	maxVel(3),
	isDrift(false),
	isBoost(false),
	boosterCount(0),
	boostGauge(0),
	boostTime(0),
	lapCount(2),
	lap(1)
{
}

CKartObject::~CKartObject()
{
}

void CKartObject::Draw(CRendererForGame* renderer, Camera camera)
{
	extern CKartObject myKart;
	CVECTOR newPosition;
	if (myKart.name == name) {
		newPosition = camera.centerPosition;
	}
	else {
		if (myKart.isBoost) {
			if (myKart.boostTime > 0)
				camera.centerPosition.X += myKart.boostTime % 2 == 0 ? -1 : 1;
			if (myKart.boostTime >= 100)
				camera.centerPosition.X += myKart.boostTime % 2 == 0 ? -1 : 1;
			if (myKart.boostTime >= 200)
				camera.centerPosition.X += myKart.boostTime % 2 == 0 ? -1 : 1;
		}

		CVECTOR movedCamPosition = myKart.pos - camera.centerPosition;
		newPosition = pos - myKart.pos;
		newPosition = newPosition.RotateClockwise(camera.angle);
		newPosition = newPosition(int(newPosition.X), int(newPosition.Y)) + myKart.pos - movedCamPosition;
	}



	newPosition.Y = WINDOW_HEIGHT - newPosition.Y;

	int left = newPosition.X - width * 0.5;
	int right = newPosition.X + width * 0.5;
	int top = newPosition.Y - height * 0.5;
	int bottom = newPosition.Y + height * 0.5;
	int textLength = strlen(name.c_str());

	if (right < 0)
		return;
	if (WINDOW_WIDTH < left)
		return;
	if (bottom < 0)
		return;
	if (WINDOW_HEIGHT < top)
		return;

	CVECTOR edge[4];
	edge[0](left, top);
	edge[1](right, top);
	edge[2](right, bottom);
	edge[3](left, bottom);

	POINT rotatedEdge[4];
	memcpy(rotatedEdge, RotateEdges(edge, newPosition, angle + camera.angle), sizeof(rotatedEdge));

	renderer->Polygon(rotatedEdge, RGB(0, 0, 255));
	renderer->Text(edge[3].X - (textLength * 0.5) * 5, edge[3].Y + 5, RGB(0, 0, 0), name);
	if (isBoost)	//카메라 진동시키기 혹은 여러 발 발사해서 표현, 빗선을 그려서 속도감을 주기, 줌아웃 시켰다가 줌 인 하기
	{
		if (boostTime % 2 == 0) {
			edge[0](left- 10, top + 15);
			edge[1](left - 15, top + 30);
			edge[2](right + 10, top + 15);
			edge[3](right + 15, top + 30);
		}
		if (boostTime % 3 == 0) {
			edge[0](left - 20, bottom + 5);
			edge[1](left - 25, bottom + 20);
			edge[2](right + 20, bottom + 5);
			edge[3](right + 25, bottom + 20);
		}

		POINT rotatedEdge[4];
		memcpy(rotatedEdge, RotateEdges(edge, newPosition, angle + camera.angle), sizeof(rotatedEdge));

		renderer->Line(rotatedEdge[0].x, rotatedEdge[0].y, rotatedEdge[1].x, rotatedEdge[1].y, RGB(150, 150, 150));
		renderer->Line(rotatedEdge[2].x, rotatedEdge[2].y, rotatedEdge[3].x, rotatedEdge[3].y, RGB(150, 150, 150));

		if (boostTime % 2 == 0) {
			edge[0](left, bottom);
			edge[1](left, bottom + 20);
			edge[2](right, bottom);
			edge[3](right, bottom + 20);
		}
		if (boostTime % 2 != 0) {
			edge[0](left, bottom);
			edge[1](left, bottom + 10);
			edge[2](right, bottom);
			edge[3](right, bottom + 10);
		}

		memcpy(rotatedEdge, RotateEdges(edge, newPosition, angle + camera.angle), sizeof(rotatedEdge));
		renderer->Polygon(rotatedEdge, RGB(255, 0, 0));
	}
}