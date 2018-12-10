#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "./cMap/cMap.h"
#include "cConsole/cConsole.h"
using namespace std;

// print log to log.txt so that we can track easily, should be called in every function
// only on development
void printLog(string logString) {
  ofstream out;
  out.open("log.txt", ofstream::out | ofstream::app);
  out << logString << endl;
  out.close();
}

// control thread = main thread -> no need to detach
// enemy thread
// player thread
// printLog thread

// void inputLoop(int& inputState) {
//     while (1) {
//         inputState = inputKey();
//     }
// }
int main() {
    // cGame game;
    // game.newGame();

    // thread gameThread(game.playGame);
    // gameThread.detach();

    // cPlayer player;
    // player.draw();
    // int inputState;
    // while (1) {
    //     inputState = inputKey();
    //     if (inputState  == 'P') {
    //         game.togglePauseGame();
    //     }
    //     if (inputState == 'W') {
    //         player.Up();
    //     }
    //     if (inputState == 'S') {
    //         player.Down();
    //     }
    //     if (inputState == 'A') {
    //         player.Left();
    //     }
    //     if (inputState == 'D') {
    //         player.Right();
    //     }
    // }

    // printLog("Running main . . .");
    // cout << "This is main" << endl;
    // return 0;
  printLog("Running main . . .");
  cMap map;
  map.printMap();
  return 0;
}
