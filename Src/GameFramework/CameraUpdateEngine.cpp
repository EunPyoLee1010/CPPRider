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
	//if (obj->isBoost) {
	//	if (obj->boostTime > 0)
	//		camera.centerPosition.X += obj->boostTime % 2 == 0 ? -2 : 2;
	//	if (obj->boostTime >= 100)
	//		camera.centerPosition.X += obj->boostTime % 2 == 0 ? -1 : 1;
	//	if (obj->boostTime >= 200)
	//		camera.centerPosition.X += obj->boostTime % 2 == 0 ? -1 : 1;
	//}
	camera.centerPosition.X = WINDOW_WIDTH * 0.5;		//vector -> position
	camera.centerPosition.Y = WINDOW_HEIGHT * 0.5;

	camera.angle = -1 * obj->angle;		//ī�޶�� : camera, ī�޶� ���� : updateEngine, ����Ǵ� ���� �������� �ݴ�� ī�޶� ����������.
	camera.name = obj->name;
}
