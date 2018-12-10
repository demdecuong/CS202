#ifndef cLevel_h
#define cLevel_h
#include <algorithm>
#include "cPosition.h"
#include "cEnemy.h"
class cLevel
{
private:
	int level;
	int maxEnemy, maxSpeed, nEnemy;
	int nRow;
	//  int nColumn;
	void initialize();
public:
	cLevel();
	cLevel(int level, int nEnemy);
	//  ~cLevel();
	void newLevel(int lv);
	int getMaxSpeed();
	cEnemy * randNewEnemy(cPosition pos);
	void decNEnemy();
};

#endif // cLevel