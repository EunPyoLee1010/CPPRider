#pragma once
#include <Windows.h>
#include <math.h>
struct CVECTOR
{
	double X;
	double Y;
	CVECTOR() :
		X(0),
		Y(0)
	{}
	CVECTOR(int x, int y) :
		X(x),
		Y(y)
	{}

	CVECTOR operator=(CVECTOR Vector)
	{
		X = Vector.X;
		Y = Vector.Y;

		return *this;
	}

	CVECTOR operator+(CVECTOR& addVector)
	{
		CVECTOR sum;
		sum.X = X + addVector.X;
		sum.Y = Y + addVector.Y;

		return sum;
	}

	CVECTOR operator-(CVECTOR& subVector)
	{
		CVECTOR sub;
		sub.X = X - subVector.X;
		sub.Y = Y - subVector.Y;

		return sub;
	}

	CVECTOR operator()(int x, int y) 
	{
		X = x;
		Y = y;
		return *this;
	}

	CVECTOR RotateCntClockwise(double radian) 
	{
		CVECTOR tmp;
		tmp.X = X * cos(radian) - Y * sin(radian);
		tmp.Y = X * sin(radian) + Y * cos(radian);

		return tmp;
		//http://egloos.zum.com/scripter/v/1618411
		//https://gammabeta.tistory.com/913
	}

	CVECTOR RotateClockwise(double radian)
	{
		CVECTOR tmp;
		tmp.X = X * cos(radian) + Y * sin(radian);
		tmp.Y = -1 * X * sin(radian) + Y * cos(radian);

		return tmp;
	}
};

//double radian = ((angle)) * PI / 180;
	//int left = posX - width * 0.5;
	//int right = posX + width * 0.5;
	//int top = (WINDOW_HEIGHT - posY) - height * 0.5;
	//int bottom = (WINDOW_HEIGHT - posY) + height * 0.5;
	//int textLength = strlen(name.c_str());

	//POINT edge[4];
	//edge[0] = { int((left - posX) * cos(radian) - (top - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((top - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	//edge[1] = { int((right - posX) * cos(radian) - (top - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((top - (WINDOW_HEIGHT - posY)) * cos(radian) + (right - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	//edge[2] = { int((right - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (right - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };
	//edge[3] = { int((left - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX), int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) };

	//renderer->Polygon(edge, RGB(0, 0, 255));
	//renderer->Text(int((left - posX) * cos(radian) - (bottom - (WINDOW_HEIGHT - posY)) * sin(radian) + posX) - (textLength * 0.5) * 5,
	//	int((bottom - (WINDOW_HEIGHT - posY)) * cos(radian) + (left - posX) * sin(radian) + (WINDOW_HEIGHT - posY)) + 5, RGB(0, 0, 0), name);





