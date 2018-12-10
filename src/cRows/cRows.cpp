#include "cRows.h"

cRows::cRows() {
    subRows.reserve(100);
}

void cRows::pushEnemy (int row, cEnemy* enemy) {
    subRows[row]->pushEnemy(enemy);
}

vector<cEnemy*> cRows::listEnemy(){
    vector<cEnemy*> listEnemy, tmp;
    for (int i = 0; (unsigned) i < subRows.size(); i++) {
        tmp = subRows[i]->getEnemy();
        listEnemy.insert(listEnemy.end(),tmp.begin(), tmp.end());
    }

    return listEnemy;
}