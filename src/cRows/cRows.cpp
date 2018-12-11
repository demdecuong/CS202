#include "cRows.h"

cRows::cRows() {
    subRows.reserve(100);
}

bool cRows::pushEnemy (int row, cEnemy* enemy) {
    if ((unsigned)row >= subRows.size())  return false;
    subRows[row]->pushEnemy(enemy);
    return true;
}

void cRows::pushRow(cOneRow* row) {
    subRows.push_back(row);
}

vector<cEnemy*> cRows::listEnemy(){
    vector<cEnemy*> listEnemy, tmp;
    for (int i = 0; (unsigned) i < subRows.size(); i++) {
        tmp = subRows[i]->getEnemy();
        listEnemy.insert(listEnemy.end(),tmp.begin(), tmp.end());
    }

    return listEnemy;
}