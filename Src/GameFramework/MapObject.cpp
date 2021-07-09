#include "stdafx.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>

CMapObject::CMapObject()
{
	std::string mapPath = "D:\\����ǥ\\���Ȱ��\\BOB\\������ ����� ������Ʈ\\CPPRider(Test)\\Src\\GameFramework\\MapList\\map1.txt";
	//std::string mapPath = "C:\\Users\\dldms\\Desktop\\������Ʈ ���� ����\\CPPRider\\Src\\GameFramework\\MapList\\map1.txt";
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

void CMapObject::Draw(CRendererForGame* renderer, Camera camera)//�̸��� �ǹ��ְ��ؼ� �������� ������
{	
	extern Camera camera;
	extern CKartObject myKart;
	CVECTOR movedCamPosition =  myKart.pos - camera.centerPosition;	// -> �������� �����
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
