#include "cGame.h"

void cGame::gameSettings() {
	system("cls");
	const char *setting[3] = { "Mode", "Sound", "Menu" };
	char * currentSettting[3] = { "Hard", "ON", "" };
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
				cout << setting[i] << " " << currentSettting[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << setting[i] << " " << currentSettting[i];
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
						toggleMute();
						if ((bool)isMute) {
							currentSettting[1] = "OFF";
						}
						else {
							currentSettting[1] = "ON";
						}
						//flag = 1;
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
	if (flag == 1) { //???
		system("cls");
		bool isFinish = false;
		cGame::menu(isFinish);
		//  cGame::drawGame();
	}
}

void cGame::menu(bool &isFinish) {
}

void cGame::menu() {
	const string choice[4] = { "New Game","Load Game","Settings","Quit" };
	int pos = 0;
	int x = 35, y = 20;
	while (true) {
		system("cls");

		//TextColor(7);
		int color = rand() % 7 + 9;
		TextColor(color);
		/*	cout << "******       *******        **        ******            ******    *******       *******      *******    *******" << endl;
		cout << "**    **     **   **       ** **      **   **           **        **     **    **     **   **         **" << endl;
		cout << "** * **      **   **      **   **     **    **          **        ** *  **    **       **    ****       ****" << endl;
		cout << "**   **      **   **     ** *** **    **   **           **        **   **      **     **         **         **" << endl;
		cout << "**    **     *******    **       **   ******            ******    **    **      *******    *****      *****" << endl;*/
		gotoXY(20, 10); cout << " =====  =======   ======   =====  ===== ==== ===       =======" << endl;
		gotoXY(20, 11); cout << "||     ||     |  ||	   |  ||     ||	     ||	||  \\   | ||  " << endl;
		gotoXY(20, 12); cout << "||     ||_____|  ||	   |  ||___  ||___   ||	||   \\  | ||   ====  " << endl;
		gotoXY(20, 13); cout << "||     ||   \\    ||    |       |     |   ||	||    \\ | ||_____||         	" << endl;
		gotoXY(20, 14); cout << " =========== \\    ======   ===== =====  ==== ======   ======      /\\      ====\\\\" << endl;
		gotoXY(20, 15); cout << "                                            ||     | ||    |     // \\    ||	   |" << endl;
		gotoXY(20, 16); cout << "                                            || ====  ||    |    //   \\   ||	   |" << endl;
		gotoXY(20, 17); cout << "                                            ||   \\\\  ||    |   //  ===\\  ||	   |" << endl;
		gotoXY(20, 18); cout << "                                            ||    \\\\  ======  //	   \\  ====//" << endl;
		TextColor(7);
		for (int i = 0; i < 4; i++) {
			gotoXY(x, y + i);
			if (i == pos)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choice[i] << endl;
		}
		while (true)
		{
			switch (inputKey()) {
			case 'w':
				pos--;
				pos = (pos + 4) % 4;
				break;
			case 's':
				pos++;
				pos %= 4;
				break;
			case 13:
				switch (pos) {
				case 0:
					while (1) {
						loading();
						if (newGame()) {
							Sleep(1000);
							clrscr();
							break;//return; // thang nhung k choi tiep
							Sleep(1000);
						}
						else if (!continueMenu()) {
							Sleep(1000);
							clrscr();
							break;//return; //thua nhung khong choi tiep
						}
					}
					break;
				case 1: {
					Sleep(1000);
					loadGameMenu();
				}break;
				case 2: {
					Sleep(1000);
					gameSettings();
				}break;
				case 3:
					return;
				}
				break;
			}
			break;
		}
		Sleep(200);
	}
}

bool cGame::continueMenu() {
	clrscr();
	map.printMap();
	map.deleteOldPlayer();
	map.bombEffect();
	gotoXY(15, 5); cout << "******    *******        ****      *******    **    **    ******     *******      ###   ###" << endl;
	gotoXY(15, 6); cout << "**        **     **     **  **   **           **    **    **         **     *     ###   ###" << endl;
	gotoXY(15, 7); cout << "**        ** *  **     **    **    ****       ********    ******     **      *    ###   ###" << endl;
	gotoXY(15, 8); cout << "**        **   **     **      **         **   **    **    **         **     *     ###   ###" << endl;
	gotoXY(15, 9); cout << "******    **    **   **        **  *****      **    **    ******     *******     ::::: ::::: " << endl;
	gotoXY(35, 23); cout << "Continue ?" << endl;
	const char *choice[2] = { "<YES>", "<NO>" };
	int pos = 0, x = 36, y = 25;
	TextColor(7);

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
			pos = abs(pos);
			pos %= 2;
			break;
		case 's':
			pos++;
			pos %= 2;
			break;
		case 13:
			return !pos;
		}
	}

}

//void cGame::pauseMenu(int cmd) {
//	
//}

bool cGame::newGame() { // start a new game, initialize cMap map
	
	char key;
	map.~cMap();
	new(&map) cMap();
	map.printMap();
	map.initializeNewState();

	gotoXY(125, 5); cout << "CONTROL MANUAL" << endl;
	gotoXY(125, 6); cout << "[ W ]: UP" << endl;
	gotoXY(125, 7); cout << "[ S ]: DOWN" << endl;
	gotoXY(125, 8); cout << "[ A ]: LEFT" << endl;
	gotoXY(125, 9); cout << "[ D ]: RIGHT" << endl;
	gotoXY(125, 11); cout << "COMMANDS" << endl;
	gotoXY(125, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(125, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(125, 14); cout << "[ P ]: Pause game/Menu" << endl;

	const string choice[3] = { "Save Game","Load Game","Quit" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoXY(125, 19); cout << "PAUSE MENU" << endl;
		int x = 125, y = 22;
		for (int i = 0; i < 3; i++) {
			gotoXY(x, y + i);
			if (isPausing && i == pos)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choice[i] << endl;
		}
			
		if (kbhit())
		{
			key = getch();
			if (key == 'l')
			{
				//Save
				// call saveGame of cGame to get name of file
				map.saveGame("minh");
			}
			if (key == 't')
			{
				//Load
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0; // reset pause menu selection
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if(!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				pos++;
				pos %= 3;
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}

void cGame::loading()
{
	PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
	map.printMap();
	map.deleteOldPlayer();
	drawTitle();
	gotoXY(30, 25);
	cout << "[";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(40);
		gotoXY(30 + i, 25);
		cout << "=>";
		gotoXY(30 + 25, 26);
		cout << i * 2 << "%";
	}
	//system("pause");
}

void cGame::loadGameMenu() { // get file of cMap map
	string filename;
	gotoXY(125, 25); 
	cout << "Input name to load: " << endl;
	getline(cin, filename);
	//file = file + ".txt";
	clrscr();
	//map.loadGame(filename);


}

void cGame::saveGameMenu() { // get file of cMap map
	string filename;
	gotoXY(125, 25);
	cout << "Input name to load: " << endl;
	getline(cin, filename);
	//file = file + ".txt";
	clrscr();
	map.saveGame(filename);
}

void cGame::togglePauseGame() { // toggle status of isPausing
	isPausing = !isPausing;
};

void cGame::gameOver() {
	cout << "Game over" << endl;
};

void cGame::toggleMute() {
	bool curMute = !isMute;
	#undef isMute
	if (curMute) {
		#define isMute true
	}
	else {
		#define isMute false
	}
}
