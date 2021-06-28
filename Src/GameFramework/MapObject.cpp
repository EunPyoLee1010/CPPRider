#include "stdafx.h"
#include "MapObject.h"
#include <fstream>
#include <sstream>


CMapObject::CMapObject()
{
	std::string mapPath = "Map/map1.txt";
	std::ifstream openFile("map1.txt");
	std::istringstream ss;
	if (openFile.is_open()) 
	{
		std::string line;
		int j = 0;
		while (getline(openFile, line))
		{
			char mapLine[1000] = {0,};
			int i = 0;
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

void CMapObject::Draw()
{
}
