#include "stdafx.h"
#include "CameraUpdateEngine.h"

CCameraUpdateEngine::CCameraUpdateEngine()
{
}

CCameraUpdateEngine::~CCameraUpdateEngine()
{
}

void CCameraUpdateEngine::Update(CKartObject* obj)
{
	extern Camera camera;
	//camera.objVector = obj->pos; // ���� �ʿ䰡 ���� // obj -> target
	
	camera.centerPosition.X = WINDOW_WIDTH * 0.5;		//vector -> position
	camera.centerPosition.Y = WINDOW_HEIGHT * 0.5;
	if (obj->isBoost) {
		if(obj->boostTime < 100)
			camera.centerPosition.X += obj->boostTime % 2 == 0 ? -3 : 3;
		if(obj->boostTime >= 100 && obj->boostTime < 200)
			camera.centerPosition.X += obj->boostTime % 2 == 0 ? -2 : 2;
		if (obj->boostTime >= 200 && obj->boostTime < 300)
			camera.centerPosition.X += obj->boostTime % 2 == 0 ? -1 : 1;
	}
	camera.angle = -1 * obj->angle;		//ī�޶�� : camera, ī�޶� ���� : updateEngine, ����Ǵ� ���� �������� �ݴ�� ī�޶� ����������.
	camera.name = obj->name;
}
