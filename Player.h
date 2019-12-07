#include "Constant.h"
#pragma once
class Player
{
private:
	int posH, posW;

public:
	Player();
	Player(int positonHeight, int positionWidth); //Khoi tao vi tri nguoi choi
	int getPositionW();
	int getPositionH();
	void setPositionW(int value);
	void moveLeft(); //Nguoi choi di chuyen sang trai
	void moveRight(); //Nguoi choi di chuyen sang phai
};