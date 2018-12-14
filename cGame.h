#ifndef cGame_h
#define cGame_h


#include <iostream>
#include <fstream>
#include <thread>
//#include <dirent.h>

#include "cConsole.h"
#include "cPlayer.h"
#include "cEnemy.h"
#include "cRows.h"
#include "cMap.h"

using namespace std;

class cGame
{	
	bool isLoaded = false;
	cMap map;
	bool isPausing = false;
public:

	cGame() = default;

	~cGame() = default;

	void gameSettings();

	void menu(bool &isFinish);

	bool newGame(); // start a new game, initialize cMap map

	bool continueGame();  //continue our game

	bool loadGameMenu(); // get file of cMap map

	void saveGameMenu(); //void saveGame(); // print file of cMap map

	void pauseMenu(int cmd);

	void togglePauseGame(); // toggle status of isPausing

	void toggleMute();

	void toggleHard();

	void gameOver();

	void playGame(bool &is_finish);

	void testThread();

	void loading();

	vector<string> getAllFilename(const std::string& name);

	void menu();

	bool continueMenu();
};

void SubThread(cGame*cg, bool *IS_RUNNING, bool *isPausing, bool *exitFlag);
#endif // cGame
