#include <iostream>
#include <iomanip>
#include <thread>
#include <cstdlib>
#include <ctime>

#include "cMap.h"
#include "cGame.h"
#include "cTruck.h"
#include "cCar.h"
#include "cBird.h"

using namespace std;

int main() {
	srand(time(NULL));
	//DisableMouse();

	cGame game;
	game.menu();
	


	system("pause");
}