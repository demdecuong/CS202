#include "cPlayer.h"





void cPlayer::killPlayer() {

	isDead = true;

}



char ** cPlayer::shape() {

	return a;

}



/*cPosition cPlayer::getPos() {

	return pos;

}*/



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

void cPlayer::draw() {

	cout << "Y";
}

void cPlayer::deleteChar() {
	gotoXY(pX, pY);
	cout << " ";
}

