#include "stdafx.h"
#include "Renderer.h"
#include "MainGameLoop.h"
#include "HDCHelper.h"

static HDCHelper hDCInstance;

void CRenderer::CreateGDI()
{
	CreateThread(NULL, 0, CreateGDIThreadCaller, this, 0, 0);
}

void CRenderer::Render()		//애니메이션 렌더링, 실사 렌더링 -> 코드 한줄로 연출기법이 변경될 수 있는 엔진
{
	hDCInstance.Clear();

	extern Camera camera;		//centerposition와 angle을 알게됐다.
	extern CKartObject myKart;



	//CVECTOR camera(0 , 0);	//실제로 카메라에 나타나는 객체 위치

	for (auto backObj : GameLoop()->backboardList)
	{
		//맵에 대한 카메라 변수 조절하고 Draw함수에서 for문 범위 정하기
		backObj->Draw(this, camera);
	}

	for (auto obj : GameLoop()->objList)
	{
		//if (camera.name != obj->name)
		//{
		//	camera = obj->pos - camera.objVector - movedCamVec;
		//	camera = camera.RotateCntClockwise(camera.angle);
		//	//카메라 회전 고민해보기
		//	camera = camera + camera.objVector;
		//}
		//if (camera.name == obj->name)
		//{
		//	camera(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);
		//}
		obj->Draw(this, camera);
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