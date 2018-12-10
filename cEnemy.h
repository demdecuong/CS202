#ifndef cEnemy_h
#define cEnemy_h
#include <Windows.h>
#include <mmsystem.h>
#include "cPosition.h"

class cEnemy
{
private:
	cPosition point;
	bool outMap;
public:
	int getX()
	{
		return point.getX();
	}
	int getY()
	{
		return point.getY();
	}
	cEnemy();
	// create new enemy with starting position
	cEnemy(cPosition st)
	{
		point = st;
	}
	virtual ~cEnemy() = default;
	//  virtual void draw() =0;
	cPosition getPos();
	bool isOutOfMap();
	void goOutMap();
	virtual int getWidth() = 0;
	int getHeight();
	virtual char ** shape()= 0; // return the shape of enemy to draw
	virtual void sound() = 0;
};

#endif // cEnemy
