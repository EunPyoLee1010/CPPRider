#pragma once
#include "../GameFramework/RendererForGame.h"

DWORD WINAPI CreateGDIThreadCaller(void* pContext);
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

class CRenderer : public CRendererForGame
{
public:
	static CRenderer* GetInstance()
	{
		static CRenderer instance;
		return &instance;
	}
	void CreateGDI();
	int CreateGDIScreen();
	void Render();

	virtual void Rectangle(int left, int top, int right, int bottom, COLORREF rgb);
	virtual void Ellipse(int left, int top, int right, int bottom, COLORREF rgb);
	virtual void Text(int left, int top, COLORREF rgb, std::string text);
private:
	CRenderer();
	~CRenderer();
};

inline CRenderer* GDI()
{
	return CRenderer::GetInstance();
}