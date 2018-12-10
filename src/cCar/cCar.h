#ifndef cCar_h
#define cCar_h
#include "../cEnemy/cEnemy.h"

class cCar : public cEnemy 
{
private:
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
#endif // !cCar_h

