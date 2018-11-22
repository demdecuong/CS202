#ifndef cOneRow_h
#define cOneRow_h

#include <vector>
#include "../cEnemy/cEnemy.h"

using namespace std;

class cOneRow
{
private:
  vector <cEnemy*> enemy;
  bool direction = 0; //0: to the left, 1: to the right
  bool redLight = false;
public:
    cOneRow() = default;
    ~cOneRow() = default;
    bool pushEnemy(cEnemy* newEnemy); // push a new new enemy
};

#endif // cOneRow
