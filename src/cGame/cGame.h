#ifndef cGame_h
#define cGame_h

#include <iostream>
#include "../cMap/cMap.h"
#include "../cEnemy/cEnemy.h"
#include "../cBird/cBird.h"
#include "../cCar/cCar.h"
#include "../cDinausor/cDinausor.h"
#include "../cTruck/cTruck.h"

class cGame: public cMap{
    cPlayer player;
    cMap map;
    bool isPausing = false;
    cTruck* truck;
    cCar* car;
    cBird* bird;
    cDinausor* dinausor;
    int level;
public:
    cGame();
    ~cGame();
    void GameSettings();
    int& getLevel();
    void logIn();
    void newGame(); // start a new Game, initialize cMap map
    void loadGame(); // get file of cMap map
    void saveGame(); // print file of cMap map
    void resetGame(int lv);
    void togglePauseGame(); // toggle status of isPausing
    void resumeGame();
    
    void lvUp();
    void playGame(); // manage Game process: randomNextState, draw (tick time)
    bool isRunning();
    cPlayer getPlayer();
    void updatePosAnimal();
    void updatePosVehicle();
    
    cTruck* getTruck();
    cBird* getBird();
    cCar* getCar();
    cDinausor* getDinausou();
    
    void updatePosPlayer(char moving);
    
    
    void quitGame();
    void GameOver();
};

#endif // cGame


