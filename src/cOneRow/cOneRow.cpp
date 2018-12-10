#include "cOneRow.h"
cOneRow::cOneRow(){
    direction = 0;
    redLight = 0;
    enemy.reserve(100);
}
bool cOneRow::pushEnemy(cEnemy* newEnemy) {
    if (newEnemy == 0 || find(enemy.begin(),enemy.end(),newEnemy) != enemy.end()) {
        return false;
    }
    enemy.push_back(newEnemy);
    return true;
}

vector<cEnemy*> cOneRow::getEnemy() {
    return enemy;
}

