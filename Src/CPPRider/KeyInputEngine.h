#pragma once
class CKeyInputEngine
{
public:
	int Query();
	static CKeyInputEngine* getInstance()
	{
		CKeyInputEngine instance;
		return &instance;
	}

private:
	CKeyInputEngine();
	~CKeyInputEngine();
};

CKeyInputEngine* KeyInput()
{
	return CKeyInputEngine::getInstance();
}

