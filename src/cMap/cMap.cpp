#include "cMap.h"
#include "cConsole.h"

void cMap::printMap()
{
	int temp1 = width, temp2 = height;
	TextColor(14);
	cout << " " << (char)218;
	for (int i = 0; i<width; i++)
		cout << (char)196;
	cout << (char)191 << endl;
	while (temp2 > 0) {
		cout << " " << (char)179;
		for (int i = 0; i < temp1; i++)
			cout << " ";
		cout << (char)179 << endl;
		temp2--;
	}
	cout << " " << (char)192;
	for (int i = 0; i < temp1; i++)
		cout << (char)196;
	cout << (char)217 << endl;
}
