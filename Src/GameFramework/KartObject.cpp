#include "stdafx.h"
#include "KartObject.h"

CKartObject::CKartObject() :
	vel(0),
	acc(0.1),
	maxVel(1.5),
	isDrift(false)
{
}

CKartObject::~CKartObject()
{
}

void CKartObject::Draw(CRendererForGame* renderer, Camera camera)
{
	extern CKartObject myKart;
	CVECTOR movedCamPosition = myKart.pos - camera.centerPosition;
	CVECTOR newPosition = pos - myKart.pos;
	newPosition = newPosition.RotateClockwise(camera.angle);
	newPosition = newPosition(int(newPosition.X), int(newPosition.Y)) + myKart.pos - movedCamPosition;

	if (myKart.name == name) {
		newPosition = camera.centerPosition;
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
	for (int i = 0; i < 4; i++)
	{
		edge[i] = edge[i] - newPosition;
		edge[i] = edge[i].RotateCntClockwise(angle + camera.angle);
		edge[i] = edge[i] + newPosition;

		rotatedEdge[i] = { int(edge[i].X), int(edge[i].Y) };
	}

	renderer->Polygon(rotatedEdge, RGB(0, 0, 255));
	renderer->Text(edge[3].X - (textLength * 0.5) * 5, edge[3].Y + 5, RGB(0, 0, 0), name);
}