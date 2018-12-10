#include "cBird.h"
#include "../cConsole/cConsole.h"
using namespace std;

void cBird::draw() {
	cout << "B";
}

void cBird::move() {
	cEnemy::move();
}
void cBird::deleteChar() {
	cEnemy::deleteChar();
}