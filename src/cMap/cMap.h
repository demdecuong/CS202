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
  const int width = 300, height = 300;
  char map[301][301];
  cPlayer player;
  cRows rowsData;
  cLevel level;

public:
  cMap();
  ~cMap();
  void resetMap();
  void printMap();
  bool draw(cPosition pos,char shape[301][301], int w, int h); // draw from position pos(x, y) shape(w, h)
};

#endif // cMap
