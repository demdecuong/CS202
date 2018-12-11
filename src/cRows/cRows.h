#ifndef cRow_h
#define cRow_h

#include <vector>
#include "../cOneRow/cOneRow.h"
#include "../cEnemy/cEnemy.h"

//using namespace std;

class cRows
{
private:
    vector <cOneRow*> subRows;
public:
    cRows();
    ~cRows() = default;
    bool pushEnemy(int row, cEnemy* enemy); //  push a new enemy to a row
    void pushRow(cOneRow*);
    vector <cEnemy*> listEnemy(); // return all enemies from all rowsgit ad
    void moveToNextState(int t) {};
};

#endif // cRows
