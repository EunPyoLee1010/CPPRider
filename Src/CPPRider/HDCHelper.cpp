#include "stdafx.h"
#include "HDCHelper.h"

HDCHelper::HDCHelper() :
	m_MemDC(NULL),
	m_hBit(NULL),
	m_MemBit(NULL),
	m_Rect(SIZE{0,0}),
	m_hWnd(NULL)
{
}

HDCHelper::~HDCHelper()
{
	::SelectObject(m_MemDC, m_MemBit);
	::DeleteObject(m_hBit);
	::DeleteDC(m_MemDC);

	m_MemBit = NULL;
}

void HDCHelper::Create(HWND hWnd, SIZE rect)
{
	m_hWnd = hWnd;
	HDC m_hDC = ::GetDC(m_hWnd);
	m_MemDC = CreateCompatibleDC(m_hDC);

	m_hBit = CreateCompatibleBitmap(m_hDC, rect.cx, rect.cy);
	m_MemBit = (HBITMAP)::SelectObject(m_MemDC, m_hBit);

	m_Rect = rect;
}

void HDCHelper::Clear()
{
	::PatBlt(m_MemDC, 0, 0, m_Rect.cx, m_Rect.cy, WHITENESS);
}

void HDCHelper::Flush(HDC hDC, POINT point)
{
	::BitBlt(hDC, point.x, point.y, m_Rect.cx, m_Rect.cy, m_MemDC, 0, 0, SRCCOPY);
}

PenHelper::PenHelper(HDC hDC, COLORREF rgb) : hDC(hDC)
{
	hPen = CreatePen(PS_SOLID, 5, rgb);
	hOldPen = (HPEN)::SelectObject(this->hDC, hPen);
}

PenHelper::~PenHelper()
{
	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
}

BrushHelper::BrushHelper(HDC hDC, COLORREF rgb) :
	hDC(hDC),
	hBrush(NULL),
	hOldBrush(NULL)
{
	hBrush = CreateSolidBrush(rgb);
	hOldBrush = (HBRUSH)::SelectObject(this->hDC, hBrush);
}

BrushHelper::~BrushHelper()
{
	SelectObject(this->hDC, hOldBrush);
	DeleteObject(hBrush);
}

FontHelper::FontHelper(HDC hDC, int fontSize) :
	hDC(hDC)
{
	hFont = CreateFont(fontSize,0,0,0,0,0,0,0,HANGEUL_CHARSET,0,0,0,VARIABLE_PITCH | FF_ROMAN,TEXT("±Ã¼­"));
	hOldFont = (HFONT)SelectObject(this->hDC, hFont);
}

FontHelper::~FontHelper()
{
	SelectObject(this->hDC, hOldFont);
	DeleteObject(hFont);
}

