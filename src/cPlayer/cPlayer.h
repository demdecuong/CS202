#ifndef cPlayer_h
#define cPlayer_h

#include "../cPosition/cPosition.h"
#include "../cEnemy/cEnemy.h"
#include "../cBird/cBird.h"
#include "../cCar/cCar.h"
#include "../cDinausor/cDinausor.h"
#include "../cTruck/cTruck.h"
#include "../cConsole/cConsole.h"
#include <cmath>

class cPlayer: public cPosition{
private:
    cPosition pos;
    bool isDead;
public:
    cPlayer(/* args */);
    cPlayer(int,int);
    ~cPlayer(){ };
    void Up();
    void Down();
    void Right();
    void Left();
    bool checkIsDead();
    void killPlayer(); // set isDead
    void reset();
    void deleteChar();
    bool crash(cTruck*p, int lv);
};

#endif // cPlayer
