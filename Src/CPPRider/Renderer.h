#pragma once
class CRenderer
{
public:
	static CRenderer* GetInstance()
	{
		CRenderer instance;
		return &instance;
	}
	void CreateGDI();
	int CreateGDIScreen();
	void Render();
private:
	CRenderer();
	~CRenderer();
};

CRenderer* GDI()
{
	return CRenderer::GetInstance();
}