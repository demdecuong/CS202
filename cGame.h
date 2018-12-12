#ifndef cGame_h
#define cGame_h


#include <iostream>
#include <fstream>
#include <thread>

#include "cConsole.h"
#include "cPlayer.h"
#include "cEnemy.h"
#include "cRows.h"
#include "cMap.h"

using namespace std;

class cGame  
{
	cMap map;
	bool isPausing = false;

public:

	cGame() = default;

	~cGame() = default;

	void gameSettings();

	void menu(bool &isFinish);

	void newGame(); // start a new game, initialize cMap map

	void loadGame(); // get file of cMap map

	//void saveGame(); // print file of cMap map

	void togglePauseGame(); // toggle status of isPausing

	void gameOver();

	void playGame(bool &is_finish);
	
	void testThread();


};
void SubThread(cGame*cg, bool *IS_RUNNING, bool *isPausing, bool *exitFlag);
#endif // cGame
