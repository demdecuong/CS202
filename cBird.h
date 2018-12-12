#ifndef cBird_h
#define cBird_h
#include "cEnemy.h"
class cBird : public cEnemy
{
	char **a; //a[3][6]
public:

	cBird(cPosition pos);
	void draw();
	char ** shape();
	void sound();
	void test();
	int getWidth()
	{
		return 6;
	}
	cBird();
	~cBird();
};
#endif // !cBird_h
