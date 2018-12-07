#include "cGame.h"
#include oldnames.lib

cGame::cGame(){
    level = 0;
    this->newGame();
}

void cGame::lvUp(){
//    player.deleteChar();
    for (int i = 0; i < level; i++)
    {
//        bird[i].deleteChar();
//        dinausor[i].deleteChar();
//        truck[i].deleteChar();
//        car[i].deleteChar();
    }
    delete[] car;
    delete[] bird;
    delete[] truck;
    delete[] dinausor;
    if (level == LV_MAX){
        gotoXY(2, HEIGHT + 2);
        cout << "You win" << endl;
//        _getch();
        exit(0);
    }
    level++;
    player.reset();
    this->newGame();
}
void cGame::resetGame(int lv)
{
    player.deleteChar();
    for (int i = 0; i < level; i++)
    {
        bird[i].deleteChar();
        dinausor[i].deleteChar();
        truck[i].deleteChar();
        car[i].deleteChar();
    }
    for (int i = 0; i < 70; i++)
    {
        gotoXY( i + 1, HEIGHT +3);
        cout << ' ';
    }
    level = lv;
    player.reset();
    this-> newGame(level);
}
void cGame::newGame(){
    map = new cMap;
//    truck = new cTruck[];
//    car = new cCar[];
//    bird = new cBird[];
//    dinausor = new cdinausor[];
//    for (int i = 0; i < ; i++)
//    {
//        int x_vehicle = 8 * i + 5;
//        int x_animal = WIDHT - 8 * i - 5;
//        truck[i].set(x_vehicle, y_truck);
//        car[i].set(x_vehicle, y_car);
//        bird[i].set(x_animal, y_bird);
//        dinausor[i].set(x_animal, y_dinausor);
//    }
}

cGame::~cGame(){
    delete[]car;
    delete[]truck;
    delete[]bird;
    delete[]dinausor;
}

int& cGame::getLevel(){
    return level;
}

void cGame::logIn(){
    char *menu[] = { "1. Start Game", "2. Load Game", "3. Setting","4. Exit" };
    int pos = 0;
    const int y = 10;
    const int x = 40;
    int flag = 0;
    while (1){
        clrscr();
        int color = rand() % 7 + 9;
        TextColor(color);
        cout << "******       *******        **        ******            ******    *******       *******      *******    *******" << endl;
        cout << "**    **     **   **       ** **      **   **           **        **     **    **     **   **         **" << endl;
        cout << "** * **      **   **      **   **     **    **          **        ** *  **    **       **    ****       ****" << endl;
        cout << "**   **      **   **     ** *** **    **   **           **        **   **      **     **         **         **" << endl;
        cout << "**    **     *******    **       **   ******            ******    **    **      *******    *****      *****" << endl;
        TextColor(7);
        TextColor(238);
        for (int i = 30; i <= 60; i++){
            for (int j = y - 5; j <= y + 5; j++){
                if (j == y - 5 || j == y + 5 || i == 30 || i == 60){
                    gotoXY(i, j);
                    cout << "*";
                }
            }
        }
        TextColor(7);
        for (int i = 0; i < 4; i++){
            if (i == pos){
                TextColor(227);
                gotoXY(x, y + i);
                cout  << menu[i];
                TextColor(7);
            }
            else{
                gotoXY(x, y + i);
                cout << menu[i];
            }
        }
        while (1){
            if (_kbhit()){
                char key = _getch();
                if (key == 'W' || key == 'w'){
                    if (pos > 0)
                        pos--;
                    else
                        pos = MAX_LIST - 1;
                    break;
                }
                if (key == 'S' || key == 's'){
                    if (pos < MAX_LIST - 1)
                        pos++;
                    else
                        pos = 0;
                    break;
                }
                if (key == 13){
                    switch (pos){
                        case 0:{
                            system("cls");
                            startGame();
                            flag = 1;
                            break;
                        }
                        case 1:{
                            system("cls");
                            loadGame();
                            startGame();
                            flag = 1;
                            break;
                        }
                        case 2:{
                            flag = 1;
                            cGame::GameSetting();
                            break;
                        }
                        case 3:
                        {
                            exit(0);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if (flag)    break;
    }
}

void cGame::GameSettings(){
    system("cls");
    char *setting[] = { "Mode", "Mute sound" ,"Menu"};
    int pos1 = 0;
    const int y = 10;
    const int x = 40;
    int flag = 0;
    while (!flag){
        system("cls");
        int color = rand() % 7 + 9;
        TextColor(color);
        cout << "******       *******        **        ******            ******    *******       *******      *******    *******" << endl;
        cout << "**    **     **   **       ** **      **   **           **        **     **    **     **   **         **" << endl;
        cout << "** * **      **   **      **   **     **    **          **        ** *  **    **       **    ****       ****" << endl;
        cout << "**   **      **   **     ** *** **    **   **           **        **   **      **     **         **         **" << endl;
        cout << "**    **     *******    **       **   ******            ******    **    **      *******    *****      *****" << endl;
        TextColor(7);
        TextColor(238);
        for (int i = 30; i <= 60; i++){
            for (int j = y - 5; j <= y + 5; j++){
                if (j == y - 5 || j == y + 5 || i == 30 || i == 60){
                    gotoXY(i, j);
                    cout << "*";
                }
            }
        }
        TextColor(7);
        for (int i = 0; i < MAX_LIST-1; i++){
            if (i == pos1){
                TextColor(227);
                gotoXY(x, y + i);
                cout << setting[i];
                TextColor(7);
            }
            else{
                gotoXY(x, y + i);
                cout << setting[i];
            }
        }
        while (1){
            if (_kbhit()){
                char key = _getch();
                if (key == 'W' || key == 'w'){
                    if (pos1 > 0)
                        pos1--;
                    else
                        pos1 = MAX_LIST - 2;
                    break;
                }
                if (key == 'S' || key == 's'){
                    if (pos1 < MAX_LIST-1 - 1)
                        pos1++;
                    else
                        pos1 = 0;
                    break;
                }
                if (key == 13){
                    switch (pos1){
                        case 0:{
                            flag = 1;
                            break;
                        }
                        case 1:{
                            flag = 1;
                            break;
                        }
                        case 2:{
                            flag = 1;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        system("cls");
    }
    if (flag == 1){
        system("cls");
        cGame::logIn();
        cGame::drawGame();
    }
}
void cGame::startGame()
{
    system("cls");
    TextColor(ColorCode_Pink);
    gotoXY(WIDHT + 3, HEIGHT - 15);
    cout << "Level: ";
    gotoXY(WIDHT + 3, HEIGHT - 10);
    cout << "Press W to UP";
    gotoXY(WIDHT + 3, HEIGHT - 13);
    cout << "Press A to LEFT";
    gotoXY(WIDHT + 3, HEIGHT - 12);
    cout << "Press S to DOWN";
    gotoXY(WIDHT + 3, HEIGHT - 11);
    cout << "Press D to RIGHT";
    gotoXY(WIDHT + 3, HEIGHT - 10);
    cout << "Press P to PauseGame";
    gotoXY(WIDHT + 3, HEIGHT - 9);
    cout << "Press L to SaveGame";
    gotoXY(WIDHT + 3, HEIGHT - 8);
    cout << "Press E to Exit";
    gotoXY(WIDHT + 3, HEIGHT - 7);
    cout << "Press T to LoadGame";
    TextColor(7);
    TextColor(187);
    for (int i = 1; i <= WIDHT+25; i++){
        gotoXY(i, 1);
        cout << "*";
        gotoXY(i, HEIGHT);
        cout << "*";
    }
    for (int i = 2; i < HEIGHT; i++){
        gotoXY(0, i);
        cout << "*";
        gotoXY(WIDHT, i);
        cout << "*";
        gotoXY(WIDHT+25, i);
        cout << "*";
    }
    TextColor(7);
}

bool cGame::isRunning(){
    return (!player.isDead());
}

cPlayer cGame::getPlayer(){
    return player;
}


void cGame::updatePosPlayer(char moving){
    player.deleteChar();
    if (moving == 'a' || moving == 'A') player.Left();
    if (moving == 'w' || moving == 'W') player.Up();
    if (moving == 'd' || moving == 'D') player.Right();
    if (moving == 's' || moving == 'S') player.Down();
}

void  cGame::updatePosAnimal(){
    for (int i = 0; i < level; i++){
        bird[i].deleteChar();
        bird[i].move();
    }
    for (int i = 0; i < level; i++){
        dinausor[i].deleteChar();
        dinausor[i].move();
    }
}

void cGame::updatePosVehicle(){
    for (int i = 0; i < level; i++){
        
        car[i].deleteChar();
        car[i].move();
        
    }
    for (int i = 0; i < level; i++){
        truck[i].deleteChar();
        truck[i].move();
        
    }
}


void cGame::exitGame(HANDLE t){
    system("cls");
    exit(0);
}
void cGame::togglePauseGame(HANDLE t)
{
    SuspendThread(t);
}
void cGame::resumeGame(HANDLE t)
{
    ResumeThread(t);
}





cTruck* cGame::getTruck(){
    return truck;
}
cBird* cGame::getBird(){
    return bird;
}
cCar* cGame::getCar(){
    return car;
}
cDinausor* cGame::getDinausou(){
    return dinausor;
}



void cGame::saveGame()
{
    TextColor(ColorCode_Green);
    ofstream outfile;
    string file;
    gotoXY(WIDHT/2, HEIGHT + 2);
    cout << "Yourname: " << endl;
    getline(cin, file);
    file = file + ".txt";
    outfile.open(file);
    TextColor(7);
    outfile << level << ' ';
    outfile << peoPle.getX() <<' '<< peoPle.getY() << endl;
    outfile << trafic.getStatus() <<' ' <<trafic.getTime() <<  endl;
    
    for (int i = 0; i < level; i++)
    {
        outfile << car[i].getX() << ' ';
        outfile << car[i].getY() << ' ';
    }
    for (int i = 0; i < level; i++)
    {
        outfile << truck[i].getX() << ' ';
        outfile << truck[i].getY() << ' ';
    }
    for (int i = 0; i < level; i++)
    {
        outfile << bird[i].getX() << ' ';
        outfile << bird[i].getY()<< ' ';
    }
    for (int i = 0; i < level; i++)
    {
        outfile << dinausor[i].getX() << ' ';
        outfile << dinausor[i].getY() << ' ';
    }
    outfile.close();
    clrscr();
    this->startcGame();
    this->drawcGame();
    return;
}
void cGame::drawDie()
{
    system("cls");
    TextColor(ColorCode_White);
    gotoXY(WIDHT + 3, HEIGHT - 15);
    cout << "level: ";
    gotoXY(WIDHT + 3, HEIGHT - 10);
    cout << "Press W to UP";
    gotoXY(WIDHT + 3, HEIGHT - 13);
    cout << "Press A to LEFT";
    gotoXY(WIDHT + 3, HEIGHT - 12);
    cout << "Press S to DOWN";
    gotoXY(WIDHT + 3, HEIGHT - 11);
    cout << "Press D to RIGHT";
    gotoXY(WIDHT + 3, HEIGHT - 10);
    cout << "Press P to PausecGame";
    gotoXY(WIDHT + 3, HEIGHT - 9);
    cout << "Press L to SavecGame";
    gotoXY(WIDHT + 3, HEIGHT - 8);
    cout << "Press E to Exit";
    gotoXY(WIDHT + 3, HEIGHT - 7);
    cout << "Press T to LoadcGame";
    for (int i = 1; i <= WIDHT + 25; i++)
    {
        gotoXY(i, 1);
        cout << "*";
        gotoXY(i, HEIGHT);
        cout << "*";
    }
    for (int i = 2; i < HEIGHT; i++)
    {
        gotoXY(0, i);
        cout << "*";
        gotoXY(WIDHT, i);
        cout << "*";
        gotoXY(WIDHT + 25, i);
        cout << "*";
    }
    TextColor(7);
}

void cGame::loadGame(){
    ifstream infile;
    string file;
    gotoXY(WIDHT / 2, HEIGHT + 2);
    cout << "Input name to load: " << endl;
    getline(cin, file);
    file = file + ".txt";
    clrscr();
    infile.open(file, ios::in);
    if (infile.fail()){
        gotoXY(WIDHT / 2, HEIGHT / 2);
        TextColor(ColorCode_Green);
        cout << "Data does not exist" << endl;
        TextColor(7);
        system("pause");
        clrscr();
        return;
    }
    delete[] car;
    delete[] truck;
    delete[] bird;
    delete[] dinausor;
    infile >> level;
    car = new cCar[leve;];
    truck = new cTruck[level];
    bird = new cBird[level];
    dinausor = new cDinausor[level];
    int x, y,status,time;
    infile >> x;
    infile >> y;
    peoPle.set(x, y);
    infile >> status;
    infile >> time;
    trafic.set(status, time);
    for (int i = 0; i < level; i++)
    {
        infile >> x;
        infile >> y;
        car[i].set(x, y);
    }
    for (int i = 0; i < level; i++)
    {
        infile >> x;
        infile >> y;
        truck[i].set(x, y);
    }
    for (int i = 0; i < level; i++)
    {
        infile >> x;
        infile >> y;
        bird[i].set(x, y);
    }
    for (int i = 0; i < level; i++)
    {
        infile >> x;
        infile >> y;
        dinausor[i].set(x, y);
    }
    infile.close();
}
