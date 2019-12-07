#include "Player.h"

Player::Player()
{
}

Player::Player(int positonHeight, int positionWidth) { //Khoi tao vi tri cua nguoi choi
	posW = positionWidth;
	posH = positonHeight;
}

int Player::getPositionW() {
	return posW;
}

int Player::getPositionH() {
	return posH;
}

void Player::setPositionW(int value) {
	posW = value;
}

void Player::moveLeft() { //Di chuyen nguoi choi sang ben trai
	posW--;
	if ((posW - PAD_LENGTH) <= 0) { //Neu cham bien ben trai thi dung lai
		posW++;
	}
}

void Player::moveRight() { //Di chuyen nguoi choi sang ben phai
	posW++;
	if ((posW + PAD_LENGTH) >= MAX_WIDTH - 1) { //Neu cham ben ben phai thi dung lai
		posW--;
	}
}