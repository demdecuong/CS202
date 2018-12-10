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

	const cPosition constPos{5,10};

	// int pX = 10, pY = 10;

	bool isDead;

	char ** a;

	int width=1, height=1;

public:

	cPlayer() = default; // set default position

	cPlayer(cPosition pos); // set current position when load game

	~cPlayer() = default;
	
	bool crash(cEnemy *d) {
		if (pX == d->GetX() && pY == d->GetY()) return true;
		else return false;
	}
	
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
		if (pY == 1) return true; //
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