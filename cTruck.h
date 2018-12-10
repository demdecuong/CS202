#ifndef cTruck_h
#define cTruck_h
#include "cEnemy.h"

class cTruck : public cEnemy
{
	char** a; //a[3][8]
public:
	char **shape();
	void sound();
	void test();
	int getWidth()
	{
		return 7;
	}
	cTruck();
	~cTruck();
};
#endif 
