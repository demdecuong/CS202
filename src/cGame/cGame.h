#pragma once
#ifndef cGame_h

#define cGame_h



#include <iostream>

#include "cMap.h"

#include "cConsole.h"

#include "cPlayer.h"

#include "cEnemy.h"



class cGame {
	int level;
	cPlayer player;
	cEnemy *d;
	bool isPausing = false;

public:

	cGame() {
		d = new cEnemy;
		isPausing = false; }

	~cGame() { }

	void gameSettings();

	void menu(bool &isFinish); 

	void newGame(); // start a new game, initialize cMap map

	void loadGame(); // get file of cMap map

	void saveGame(); // print file of cMap map

	//void togglePauseGame(); // toggle status of isPausing

	void playGame(bool &is_finish); // manage game process: randomNextState, draw (tick time)

	void quitGame(thread *t1, bool &IS_RUNNING);

	cEnemy* getAnimal() {
		return d;
	}

	//void gameOver();

	void updatePosPlayer(char moving);

	void updatePosEnemy() {
		d->move();
	}

	//void SubThread(cGame*cg, bool *IS_RUNNING, bool *isPausing, bool *exitFlag);

	cPlayer getPlayer() {
		return player;
	}

};
void startGame(bool &reset,int level);
void SubThread(cGame*cg, bool *IS_RUNNING, bool *isPausing, bool *exitFlag);
#endif // cGame