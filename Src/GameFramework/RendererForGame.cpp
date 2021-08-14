#include "stdafx.h"
#include "RendererForGame.h"

CRendererForGame::CRendererForGame()
{
}

CRendererForGame::~CRendererForGame()
{
}

void CRendererForGame::Rectangle(int left, int top, int right, int bottom, COLORREF rgb)
{
}

void CRendererForGame::Ellipse(int left, int top, int right, int bottom, COLORREF rgb)
{
}

void CRendererForGame::Text(int left, int top, COLORREF rgb, std::string text)
{
}

void CRendererForGame::Polygon(POINT* edges, COLORREF color)
{
}

void CRendererForGame::Line(int left, int top, int right, int bottom, COLORREF color)
{
}

POINT* RotateEdges(CVECTOR edge[], CVECTOR basePoint, int angle)
{
	POINT rotatedEdge[4];
	for (int i = 0; i < 4; i++)
	{
		edge[i] = edge[i] - basePoint;
		edge[i] = edge[i].RotateCntClockwise(angle);
		edge[i] = edge[i] + basePoint;

		rotatedEdge[i] = { int(edge[i].X), int(edge[i].Y) };
	}
	return rotatedEdge;
}
