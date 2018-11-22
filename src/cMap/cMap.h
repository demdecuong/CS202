#ifndef cMap_h
#define cMap_h

#include <iostream>
#include <string>
#include "../cPlayer/cPlayer.h"
#include "../cPosition/cPosition.h"
#include "../cRows/cRows.h"
#include "../cLevel/cLevel.h"

using namespace std;

class cMap
{
   	//old figure: width=height =300
	const int width = 115, height = 35;
	char map[116][36];
	cPlayer player;
	cRows rowsData;
	cLevel level;
public:
    cMap();
    ~cMap();
    void resetMap(); // reset the map to default with no enemy and no player
    void printMap();
    bool draw(cPosition pos,char shape[301][301], int w, int h); // draw from position pos(x, y) shape(w, h)
    void drawPlayer(); // draw player to map, check if crash => kill player
    void drawEnemies(cEnemy enemy); // draw enemy to map
    void randomNextState(); // generate new enemies base on level and push to rows
    void initializeNewState(); // intialize a new map base on level, reset player state
    void handleKeyInput(); // receive key input from cGame and call appropriate function
};

#endif // cMap
