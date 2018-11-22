#ifndef cPlayer_h
#define cPlayer_h

#include "../cPosition/cPosition.h"
#include "../cEnemy/cEnemy.h"

class cPlayer
{
private:
    cPosition pos;
    bool isDead;
public:
    cPlayer(/* args */);
    ~cPlayer();
    void Up();
    void Down();
    void Right();
    void Left();
    bool checkIsDead();
    void killPlayer(); // set isDead
    void draw();
    bool crash(cEnemy);
};

#endif // cPlayer
