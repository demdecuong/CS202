#include "cLevel.h"

cLevel::cLevel() {
	level = 1;
	nEnemy = 0;
	initialize();
}

cLevel::cLevel(int level, int nEnemy) {
	this->level = level;
	this->nEnemy = nEnemy;
	initialize();
}

void cLevel::initialize() {
	int difficulty = 1000, maxE = 20;
	if (constantVar::isHard) difficulty = 50, maxE = 200;
	nRow = min(10, 3 + (level / 3));
	maxEnemy = min(maxE, nRow * 10);
	maxSpeed = difficulty- level * 3;
	minSpeed = difficulty - level * 2;
}

int cLevel::getLevel() {
	return level;
}

bool cLevel::newLevel(int lv) {
	if (lv > maxLevel) return false;
	level = lv;
	nEnemy = 0;
	initialize();
	return true;
}

bool cLevel::nextLevel() {
	if (level == maxLevel) return false;
	++level;
	nEnemy = 0;
	return true;
}

int cLevel::getMaxSpeed() {
	return maxSpeed;
}

int cLevel::getMinSpeed() {
	return minSpeed;
}

cEnemy * cLevel::randNewEnemy(cPosition pos) {
	if (nEnemy == maxEnemy) return NULL;
	if ((nEnemy < (maxEnemy / 2)) || (rand() % 3)) {
		++nEnemy;
		cEnemy * pEnemy = NULL;
		int type = rand() % 4;
		switch (type)
		{
		case 0: {
			pEnemy = new cBird(pos);
			break;
		}
		case 1: {
			pEnemy = new cCar(pos);
			break;
		}
		case 2: {
			pEnemy = new cDinosaur(pos);
			break;
		}
		default:
			pEnemy = new cTruck(pos);
			break;
		}
		//    pEnemy = new cEnemy(pos); //choose a random type of enemy
		return pEnemy;
	}
	return NULL;
}

cEnemy * cLevel::getNewEnemy(cPosition pos, int type) {
	++nEnemy;
	cEnemy * pEnemy = NULL;
	switch (type)
	{
	case 0: {
		pEnemy = new cBird(pos);
		break;
	}
	case 1: {
		pEnemy = new cCar(pos);
		break;
	}
	case 2: {
		pEnemy = new cDinosaur(pos);
		break;
	}
	default:
		pEnemy = new cTruck(pos);
		break;
	}
	//    pEnemy = new cEnemy(pos); //choose a random type of enemy
	return pEnemy;
}

void cLevel::decNEnemy(int d) {
	nEnemy -= d;
}
