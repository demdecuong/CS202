
#ifndef cEnemy_h
#define cEnemy_h

#include "../cPosition/cPosition.h"


class cEnemy
{
private:
	cPosition point;
public:
	int getX()
	{
		return point.getX();
	}
	int getY()
	{
		return point.getY();
	}
  cEnemy() = default;
  cEnemy(cPosition st); // create new enemy with starting position
  ~cEnemy() = default;
//  virtual void draw() =0;
  virtual char ** shape() =0; // return the shape of enemy to draw
  virtual void sound() =0;
};

#endif // cEnemy
