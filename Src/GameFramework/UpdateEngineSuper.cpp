#include "stdafx.h"
#include "UpdateEngineSuper.h"

CUpdateEngineSuper::CUpdateEngineSuper()
{
}

CUpdateEngineSuper::~CUpdateEngineSuper()
{
}

void CUpdateEngineSuper::Update(CKartObject* obj)
{
	obj->Move(obj->getVel(), obj->getAngle());
}
