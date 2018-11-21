#ifndef cLevel_h
#define cLevel_h

class cLevel
{
private:
  int level;
  int maxEnemy, maxSpeed, nEnemy;
  int nRow, nColumn;
public:
  cLevel();
  ~cLevel() { }
  void newLevel(int lv);
};

#endif // cLevel
