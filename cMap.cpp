#include "cMap.h"
#include "cConsole.h"

cMap::cMap() : width(115), height(36) {
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i <= width; i++) {
		map[0][i] = map[height + 1][i] = '-';
	}
	map[0][width + 1] = map[height + 1][width + 1] = ' ';
	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width] = '|';
		map[i][width + 1] = ' ';
		for (int j = 1; j < width; ++j) {
			map[i][j] = ' ';
		}
	}
}

void cMap::resetMap() {
	cout << "This is resetMap" << endl;
	for (int i = 0; i <= width + 1; i++) {
		map[0][i] = map[height + 1][i] = '-';
	}
	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width + 1] = '|';
		for (int j = 1; j <= width; ++j) {
			map[i][j] = ' ';
		}
	}
}

void cMap::printMap()
{
	//    TextColor(14);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= width + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
	drawPlayer();
}

void cMap::drawMap() {
	//resetMap();
	vector <cEnemy*> enemyList = rowsData.listEnemy(); //enemyList = 0 
	for (int i = 0; i < (int)enemyList.size(); ++i) {
		//drawEnemies(enemyList[i]);
		if (player.crash(enemyList[i]->getPos(), enemyList[i]->getWidth() - 3, enemyList[i]->getHeight())) {
			player.killPlayer();
			//randomNextState();
			clrscr();
			printMap();
			bombEffect();
			return;
		}
	}
	//drawPlayer();
}

int cMap::draw(cPosition pos, char ** shape, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y + w <= 0) return 0;
	if (Y > width) return 0;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(width, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return 1;
}

void cMap::drawEnemies(cEnemy * enemy) { // deleted
	int status = draw(enemy->getPos(), enemy->shape(), enemy->getWidth(), enemy->getHeight());
	if (status == 0) {
		enemy->goOutMap();
	}
	if (status == -1) {
		player.killPlayer();
	}
}

void cMap::drawPlayer() {
	int status = draw(player.getPos(), player.shape(), player.getWidth(), player.getHeight());
	if (status == -1) {
		player.killPlayer();
	}
}

void cMap::deleteOldPlayer() {
	draw(player.getPos(), player.emptyShape(), player.getWidth(), player.getHeight());
}


void cMap::initializeNewState() {
	player.~cPlayer();
	new(&player) cPlayer();
	rowsData.~cRows();
	new(&rowsData) cRows();
	int padding[10];
	for (int i = 0; i < 10; ++i) {
		padding[i] = 0;
		int speed = rand() % (level.getMinSpeed() - level.getMaxSpeed() + 1) + level.getMaxSpeed();
		bool direction = rand() % 2;
		bool redLight = rand() % 2;
		rowsData.pushRow(new cOneRow(speed, direction, redLight, (i * 3) + 1));
	}
	cEnemy * newEnemy;
	cPosition pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 10);
		padding[rRow] += (rand() % 20) + 9;
		pos = cPosition((rRow * 3) + 1, padding[rRow]);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	Sleep(100);
	rowsData.moveToNextState(0);
}

void cMap::randomNextState() {
	srand(time(NULL));
	//int t = rand(); // this will be get from global clock
	cEnemy * newEnemy;
	cPosition pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = rand() % 10;
		pos = cPosition((rRow * 3) + 1, 4);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	++t;
	int tmp = rowsData.moveToNextState(t);
	level.decNEnemy(tmp);
	drawMap();
}

void cMap::updatePosPlayer(char moving) {
	deleteOldPlayer();
	if (moving == 'a' || moving == 'A') player.Left();
	else if (moving == 'w' || moving == 'W') player.Up();
	else if (moving == 'd' || moving == 'D') player.Right();
	else if (moving == 's' || moving == 'S') player.Down();
	else return;
}

bool cMap::isEnd()
{
	return player.checkIsDead();
}
bool cMap::isWin()
{
	if (player.getX() == 1)
		return true;
	return false;
}

void cMap::bombEffect()
{
	gotoXY(10, 10);
	cout << R"(                                               ____                       )" << "\n"
		<< R"(                                           __,-~~/~    `---.                  )" << "\n"
		<< R"(                                         _/_,---(      ,    )                 )" << "\n"
		<< R"(                                     __ /        <    /   )  \___             )" << "\n"
		<< R"(                      - ------===;;;'====------------------===;;;===----- -  -)" << "\n"
		<< R"(                                      \/  ~"~"~"~"~"~\~"~)~" / )"				 <<	"\n"
		<< R"(                                        (_ (   \  (     >    \)               )" << "\n"
		<< R"(                                         \_( _ <         >_>'                 )" << "\n"
		<< R"(                                            ~ `-i' ::>|--"                    )" << "\n"
		<< R"(                                                I;|.|.|                       )" << "\n"
		<< R"(                                               <|i::|i|`.                     )" << "\n"
		<< R"(                                              (` ^'"`-' ")                    )";
}

void cMap::nextLevel() {
	level.nextLevel();
}
