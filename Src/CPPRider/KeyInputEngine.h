#pragma once
class CKeyInputEngine
{
public:
	int Query();
	static CKeyInputEngine* getInstance()
	{
		static CKeyInputEngine instance;
		return &instance;
	}

private:
	CKeyInputEngine();
	~CKeyInputEngine();
};

inline CKeyInputEngine* KeyInput()
{
	return CKeyInputEngine::getInstance();
}

