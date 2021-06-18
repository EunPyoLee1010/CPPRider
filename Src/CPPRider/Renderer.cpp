#include "stdafx.h"
#include "Renderer.h"
#include "MainGameLoop.h"
#include "HDCHelper.h"

HDCHelper hDCInstance;

void CRenderer::CreateGDI()
{
	CreateThread(NULL, 0, CreateGDIThreadCaller, this, 0, 0);
}

void CRenderer::Render()
{
	for (auto backObj : GameLoop()->backboardList)
		backObj->Draw();

	for (auto obj : GameLoop()->objList)
		obj->Draw();

	for (auto frontObj : GameLoop()->frontboardList)
		frontObj->Draw();
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