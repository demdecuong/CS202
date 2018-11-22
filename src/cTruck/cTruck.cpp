
#include "cTruck.h"
#include "cConsole.h"
using namespace std;

void cTruck::draw()
{
	int x = cTruck::cEnemy::getX();
	int y = cTruck::cEnemy::getY();
	gotoXY(x , y);
	cout << (char)218;
	for (int i = 0; i < 6; i++)
		cout << char(196);
	cout << (char)191;
	
	cout << endl;
	cout << (char)179 << "     [" << (char)179;
	cout << endl;
	cout << (char)192;
	for (int i = 0; i < 6; i++) {
		if (i == 0 || i == 5)cout << "O";
		else
			cout << (char)196;
	}
	cout << (char)217;
}
