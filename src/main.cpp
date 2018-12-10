#include"cEnemy.h"
#include"cGame.h"
#include"cConsole.h"

int main() {
	FixConsoleWindow();
	bool reset = false;

	do {
		startGame(reset, 1);
	} while (reset);
	
	system("pause");
}
