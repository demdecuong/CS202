#include"cEnemy.h"
#include"cGame.h"
#include"cConsole.h"

int main() {
	FixConsoleWindow();
	cPlayer a;
	a.draw();
	int tmp;
	char moving;
	cGame b;
	b.gameSettings();
	while (true) {
		tmp = toupper(_getch());
		moving = tmp;
		b.updatePosPlayer(moving);
	}
	system("pause");
}
