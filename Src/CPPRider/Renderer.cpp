#include "stdafx.h"
#include "Renderer.h"
#include "MainGameLoop.h"
#include "HDCHelper.h"

static HDCHelper hDCInstance;

void CRenderer::CreateGDI()
{
	CreateThread(NULL, 0, CreateGDIThreadCaller, this, 0, 0);
}

void CRenderer::Render()
{
	hDCInstance.Clear();


	for (auto backObj : GameLoop()->backboardList)
	{
		backObj->Draw(this);
	}

	for (auto obj : GameLoop()->objList)
	{
		extern Camera view;
		extern CKartObject myKart;
		int screenX = 0;
		int screenY = 0;
		if (view.name != obj->name)
		{
			//Ä«¸Þ¶ó
		}
		if (view.name == obj->name)
		{
			screenX = WINDOW_WIDTH * 0.5;
			screenY = WINDOW_HEIGHT * 0.5;
		}
		obj->Draw(this);
	}

	for (auto frontObj : GameLoop()->frontboardList)
	{
		frontObj->Draw(this);
	}

	HDC hDC = GetDC(hDCInstance.m_hWnd);
	hDCInstance.Flush(hDC, {0, 0});
	::ReleaseDC(hDCInstance.m_hWnd, hDC);
}

void CRenderer::Rectangle(int left, int top, int right, int bottom, COLORREF rgb)
{
	PenHelper hPen(hDCInstance.m_MemDC, rgb);
	BrushHelper hBrush(hDCInstance.m_MemDC, rgb);
	::Rectangle(hDCInstance.m_MemDC, left, top, right, bottom);
}

void CRenderer::Ellipse(int left, int top, int right, int bottom, COLORREF rgb)
{
	PenHelper hPen(hDCInstance.m_MemDC, rgb);
	BrushHelper hBrush(hDCInstance.m_MemDC, rgb);
	::Ellipse(hDCInstance.m_MemDC, left, top, right, bottom);
}

void CRenderer::Text(int left, int top, COLORREF rgb, std::string text)
{
	PenHelper hPen(hDCInstance.m_MemDC, rgb);
	::SetBkMode(hDCInstance.m_MemDC, TRANSPARENT);
	::SetTextAlign(hDCInstance.m_MemDC, TA_CENTER);
	::TextOutA(hDCInstance.m_MemDC, left, top, text.c_str(), strlen(text.c_str()));
}

void CRenderer::Polygon(POINT* edges, COLORREF color)
{
	PenHelper hPen(hDCInstance.m_MemDC, color);
	BrushHelper hBrush(hDCInstance.m_MemDC, color);
	::Polygon(hDCInstance.m_MemDC, edges, 4);
}


CRenderer::CRenderer()
{
}


CRenderer::~CRenderer()
{
}

DWORD WINAPI CreateGDIThreadCaller(void* pContext)
{
	GDI()->CreateGDIScreen();

	return 0;
}

int CRenderer::CreateGDIScreen()
{
	MSG msg;
	HINSTANCE hInstance = GetModuleHandle(NULL);
	LPCWCHAR CLASS_NAME = L"CppRider";
	WNDCLASS wc = {};

	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0, CLASS_NAME, CLASS_NAME,
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU),
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
		return 0;

	ShowWindow(hwnd, SW_SHOW);

	while (GetMessage(&msg, (HWND)NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_CREATE:
		hDCInstance.Create(hWnd, SIZE{ WINDOW_WIDTH, WINDOW_HEIGHT });
		return 0;
	case WM_PAINT:
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}