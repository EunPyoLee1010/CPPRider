#include "stdafx.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>

CMapObject::CMapObject()
{
	//std::string mapPath = "D:\\이은표\\대외활동\\BOB\\전상현 멘토님 프로젝트\\CPPRider\\Src\\GameFramework\\Map\\map1.txt";
	std::string mapPath = "C:\\Users\\dldms\\Desktop\\프로젝트 개발 폴더\\CPPRider\\Src\\GameFramework\\MapList\\map1.txt";
	std::ifstream openFile;
	std::istringstream ss;

	openFile.open(mapPath.data());
	if (openFile.is_open()) 
	{
		std::string line = "";
		int j = 0;
		while (getline(openFile, line))
		{
			char mapLine[1000] = {0,};
			int i = 0;
			ss.clear();
			ss.str(line);
			while (getline(ss, line, ','))
			{
				mapLine[i++] = stoi(line);
			}
			memcpy(mapContainer[j++], mapLine, 1000);
		}
		openFile.close();
	}
}

CMapObject::~CMapObject()
{
}

void CMapObject::Draw(CRendererForGame* renderer, CVECTOR screen)
{	
	extern Camera view;
	extern CKartObject myKart;

	CVECTOR movedCamVec = view.objVector - view.centVector;

	for (int i = int(myKart.pos.Y) - 250; i < int(myKart.pos.Y) + 250; i++)
	{
		if (i < 0 || i > 999)
			continue;
		for (int j = int(myKart.pos.X) - 250; j < int(myKart.pos.X) + 250; j++)
		{
			if (j < 0 || j > 999)
				continue;

			if (mapContainer[i][j] == 2)
			{
				int left = j - movedCamVec.X - 0.5;
				int top = (WINDOW_HEIGHT - i + movedCamVec.Y) - 0.5;
				int right = j - movedCamVec.X + 0.5;
				int bottom = (WINDOW_HEIGHT - i + movedCamVec.Y) + 0.5;
				renderer->Ellipse(left, top, right, bottom, RGB(0, 255, 0));
			}

			if (mapContainer[i][j] == 1)
			{
				//int left = j - MovedCameraX - 0.5;
				//int top = (WINDOW_HEIGHT - i + MovedCameraY) - 0.5;
				//int right = j - MovedCameraX + 0.5;
				//int bottom = (WINDOW_HEIGHT - i + MovedCameraY) + 0.5;

				//double radian = (myKart.angle) * PI / 180;

				//POINT edges[4] =
				//{
				//	{left * cos(radian) + top * sin(radian), top * cos(radian) - left * sin(radian)},
				//	{right * cos(radian) + top * sin(radian), top * cos(radian) - right * sin(radian)},
				//	{right * cos(radian) + bottom * sin(radian), bottom * cos(radian) - right * sin(radian)},
				//	{left * cos(radian) + bottom * sin(radian), bottom * cos(radian) - left * sin(radian)}
				//};

				//renderer->Polygon(edges, RGB(0, 0, 0));

				int left = j - movedCamVec.X - 0.5;
				int top = (WINDOW_HEIGHT - i + movedCamVec.Y) - 0.5;
				int right = j - movedCamVec.X + 0.5;
				int bottom = (WINDOW_HEIGHT - i + movedCamVec.Y) + 0.5;
				renderer->Rectangle(left, top, right, bottom, RGB(0, 0, 0));
			}
		}
	}
}
