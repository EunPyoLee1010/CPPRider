#include "stdafx.h"
#include "KartObject.h"

CKartObject::CKartObject() :
	vel(0),
	acc(0.1),
	maxVel(1.5)
{
}

CKartObject::~CKartObject()
{
}

void CKartObject::Draw(CRendererForGame* renderer, Camera camera)
{

	extern CKartObject myKart;
	CVECTOR movedCamPosition = myKart.pos - camera.centerPosition;
	CVECTOR screenPosition = this->pos - movedCamPosition;
	screenPosition = screenPosition.RotateCntClockwise(camera.angle);
	screenPosition = screenPosition + movedCamPosition;

	int left = screenPosition.X - width * 0.5;
	int right = screenPosition.X + width * 0.5;
	int top = (WINDOW_HEIGHT - screenPosition.Y) - height * 0.5;
	int bottom = (WINDOW_HEIGHT - screenPosition.Y) + height * 0.5;
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
		edge[i] = edge[i] - screenPosition;
		//edge[i] = edge[i].RotateCntClockwise(angle - view.angle);
		edge[i] = edge[i].RotateCntClockwise(angle);
		edge[i] = edge[i] + screenPosition;

		rotatedEdge[i] = { int(edge[i].X), int(edge[i].Y) };
	}

	renderer->Polygon(rotatedEdge, RGB(0, 0, 255));
	renderer->Text(edge[3].X - (textLength * 0.5) * 5, edge[3].Y + 5, RGB(0, 0, 0), name);
}