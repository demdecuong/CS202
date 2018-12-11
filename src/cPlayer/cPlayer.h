#pragma once
#ifndef cPlayer_h

#define cPlayer_h

#include <stdio.h>

#include "../cPosition/cPosition.h"

#include "../cConsole/cConsole.h"

#include "../cEnemy/cEnemy.h"



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

	bool crash(cEnemy* e) {
		return (abs(getX()-e->getX()) <=4 && abs(getY()-e->getY()) <= 2);
	}

	void deleteChar();

	bool isFinish() {
		if (pY == 1) return true; 
		else return false;
	}

	int getX() {
		return pos.getX();
	}

	int getY() {
		return pos.getY();
	}

	//void move(char moving);

};



#endif // cPlayer