#ifndef cPlayer_h
#define cPlayer_h

#include "cPosition.h"
#include "cEnemy.h"
#include "cBird.h"
#include "cCar.h"
#include "cDinosaur.h"
#include "cTruck.h"
#include <cmath>


class cPlayer
{
private:
	cPosition pos;
	bool isDead;
	char ** a;
	int width, height;
public:
	cPlayer() = default; // set default position
	cPlayer(cPosition pos); // set current position when load game
	~cPlayer() = default;
	void Up();
	void Down();
	void Right();
	void Left();
	//    bool checkIsDead();
	void killPlayer(); // set isDead
	void draw();
	char ** shape();
	cPosition getPos();
	int getWidth();
	int getHeight();
	//    bool crash(cEnemy);
};

#endif // cPlayer