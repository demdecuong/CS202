#ifndef cRow_h
#define cRow_h

#include <vector>
#include "../cOneRow/cOneRow.h"
#include "../cEnemy/cEnemy.h"

//using namespace std;

class cRows
{
private:
//  vector <cOneRow*> subRows;
public:
<<<<<<< HEAD
    cRows();
=======
    cRows() = default;
>>>>>>> cMap-and-cLevel
    ~cRows() = default;
    void pushEnemy(int row, cEnemy* enemy); //  push a new enemy to a row
//    vector <cEnemy*> listEnemy(); // return all enemies from all rows
};

#endif // cRows
