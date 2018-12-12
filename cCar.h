#ifndef cCar_h
#define cCar_h
#include "cEnemy.h"

class cCar : public cEnemy 
{
	char **a; //a[3][8]
public:
	cCar(cPosition pos);
	char ** shape();
	void sound();
	void test();
	int getWidth()
	{
		return 8;
	}
	cCar();
	~cCar();

};
#endif // !cCar_h
