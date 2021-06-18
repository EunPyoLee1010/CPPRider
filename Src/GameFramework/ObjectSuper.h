#pragma once
class CObjectSuper
{
public:
	CObjectSuper();
	~CObjectSuper();

	virtual void Draw();

	int posX;
	int posY;

	void Move(double vel, int angle);
private:

};

