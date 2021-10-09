#include "stdafx.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>
#include "struct.h"

CMapObject::CMapObject() :
	mapIndexWidth(2),
	mapIndexHeight(2)
{
	//std::string mapPath = "D:\\이은표\\대외활동\\BOB\\전상현 멘토님 프로젝트\\CPPRider\\Src\\GameFramework\\MapList\\map1.txt";
	std::string mapPath = "C:\\Users\\dldms\\Desktop\\프로젝트 개발 폴더\\CPPRider\\Src\\GameFramework\\MapList\\map2.txt";
	//std::string mapPath = "map2.txt";
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
	extern CKartObject myKart;
	if (myKart.isBoost) {
		if (myKart.boostTime > 0)
			camera.centerPosition.X += myKart.boostTime % 2 == 0 ? -2 : 2;
		if (myKart.boostTime >= 100)
			camera.centerPosition.X += myKart.boostTime % 2 == 0 ? -1 : 1;
		if (myKart.boostTime >= 200)
			camera.centerPosition.X += myKart.boostTime % 2 == 0 ? -1 : 1;
	}
	CVECTOR movedCamPosition =  myKart.pos - camera.centerPosition;	// -> 쓸데없이 길어짐
	CVECTOR mapIndexPosition;
	CVECTOR centRelPosition;
	CVECTOR rotatedPosition;

	for (int y = movedCamPosition.Y; y < movedCamPosition.Y + WINDOW_HEIGHT; y++) 
	{
		if (y < 0 || y > 999)
			continue;
		for (int x = movedCamPosition.X; x < movedCamPosition.X + WINDOW_WIDTH; x++)
		{
			if (x < 0 || x > 999)
				continue;
			if (mapContainer[y][x])
			{
				int copyX = x;
				{
					centRelPosition = mapIndexPosition(x, y) - myKart.pos;
					rotatedPosition = centRelPosition.RotateClockwise(camera.angle);
					CVECTOR newPosition = rotatedPosition(int(rotatedPosition.X), int(rotatedPosition.Y)) + myKart.pos - movedCamPosition;

					int tmpX = 1;
					if(mapContainer[y][x + 1] == 1)
					{
						tmpX++;
						x++;
					}
					int tmpY = 1;
					if (mapContainer[y + 1][x] == 1)
					{
						tmpY++;
						y++;
					}

					int left = newPosition.X - (mapIndexWidth * 0.5) * tmpX;
					int right = newPosition.X + (mapIndexWidth * 0.5);
					int top = (WINDOW_WIDTH - newPosition.Y) - (mapIndexHeight * 0.5);
					int bottom = (WINDOW_WIDTH - newPosition.Y) + (mapIndexHeight * 0.5) * tmpY;

					CVECTOR edge[4];
					edge[0](left, top);
					edge[1](right, top);
					edge[2](right, bottom);
					edge[3](left, bottom);

					POINT rotatedEdge[4];
					for (int i = 0; i < 4; i++)
					{
						rotatedEdge[i] = { int(edge[i].X), int(edge[i].Y) };
					}
					if (mapContainer[y][x] == 1)
						renderer->Polygon(rotatedEdge, RGB(0, 0, 0));
					if (mapContainer[y][x] == 2)
						renderer->Polygon(rotatedEdge, RGB(0, 255, 0));
					if (mapContainer[y][x] == 6) 
					{
						if((x % 5) == 0 && (x / 5) % 2 == 0)
							renderer->Polygon(rotatedEdge, RGB(0, 0, 0));
						if ((x % 5) == 0 && (x / 5) % 2 == 1)
							renderer->Polygon(rotatedEdge, RGB(255, 255, 255));
					}
				}

			}
		}
	}
}

bool CMapObject::isCollide(CVECTOR position) 
{
	CVECTOR intPosition(int(position.X), int(position.Y));
	//if (intPosition.X < 0 || intPosition.Y < 0 || intPosition.X > 999 || intPosition.Y > 999)
	//	return true;
	if (intPosition.getMapSection() != MAP_SECTION_TRACK) 
	{
		return true;
	}
	if (mapContainer[int(intPosition.Y)][int(intPosition.X)] == 1) 
	{
		printf("Collided at %f, %f\n", intPosition.X, intPosition.Y);
	}
	return mapContainer[int(intPosition.Y)][int(intPosition.X)] == 1;
}