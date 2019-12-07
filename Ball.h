#include "Player.h"
#pragma once
class Ball
{
private:
	int posH, posW;

public:
	Ball();
	Ball(int postionH, int postionW); //Khoi tao vi tri ban dau cua bong
	int getPosHeight();
	int getPosWidth();
	int autoMove(int& direction, Player player1, Player player2, int& time); //Dieu chinh huong bong va tuong tac voi cac object khac
};

