#include "cPlayer.h"

cPlayer::cPlayer() {
	a = new char*[3];
	for (int i = 0; i < 3; i++)
		a[i] = new char[5];
}

cPlayer::~cPlayer() {
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}

cPlayer::cPlayer(cPosition pos) {
	this->pos = pos;
}



void cPlayer::killPlayer() {

	isDead = true;

}



char ** cPlayer::shape() {
	//Row1

	for (int i = 0; i < 5; i++) {

		if (i == 2)
			a[0][i] = 'O';

		else

			a[0][i] = ' ';

	}

	//Row2

	for (int i = 0; i < 5; i++) {

		if (i == 0)	a[1][i] = '/';
		if (i == 1)	a[1][i] = '(';
		if (i == 2)	a[1][i] = '_';
		if (i == 3)	a[1][i] = ')';
		if (i == 4)	a[1][i] = '\\';


	}

	//Row3

	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}

	return a;

}



cPosition cPlayer::getPos() {

	return pos;

}



int cPlayer::getHeight() {

	return width;

}



int cPlayer::getWidth() {

	return height;

}

void cPlayer::Up() {
	deleteChar();
	pY -= height;
	gotoXY(pX, pY);
	draw();
}

void cPlayer::Down() {
	deleteChar();
	pY += height;
	gotoXY(pX, pY);
	draw();
}

void cPlayer::Left() {
	deleteChar();
	pX -= width;
	gotoXY(pX, pY);
	draw();
}

void cPlayer::Right() {
	deleteChar();
	pX += width;
	gotoXY(pX, pY);
	draw();
}

void cPlayer::draw() { //demo thoi nha (ham draw nay khong can)

	cout << "Y";
}

void cPlayer::deleteChar() {
	gotoXY(pX, pY);
	cout << "     ";
}

