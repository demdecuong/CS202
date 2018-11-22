
#include "cCar.h"
#include "cConsole.h"
using namespace std;

void cCar::draw()
{
	int x = cCar::cEnemy::getX();
	int y = cCar::cEnemy::getY();
	gotoXY(x, y);
	cout << " ";
	for (int i = 0; i < 5; i++)
		cout << "_";
	cout << " ";
	gotoXY(x, y + 1);
	cout << "/    "<<(char)220<<"\\" ;
	gotoXY(x, y + 2);
	for (int i = 0; i < 7; i++) {
		if (i == 0)cout << (char)240;
		else
		if (i == 1 || i == 5)cout << "O";
		else
			//cout << (char)196;
			cout << '-';
	}
	cout << (char)217;
}
