#pragma once
#ifndef cEnemy_h

#define cEnemy_h


#include "../cConsole/cConsole.h"
#include "../cPosition/cPosition.h"


class cEnemy

{

private:

    int mX=1, mY=5;

	cPosition point;

	bool outMap;

public:

	cPosition getPos();

	int getX()

	{

		return point.getX();

	}

	int getY()

	{

		return point.getY();

	}

	cEnemy();

	cEnemy(cPosition st); // create new enemy with starting position

	virtual ~cEnemy() = default;

	//  virtual void draw() =0;

	virtual char ** shape() = 0; // return the shape of enemy to draw

	virtual void sound() = 0;

	bool isOutOfMap();

	void goOutMap();

	int getWidth();

	int getHeight();


	//demo =====================================================
	void deleteChar() { 
		gotoXY(mX, mY);
		cout << " ";
	}
	void move() {
		deleteChar();
		mX += 1;
		if (mX == 30) mX = 1;
		gotoXY(mX, mY);
		draw();
		Sleep(100);
	}
	void draw() {
		cout << "D";
	}
	int GetX() {
		return mX;
	}
	int GetY() {
		return mY;
	}
};

#endif // cEnemy