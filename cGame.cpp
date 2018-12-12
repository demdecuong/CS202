#include "cGame.h"

void cGame::gameSettings() {
	system("cls");
	const char *setting[3] = { "Mode", "Mute sound", "Menu" };
	int pos1 = 0;
	const int y = 10;
	const int x = 40;
	int flag = 0;
	while (!flag) {
		system("cls");
		int color = rand() % 7 + 9;
		TextColor(color);
	/*	cout << "******       *******        **        ******            ******    *******       *******      *******    *******" << endl;
		cout << "**    **     **   **       ** **      **   **           **        **     **    **     **   **         **" << endl;
		cout << "** * **      **   **      **   **     **    **          **        ** *  **    **       **    ****       ****" << endl;
		cout << "**   **      **   **     ** *** **    **   **           **        **   **      **     **         **         **" << endl;
		cout << "**    **     *******    **       **   ******            ******    **    **      *******    *****      *****" << endl;*/
			gotoXY(20, 30);
			cout << " =====  =======   ======   =====  ===== ==== ===       =======" << endl;
			gotoXY(20, 31);
			cout << "||     ||     |  ||	   |  ||     ||	     ||	||  \\   | ||  " << endl;
			gotoXY(20, 32);
			cout << "||     ||_____|  ||	   |  ||___  ||___   ||	||   \\  | ||   ====  " << endl;
			gotoXY(20, 33);
			cout << "||     ||   \\    ||    |       |     |   ||	||    \\ | ||_____||         	" << endl;
			gotoXY(20, 34);
			cout << " =========== \\    ======   ===== =====  ==== ======   ======      /\\      ====\\\\" << endl;
			gotoXY(20, 35);
			cout << "                                            ||     | ||    |     // \\    ||	   |" << endl;
			gotoXY(20, 36);
			cout << "                                            || ====  ||    |    //   \\   ||	   |" << endl;
			gotoXY(20, 37);
			cout << "                                            ||   \\\\  ||    |   //  ===\\  ||	   |" << endl;
			gotoXY(20, 38);
			cout << "                                            ||    \\\\  ======  //	   \\  ====//" << endl;
		TextColor(7);
		TextColor(238);
		for (int i = 20; i <= 80; i++) {
			for (int j = y - 5; j <= y + 5; j++) {
				if (j == y - 5 || j == y + 5 || i == 20 || i == 80) {
					gotoXY(i, j);
					cout << "*";
				}
			}
		}
		TextColor(7);
		for (int i = 0; i < 4 - 1; i++) {
			if (i == pos1) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << setting[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << setting[i];
			}
		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos1 > 0)
						pos1--;
					else
						pos1 = 4 - 2;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos1 < 4 - 1 - 1)
						pos1++;
					else
						pos1 = 0;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0: {
						flag = 1;
						break;
					}
					case 1: {
						flag = 1;
						break;
					}
					case 2: {
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
	if (flag == 1) {
		system("cls");
		bool isFinish = false;
		cGame::menu(isFinish);
		//  cGame::drawGame();
	}
}

void cGame::menu(bool &isFinish) {
}


void cGame::newGame() { // start a new game, initialize cMap map
		map.printMap();
		map.initializeNewState();
		while (!map.isEnd()) {
			if (!isPausing) {
				map.randomNextState();
			}
			if (kbhit())
			{
				char key = getch();
				if (key == 'l')
				{
					//Save
					map.saveGame("minh.txt");
				}
				if (key == 't')
				{
					//Load
				}
				if (key == 'p')
				{
					togglePauseGame();
				}
				if (isPausing) continue;
				if (key == 'a')
				{
					map.updatePosPlayer('a');
				}
				if (key == 'w')
				{
					map.updatePosPlayer('w');
				}
				if (key == 's')
				{
					map.updatePosPlayer('s');
				}
				if (key == 'd')
				{
					map.updatePosPlayer('d');
				}
				map.drawPlayer();
				map.drawMap();
			}
			if (map.isWin()) {
				map.printMap();
				map.initializeNewState();
				map.nextLevel();
				break;
			}
		}
}

void cGame::loadGame() { // get file of cMap map
	ifstream infile;
	string file;
	gotoXY(80 / 2, 20 + 2); //width=115, height=35
	cout << "Input name to load: " << endl;
	getline(cin, file);
	file = file + ".txt";
	clrscr();
	infile.open(file, ios::in);
	if (infile.fail()) {
		gotoXY(115 / 2, 35 / 2);
		TextColor(ColorCode_Green);
		cout << "Data does not exist" << endl;
		TextColor(7);
		system("pause");
		clrscr();
		return;
	}
	/*delete[] car;
	delete[] truck;
	delete[] bird;
	delete[] dinausor;
	infile >> level;
	car = new cCar[level];
	truck = new cTruck[level];
	bird = new cBird[level];
	dinausor = new cDinausor[level];
	*/
	int x, y;
	infile >> x;
	infile >> y;
	/*player.set(x, y);
	for (int i = 0; i < level; i++) {
	infile >> x;
	infile >> y;
	//   car[i].set(x, y);
	}
	for (int i = 0; i < level; i++)
	{
	infile >> x;
	infile >> y;
	//  truck[i].set(x, y);
	}
	for (int i = 0; i < level; i++)
	{
	infile >> x;
	infile >> y;
	//   bird[i].set(x, y);
	}
	for (int i = 0; i < level; i++)
	{
	infile >> x;
	infile >> y;
	//   dinausor[i].set(x, y);
	}
	*/
	infile.close();
}



void cGame::togglePauseGame() { // toggle status of isPausing
	isPausing = !isPausing;
};

void cGame::gameOver() {
	cout << "Game over" << endl;
};




/*
void SubThread(cGame*cg, bool *IS_RUNNING, bool *isPausing, bool *exitFlag)
{
	//cg->drawGame();
	while (*IS_RUNNING) {
		if (*isPausing == false) {
			cg->getMap().updatePosPlayer(MOVING);
		}
		MOVING = ' ';
		cg->getMap().randomNextState();

		if (cg->getMap().isEnd())
		{

		}
		if (cg->getMap().isWin())
		{
			cout << "CONGRATULATION...!!!!" << endl;
		}
		Sleep(100);
	}
}*/
/*
void cGame::playGame(bool &is_finish) {
	bool IS_RUNNING = true;
	bool exitFlag = false;
	thread t1(SubThread, this, &IS_RUNNING, &isPausing, &exitFlag);
	int tmp;
	while (IS_RUNNING) {/*
		if (exitFlag == true) {
			//quitGame(&t1, IS_RUNNING);
		}
		if (kbhit())
		{
			char key = getch();
			if (key == 'a')
			{
				cout << "A" << endl;
				map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				map.updatePosPlayer('w');
			}
			if (key == 's')
			{
				map.updatePosPlayer('s');
			}
			if (key == 'd')
			{
				map.updatePosPlayer('d');
			}
			map.drawPlayer();
		}
		/*if (true)
		{
			tmp = toupper(getch());

			if (tmp == 27) {
				//quitGame(&t1, IS_RUNNING);
				t1.native_handle();
				return;
			}
			if (tmp == 80) {
				t1.native_handle();
				if (isPausing == false) {

					isPausing = true;
					while (isPausing) {
						int tmp1 = toupper(_getch());
						if (tmp1 == 80) {
							isPausing = false;
							break;
						}
					}
				}
			}
			t1.native_handle();
			MOVING = tmp;
			map.updatePosPlayer(MOVING);
		}
		else {
			is_finish = true;
			t1.native_handle();
			//quitGame(&t1, IS_RUNNING);
		}
	}
	}
}
*/

