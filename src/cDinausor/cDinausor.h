
#ifndef cDinausor_h
#define cDinausor_h
#include "../cEnemy/cEnemy.h"

class cDinausor : public cEnemy
{
	int x, y;
public:
    void draw();
    void sound();
	void deleteChar();
	void move();
	int getX() {
		x = cEnemy::getX();
		return x;
	}

	int getY() {
		y = cEnemy::getY();
		return y;
	}
};
#endif
