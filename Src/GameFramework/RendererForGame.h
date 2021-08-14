#pragma once
#include <Windows.h>
#include <string>
#include "vector.h"

POINT* RotateEdges(CVECTOR edge[], CVECTOR basePoint, int angle);

class CRendererForGame
{
public:
	CRendererForGame();
	~CRendererForGame();

	virtual void Rectangle(int left, int top, int right, int bottom, COLORREF rgb);
	virtual void Ellipse(int left, int top, int right, int bottom, COLORREF rgb);
	virtual void Text(int left, int top, COLORREF rgb, std::string text);
	virtual void Polygon(POINT* edges, COLORREF color);
	virtual void Line(int left, int top, int right, int bottom, COLORREF color);
private:

};

