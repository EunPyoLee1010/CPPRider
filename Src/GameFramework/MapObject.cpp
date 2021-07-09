#include "stdafx.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>

CMapObject::CMapObject()
{
	std::string mapPath = "D:\\이은표\\대외활동\\BOB\\전상현 멘토님 프로젝트\\CPPRider(Test)\\Src\\GameFramework\\MapList\\map1.txt";
	//std::string mapPath = "C:\\Users\\dldms\\Desktop\\프로젝트 개발 폴더\\CPPRider\\Src\\GameFramework\\MapList\\map1.txt";
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

void CMapObject::Draw(CRendererForGame* renderer, Camera camera)//이름을 의미있게해서 가독성을 높이자
{	
	extern Camera camera;
	extern CKartObject myKart;
	CVECTOR movedCamPosition =  myKart.pos - camera.centerPosition;	// -> 쓸데없이 길어짐
	CVECTOR index;
	CVECTOR centRelVec;
	CVECTOR rotatedVec;
	for (int y = myKart.pos.Y - 250; y < myKart.pos.Y + 250; y++)
	{
		if (y < 0 || y > 999)
			continue;
		for (int x = myKart.pos.X - 250; x < myKart.pos.X + 250; x++)
		{
			if (x < 0 || x > 999)
				continue;
			if (mapContainer[y][x] == 1)
			{
				CVECTOR screenPosition = index(x, y) - movedCamPosition;
				screenPosition = screenPosition.RotateCntClockwise(camera.angle);
				screenPosition = screenPosition + movedCamPosition;

				int left = screenPosition.X - 0.5;
				int right = screenPosition.X + 0.5;
				int top = (WINDOW_HEIGHT - screenPosition.Y) - 0.5;
				int bottom = (WINDOW_HEIGHT - screenPosition.Y) + 0.5;

				POINT edge[4] = {
					{left, top},
					{left, bottom},
					{right, top},
					{right, bottom},
				};
				renderer->Polygon(edge, RGB(0, 0, 0));
			}
		}
	}
}
