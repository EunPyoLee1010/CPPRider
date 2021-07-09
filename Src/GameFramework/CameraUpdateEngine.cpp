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
	//camera.objVector = obj->pos; // 넣을 필요가 없음 // obj -> target
	
	camera.centerPosition.X = WINDOW_WIDTH * 0.5;		//vector -> position
	camera.centerPosition.Y = WINDOW_HEIGHT * 0.5;
	camera.angle = -1 * obj->angle;		//카메라맨 : camera, 카메라 감독 : updateEngine, 진행되는 차량 움직임의 반대로 카메라가 움직여야함.
	camera.name = obj->name;
}
