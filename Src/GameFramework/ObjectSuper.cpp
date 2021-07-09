#include "stdafx.h"
#include "ObjectSuper.h"
#include "RendererForGame.h"

CObjectSuper::CObjectSuper() :
	angle(0),
	pos(0,0),
	width(10),
	height(30),
	name("Kart")
{
}

CObjectSuper::~CObjectSuper()
{
}

void CObjectSuper::Draw(CRendererForGame* renderer,  Camera camera)
{
}

