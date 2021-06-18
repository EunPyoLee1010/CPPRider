#pragma once
#include "HDCHelper.h"
#include <Windows.h>
#include <string>

class HDCHelper
{
public:
	HWND m_hWnd;
	HDC m_MemDC;
	HBITMAP m_hBit, m_MemBit;
	SIZE m_Rect;

	HDCHelper();
	~HDCHelper();
	void Create(HWND hWnd, SIZE rect);
	void Clear();
	void Flush(HDC hDC, POINT point = {0, 0});
};

class PenHelper
{
private:
public:
	HDC hDC;
	HPEN hPen;
	HPEN hOldPen;
	PenHelper(HDC hDC, COLORREF rgb);
	~PenHelper();
};

class BrushHelper
{
private:
public:
	HDC hDC;
	HBRUSH hBrush;
	HBRUSH hOldBrush;
	BrushHelper(HDC hDC, COLORREF rgb);
	~BrushHelper();
};

