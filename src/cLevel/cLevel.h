#ifndef cLevel_h
#define cLevel_h

#include <algorithm>

using namespace std;

class cLevel
{
private:
  int level;
  int maxEnemy, maxSpeed, nEnemy;
  int nRow;
//  int nColumn;
  void initialize();
public:
  cLevel();
  cLevel(int level, int nEnemy);
//  ~cLevel();
  void newLevel(int lv);
};

#endif // cLevel
