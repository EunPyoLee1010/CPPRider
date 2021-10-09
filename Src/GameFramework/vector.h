#pragma once
#include <Windows.h>
#include <math.h>
#include "struct.h"

#define PI	3.14159265358979323846

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

	bool operator<(int num)
	{
		return (X < num) && (Y < num);
	}

	bool operator>(int num)
	{
		return (X > num) && (Y > num);
	}

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

	CVECTOR operator+(int number)
	{
		CVECTOR sum;
		sum.X = X + number;
		sum.Y = Y + number;

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

	CVECTOR RotateCntClockwise(double angle) 
	{
		double radian = angle * PI / 180;
		CVECTOR tmp;
		tmp.X = X * cos(radian) - Y * sin(radian);
		tmp.Y = X * sin(radian) + Y * cos(radian);

		return tmp;
		//http://egloos.zum.com/scripter/v/1618411
		//https://gammabeta.tistory.com/913
	}

	CVECTOR RotateClockwise(double angle)
	{
		double radian = angle * PI / 180;
		CVECTOR tmp;
		tmp.X = X * cos(radian) + Y * sin(radian);
		tmp.Y = -1 * X * sin(radian) + Y * cos(radian);

		return tmp;
	}

	double DotProduct(CVECTOR& dotProdVec) 
	{
		return (X * dotProdVec.X) + (Y * dotProdVec.Y);
	}


	ENUM_MAP_SECTION getMapSection() 
	{
		if ((X > 999 || X < 0) || (Y > 999 || Y < 0)) 
		{
			return MAP_SECTION_OUTSIDE;
		}
		if ((X > 300 && X < 600) && (Y > 200 && Y < 800)) 
		{
			return MAP_SECTION_WALL;
		}
		return MAP_SECTION_TRACK;
	}
};