#include <iostream>
#include <iomanip>
#include <thread>
#include <Windows.h>
#include <mmsystem.h>


#include "cMap.h"
#include "cGame.h"
#include "cTruck.h"
#include "cCar.h"
#include "cBird.h"
#include "cDinosaur.h"
#include "cConsole.h"

using namespace std;
/*void drawTitle()
{
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






}
void drawMember()
{
	srand(time(NULL));
	int color = rand() % 10 + 1;
	gotoXY(40, 50);
	//TextColor(color);
	cout << setw(10) << "Minh Nguyen - Ngan Vo - Huy Nguyen - Duy Nguyen" << endl;
}
void consoleMenu()
{
	string Menu[SIZE] = { "New Game","Load Game" ,"Options", "Exit" };
	int pointer = 0;

	while (true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		TextColor(10);
		gotoXY(40, 40);
		cout << setw(32) << "MAIN MENU\n\n";
		//Display 
		for (int i = 0; i < SIZE; ++i)
		{
			// display the backgound color for Pointed text
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << setw(60) << right << i + 1 << ". " << Menu[i] << endl;
		}
		drawTitle();
		drawMember();
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = SIZE - 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == SIZE)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					cout << "Starting new game...";
					
					Sleep(1000);
				} break;
				case 1:
				{
					cout << "Load game..." << endl;
					Sleep(1000);
				}break;
				case 2:
				{
					cout << "This is the options...";
					Sleep(1000);
				} break;
				case 3:
				{
					clrscr();
					cout << "See u again..." << endl;
					Sleep(1000);
					return;
				} break;
				}
				break;
			}
		}
		Sleep(150);
	}
}*/

int main() {
	srand(time(NULL));
	//DisableMouse();

	cGame game;
	game.newGame();
//	PlaySound(TEXT("trafficjam.wav"), NULL, SND_ASYNC);


	system("pause");
}