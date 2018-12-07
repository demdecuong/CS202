#include "cPosition.h"

cPosition::cPosition(){
    X = Y = 0;
}

cPosition::cPosition(int x, int y){
    X = x;
    Y = y;
}

int cPosition::getX(){
    return X;
}

int cPosition::getY(){
    return Y;
}
