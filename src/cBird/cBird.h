
#ifndef cBird_h
#define cBird_h
#include "../cEnemy/cEnemy.h"

class cBird : public cEnemy
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
