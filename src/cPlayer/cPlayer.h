#pragma once
#ifndef cPlayer_h

#define cPlayer_h


#include"cEnemy.h"
#include <stdio.h>

#include "cPosition.h"

#include "cConsole.h"

//#include "../cEnemy/cEnemy.h"



class cPlayer

{

private:

	cPosition pos;

	int pX = 10, pY = 10;

	bool isDead;

	char ** a; //[3][5]

	int width=1, height=1;

public:

	cPlayer(); // set default position

	cPlayer(cPosition pos); // set current position when load game

	~cPlayer();
	
	//cai nay demo thoi 
	/*bool crash(cEnemy *d) { 
		if (pX == d->GetX() && pY == d->GetY()) return true;
		else return false;
	}*/
	
	void Up();

	void Down();

	void Right();

	void Left();

	//    bool checkIsDead();

	void killPlayer(); // set isDead

	bool checkisDead() {
		return isDead;
	}

	void draw();

	char ** shape();

	cPosition getPos();

	int getWidth();

	int getHeight();

	//    bool crash(cEnemy);

	void deleteChar();

	bool isFinish() {
		if (pY == 1) return true; 
		else return false;
	}

	int getX() {
		return pX;
	}

	int getY() {
		return pY;
	}

	//void move(char moving);

};



#endif // cPlayer