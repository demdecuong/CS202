#include "cPlayer.h"


cPlayer::cPlayer(){
    X = WIDTH/2 -10;
    Y = HEIGHT-2;
    isDead = false;
}

cPlayer::cPlayer(int x, int y): cPosition(x,y){
    isDead = false;
}

void cPlayer::Up(){
    if (Y - 1 != 1)
        Y--;
}

void cPlayer::Down(){
    if (Y + 1 != HEIGHT-1)
        Y++;
}

void cPlayer::Left(){
    if (X - 1 != 0)
        X--;
}

void cPlayer::Right(){
    if (X != WIDTH-1)
        X++;
}

bool cPlayer::checkIsDead(){
    return isDead;
}

void cPlayer::killPlayer(){
    isDead = true;
}

//bool cPlayer::isFinish()
//{
//    if (Y == 2)
//    {
//        return true;
//    }
//    return false;
//}

//
//void cPlayer::draw(){
//    TextColor(ColorCode_Yellow);
//    gotoXY(X, Y);
//    printf("%c", 233);
//    gotoXY(X, Y+1);
//    cout << "X";
//    TextColor(7);
//}

void cPlayer::deleteChar(){
    gotoXY(X, Y);
    cout <<' ';
    gotoXY(X, Y+1);
    cout <<' ';
}

void cPlayer::reset(){
    X = WIDTH / 2;
    Y = HEIGHT - 2;
    isDead = false;
}

bool cPlayer::crash(cTruck *p, int lv){
    for(int i = 0; i < lv; i++){
        int xTruck = p[i].getX(), yTruck = p[i].getY();
        int distance = sqrt((pow((xTruck-X),2)+pow((yTruck-Y),2)));
        if (distance==7){
            isDead = true;
        }
        else isDead = false;
    }
    return isDead;
}


//        if (p[i].getX() == X && p[i].getY() == Y){
//            isDead = true;
//            return true;
//        }
//        if (p[i].getX()-1 == X && p[i].getY() == Y){
//            isDead = true;
//            return true;
//        }
//        if (p[i].getX()-2 == X && p[i].getY() == Y){
//            isDead = true;
//            return true;
//        }
//        if (p[i].getX() == X && p[i].getY() == Y+1){
//            isDead = true;
//            return true;
//        }
//        if (p[i].getX() - 1 == X && p[i].getY() == Y+1){
//            isDead = true;
//            return true;
//        }
//        if (p[i].getX() - 2 == X && p[i].getY() == Y+1){
//            isDead = true;
//            return true;
//        }
//    }
//    return false;
//}

//bool cPlayer::crash(cCar *p, int lv)
//{
//    for (int i = 0; i < lv; i++)
//    {
//        if (p[i].getX() == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() == X && p[i].getY()-1 == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX()-1 == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX()+1 == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() == X && p[i].getY() - 1 == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() - 1 == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() + 1 == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//    }
//    return false;
//}
//bool cPlayer::crash(cBird *p, int lv)
//{
//    for (int i = 0; i < lv; i++)
//    {
//        if (p[i].getX() == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX()-1 == X && p[i].getY()-1 == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() +1== X && p[i].getY()-1 == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() - 1 == X && p[i].getY() - 1 == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() + 1 == X && p[i].getY() - 1 == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//    }
//    return false;
//}
//bool cPlayer::crashcdinausor *p, int lv)
//{
//    for (int i = 0; i < lv; i++)
//    {
//        if (p[i].getX() == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX()+1 == X && p[i].getY()-1 == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX()+1 == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX()-1 == X && p[i].getY() == Y)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() + 1 == X && p[i].getY() - 1 == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() + 1 == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//        if (p[i].getX() - 1 == X && p[i].getY() == Y+1)
//        {
//            m_State = false;
//            return true;
//        }
//    }
//    return false;
//}
