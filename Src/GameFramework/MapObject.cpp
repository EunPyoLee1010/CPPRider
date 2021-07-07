#include "stdafx.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>

CMapObject::CMapObject()
{
	std::string mapPath = "D:\\이은표\\대외활동\\BOB\\전상현 멘토님 프로젝트\\CPPRider\\Src\\GameFramework\\MapList\\map1.txt";
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

void CMapObject::Draw(CRendererForGame* renderer, CVECTOR screen)
{	
	extern Camera view;

	CVECTOR movedCamVec = view.objVector - view.centVector;
	CVECTOR index;
	CVECTOR centRelVec;
	CVECTOR rotatedVec;
	for (int y = view.objVector.Y - 250; y < view.objVector.Y + 250; y++)
	{
		if (y < 0 || y > 999)
			continue;
		for (int x = view.objVector.X - 250; x < view.objVector.X + 250; x++)
		{
			if (x < 0 || x > 999)
				continue;
			if (mapContainer[y][x] == 1)
			{
				index(x, y);
				centRelVec = index - view.objVector - movedCamVec;
				rotatedVec = centRelVec.RotateCntClockwise(view.angle);
				screen = rotatedVec + view.objVector;

				int left = screen.X - 0.5;
				int right = screen.X + 0.5;
				int top = (WINDOW_HEIGHT - screen.Y) - 0.5;
				int bottom = (WINDOW_HEIGHT - screen.Y) + 0.5;

				renderer->Rectangle(left, top, right, bottom, RGB(0, 0, 0));
			}
		}
	}
}
