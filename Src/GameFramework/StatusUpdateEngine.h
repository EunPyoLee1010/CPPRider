#pragma once
#include "UpdateEngineSuper.h"
class CStatusUpdateEngine : public CUpdateEngineSuper
{
public:
	CStatusUpdateEngine();
	~CStatusUpdateEngine();

	virtual void Update(CKartObject* obj);
private:
};

