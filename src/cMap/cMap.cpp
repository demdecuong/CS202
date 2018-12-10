#include "cMap.h"
//#include "cConsole.h"

cMap::cMap() {
    resetMap();
}

void cMap::resetMap(){
    for (int i = 0; i <= width + 1; i++){
        map[0][i] = map[height + 1][i] = '-';
    }
    for (int i = 1; i <= height; ++i) {
        map[i][0] = map[i][width + 1] = '|';
        for (int j = 1; j <= width; ++j) {
            map[i][j] = ' ';
        }
    }
}

void cMap::printMap()
{
//    TextColor(14);
    for (int i = 0; i <= height + 1; ++i) {
        for (int j = 0; j <= width + 1; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }
}

int cMap::draw(cPosition pos, char ** shape, int w, int h) {
  int X = pos.getX();
  int Y = pos.getY();
  if (Y + w <= 0) return 0;
  if (Y > width) return 0;
  for (int i = 0; i < h; ++i) {
    for (int j = max(1, Y); j <= min(width, Y + w - 1); ++j) {
      if (map[X + i][Y + j] != ' ') return -1;
      map[X + i][Y + j] = shape[i][j - max(1, Y)];
    }
  }
  return 1;
}

void cMap::drawEnemies(cEnemy * enemy) {
  int status = draw(enemy->getPos(), enemy->shape(), enemy->getWidth(), enemy->getHeight());
  if (status == 0) {
    enemy->goOutMap();
  }
  if (status == -1) {
    player.killPlayer();
  }
}

void cMap::drawPlayer() {
  int status = draw(player.getPos(), player.shape(), player.getWidth(), player.getHeight());
  if (status == -1){
    player.killPlayer();
  }
}

void cMap::initializeNewState() {
  player = cPlayer();
  rowsData = cRows();
  // create initial status
//  #include "../cConsole/cConsole.h"

// void cMap::printMap()
// {
// 	int temp1 = width, temp2 = height;
//      TextColor(14);
// 	cout << " " << (char)218;
// 	for (int i = 0; i<width; i++)
// 		cout << (char)196;
// 	cout << (char)191 << endl;
// 	while (temp2 > 0) {
// 		cout << " " << (char)179;
// 		for (int i = 0; i < temp1; i++)
// 			cout << " ";
// 		cout << (char)179 << endl;
// 		temp2--;
// 	}
// 	cout << " " << (char)192;
// 	for (int i = 0; i < temp1; i++)
// 		cout << (char)196;
// 	cout << (char)217 << endl;
// }
