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

void CMapObject::Draw(CRendererForGame* renderer, POINT screen)
{	
	extern Camera view;
	extern CKartObject myKart;

	int MovedCameraX = view.objectX - view.centeredScreenX;
	int MovedCameraY = view.objectY - view.centeredScreenY;

	for (int i = int(myKart.posY) - 250; i < int(myKart.posY) + 250; i++)
	{
		if (i < 0 || i > 999)
			continue;
		for (int j = int(myKart.posX) - 250; j < int(myKart.posX) + 250; j++)
		{
			if (j < 0 || j > 999)
				continue;

			if (mapContainer[i][j] == 2)
			{
				int left = j - MovedCameraX - 0.5;
				int top = (WINDOW_HEIGHT - i + MovedCameraY) - 0.5;
				int right = j - MovedCameraX + 0.5;
				int bottom = (WINDOW_HEIGHT - i + MovedCameraY) + 0.5;
				renderer->Ellipse(left, top, right, bottom, RGB(0, 255, 0));
			}

			if (mapContainer[i][j] == 1)
			{
				int left = j - MovedCameraX - 0.5;
				int top = (WINDOW_HEIGHT - i + MovedCameraY) - 0.5;
				int right = j - MovedCameraX + 0.5;
				int bottom = (WINDOW_HEIGHT - i + MovedCameraY) + 0.5;
				renderer->Ellipse(left, top, right, bottom, RGB(0, 0, 0));
			}
		}
	}

	//for (int i = 0; i < 500; i++)
	//{
	//	for (int j = 0; j < 500; j++)
	//	{
	//		if (mapContainer[i][j] == 2 || mapContainer[i][j] == 1)
	//		{
	//			int left = j - 0.5;
	//			int top = (WINDOW_HEIGHT - i) - 0.5;
	//			int right = j + 0.5;
	//			int bottom = (WINDOW_HEIGHT - i) + 0.5;
	//			if(mapContainer[i][j] == 2)
	//				renderer->Ellipse(left, top, right, bottom, RGB(0, 255, 0));
	//			if(mapContainer[i][j] == 1)
	//				renderer->Rectangle(left, top, right, bottom, RGB(0, 0, 0));
	//		}
	//	}
	//}
}
