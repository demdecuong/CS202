
#ifndef cTruck_h
#define cTruck_h
#include "../cEnemy/cEnemy.h"


class cTruck : public cEnemy
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
