#include "cMap.h"
#include "cConsole.h"

cMap::cMap() : width(115), height(36) {
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
	clrscr();
	gotoXY(0, 0);
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
			if (!isMute) enemyList[i]->sound();
			player.killPlayer();
			//randomNextState();
			clrscr();
			printMap();
			deleteOldPlayer();
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
		int rRow = (rand() % 9) + 1;
		padding[rRow] += (rand() % 20) + 9;
		pos = cPosition((rRow * 3) + 1, padding[rRow]);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	Sleep(200);
	rowsData.moveToNextState(0);
}

void cMap::randomNextState() {
	srand(time(NULL));
	//int t = rand(); // this will be get from global clock
	cEnemy * newEnemy;
	cPosition pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 9) + 1;
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
		<< R"(                                      \/  ~"~"~"~"~"~\~"~)~" / )" << "\n"
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

void cMap::printInt(int x, ofstream& outfile) {
	outfile.write((char*)&x, sizeof(int));
}

void cMap::saveGame(string file)
{
	ofstream outfile("./data/" + file + ".bin", ios::out | ios::binary);
	printInt(level.getLevel(), outfile);
	printInt(player.getX(), outfile);
	printInt(player.getY(), outfile);

	vector <cOneRow*> rows(rowsData.listRow());
	for (int i = 0; i < 10; ++i) {
		//outfile.write((char*)rows[i]->getCurrentRow(), sizeof(rows[i]->getCurrentRow()));
		printInt(rows[i]->getCurrentRow(), outfile);
		//outfile.write((char*)rows[i]->getDirection(), sizeof(rows[i]->getDirection()));
		printInt(rows[i]->getDirection(), outfile);
		//outfile.write((char*)rows[i]->getSpeed(), sizeof(rows[i]->getSpeed()));
		printInt(rows[i]->getSpeed(), outfile);
		//outfile.write((char*)rows[i]->getRedLight(), sizeof(rows[i]->getRedLight()));
		printInt(rows[i]->getRedLight(), outfile);
		vector <cEnemy*> enemy(rows[i]->getEnemy());
		//outfile.write((char*)enemy.size(), sizeof(enemy.size()));
		printInt((int)enemy.size(), outfile);
		for (int j = 0; j < (int)enemy.size(); ++j) {
			//outfile.write((char*)enemy[j]->getX(), sizeof(enemy[j]->getX()));
			printInt(enemy[j]->getX(), outfile);
			//outfile.write((char*)enemy[j]->getY(), sizeof(enemy[j]->getY()));
			printInt(enemy[j]->getY(), outfile);
			//outfile.write((char*)enemy[j]->getType(), sizeof(enemy[j]->getType()));
			printInt(enemy[j]->getType(), outfile);
		}
	}
	outfile.close();
}

bool cMap::printLevelUp() {
	clrscr();
	printMap();
	deleteOldPlayer();
	gotoXY(15, 15); cout << "******    *******       *******      *******    *******    ******     *******      ###   ###" << endl;
	gotoXY(15, 16); cout << "**        **     **    **     **   **         **           **         **     *     ###   ###" << endl;
	gotoXY(15, 17); cout << "**        ** *  **    **       **    ****       ****       ******     **      *    ###   ###" << endl;
	gotoXY(15, 18); cout << "**        **   **      **     **         **         **     **         **     *     ###   ###" << endl;
	gotoXY(15, 19); cout << "******    **    **      *******    *****      *****        ******     *******     ::::: ::::: " << endl;
	gotoXY(35, 21); cout << "Continue ?" << endl;
	const char *choice[2] = { "<NO>", "<YES>" };
	int pos = 0, x = 36, y = 22;
	TextColor(7);
	/*TextColor(227);
	gotoXY(x, y);
	cout << choice[0];
	TextColor(7);

	TextColor(227);
	gotoXY(x+10, y);
	cout << choice[1];
	TextColor(7);*/

	while (1) {
		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
			}
		}

		switch (inputKey()) {
		case 'w':
			pos--;
			pos %= 2;
			break;
		case 's':
			pos++;
			pos %= 2;
			break;
		case 13:
			return pos;
		}
	}

}