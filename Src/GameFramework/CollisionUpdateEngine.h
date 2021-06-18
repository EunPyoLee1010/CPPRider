#pragma once
#include "UpdateEngineSuper.h"
class CCollisionUpdateEngine : public CUpdateEngineSuper
{
public:
	CCollisionUpdateEngine();
	~CCollisionUpdateEngine();

	virtual void Update();

private:

};

