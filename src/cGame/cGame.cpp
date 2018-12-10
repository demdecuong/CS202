#include "cGame.h"

void cGame::gameSettings() {
	system("cls");
	const char *setting[3] = {"Mode", "Mute sound", "Menu"};
	int pos1 = 0;
	const int y = 10;
	const int x = 40;
	int flag = 0;
	while (!flag) {
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
	const char *menu[4] = { "1. Start Game", "2. Load Game", "3. Setting","4. Exit" };
	int pos = 0;
	const int y = 10;
	const int x = 40;
	int flag = 0;
	while (1) {
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
		for (int i = 20; i <= 80; i++) {
			for (int j = y - 5; j <= y + 5; j++) {
				if (j == y - 5 || j == y + 5 || i == 20 || i == 80) {
					gotoXY(i, j);
					cout << "*";
				}
			}
		}
		TextColor(7);
		for (int i = 0; i < 4; i++) {
			if (i == pos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << menu[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << menu[i];
			}
		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos > 0)
						pos--;
					else
						pos = 4 - 1;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos < 4 - 1)
						pos++;
					else
						pos = 0;
					break;
				}
				if (key == 13) {
					switch (pos) {
					case 0: {
						system("cls");
						//newGame(); 
						playGame(isFinish);
						flag = 1;
						break;
					}
					case 1: {
						system("cls");
						loadGame();
						//newGame(); 
						playGame(isFinish);
						flag = 1;
						break;
					}
					case 2: {
						flag = 1;
						cGame::gameSettings();
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

void cGame::newGame() { // start a new game, initialize cMap map
	bool reset = true;
	startGame(reset, 0);
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

void cGame::saveGame() { // print file of cMap map
	TextColor(ColorCode_Green);
	ofstream outfile;
	string file;
	gotoXY(80/2, 20+2); //width=115, height=35
	cout << "Yourname: " << endl;
	getline(cin, file);
	file = file + ".txt";
	outfile.open(file);
	TextColor(7);
	outfile << level << ' ';
	outfile << player.getX() << ' ' << player.getY() << endl;

	/*for (int i = 0; i < level; i++)
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
		outfile << bird[i].getY() << ' ';
	}
	for (int i = 0; i < level; i++)
	{
		outfile << dinausor[i].getX() << ' ';
		outfile << dinausor[i].getY() << ' ';
	}*/
	outfile.close();
	clrscr();
	bool reset = true;
	startGame(reset,level);
	// this->drawGame();
	return;
}

void togglePauseGame(); // toggle status of isPausing


void cGame::playGame(bool &is_finish) {
	char move;
	bool IS_RUNNING = true;
	bool exitFlag = false;
	thread t1(SubThread,this, &IS_RUNNING, &isPausing, &exitFlag);
	int tmp;
	while (IS_RUNNING) {
		if (exitFlag == true) {
			quitGame(&t1, IS_RUNNING);

		}
		if ( getPlayer().isFinish() == false)
		{
			tmp = toupper(_getch());

			if (tmp == 27) {
				quitGame(&t1, IS_RUNNING);
			}
			if (tmp == 80) {
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
			move = tmp;
			updatePosPlayer(move);

		}
		else {
			is_finish = true;
			quitGame(&t1, IS_RUNNING);
		}
	}

} // manage game process: randomNextState, draw (tick time)

void cGame::quitGame(thread *t1, bool &IS_RUNNING) {
	IS_RUNNING = false;
	t1->join();
}

void gameOver();

void cGame::updatePosPlayer(char moving) {
	if (moving == 'a' || moving == 'A') player.Left();
	else if (moving == 'w' || moving == 'W') player.Up();
	else if (moving == 'd' || moving == 'D') player.Right();
	else if (moving == 's' || moving == 'S') player.Down();
	else return;
}

void startGame(bool &reset, int level) {
	cGame cg;
	bool is_finish = false;
	cg.menu(is_finish);
	// cg.playGame(is_finish);  o tren gamesetiing roi 
	if (is_finish == true) {
		gotoXY(15, 15);
		cout << "YOU WON LEVEL" << level << endl;
		gotoXY(15, 16);
		cout << "PRESS 'n' TO CONTINUE" << endl;
		int tmp2;
		do {
			tmp2 = toupper(_getch());
		} while (tmp2 != 'N');
		if (tmp2 == 'N') {
			is_finish = false;
			startGame(reset, level + 1);
		}

	}
	else {
		system("cls");
		gotoXY(15, 15);
		cout << "PRESS Y TO PLAY AGAIN!!" << endl;
		gotoXY(15, 16);
		cout << "PRESS N TO EXIT!!" << endl;
		int tmp1;
		do {
			tmp1 = toupper(_getch());
			if (tmp1 == 'Y') {
				reset = true;
				break;
			}
			else if (tmp1 == 'N') {
				reset = false;
				break;
			}

		} while (tmp1 != 'y' && tmp1 != 'n');
	}

}
/*void cGame::updatePosTruck() {
	truck.deleteChar();
	for (int i=0; i<)
}*/

void SubThread(cGame*cg, bool *IS_RUNNING, bool *isPausing, bool *exitFlag)
{
	//cg->drawGame();
	while (*IS_RUNNING && (cg->getPlayer().checkisDead() == false)) {
		if (*isPausing == false) {
			cg->updatePosEnemy();
			if ((cg->getPlayer().crash(cg->getAnimal()) == true) /*|| (cg->getPeople().isImpact(cg->getAnimal1(), 6) == true)*/) {
				*exitFlag = true;
				gotoXY(15, 15);
				cout << "YOU ARE DEAD!!" << endl;
				gotoXY(15, 16);
				cout << "PRESS ENTER ENTER" << endl;
				return;
			}
		}
		else {
			while (*isPausing) {}
		}
	}

}