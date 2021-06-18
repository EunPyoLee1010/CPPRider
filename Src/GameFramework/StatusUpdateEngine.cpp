#include "StatusUpdateEngine.h"

CStatusUpdateEngine::CStatusUpdateEngine()
{
}

CStatusUpdateEngine::~CStatusUpdateEngine()
{
}

void CStatusUpdateEngine::Update(CKartObject* obj)
{
	obj->Move(obj->vel, obj->angle);
}

