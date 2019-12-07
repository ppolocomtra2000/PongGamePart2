#include "Player.h"
#include "Ball.h"
#include <iostream>

#pragma once

using namespace std;

class Map
{
private:

	int map[MAX_HEIGHT][MAX_WIDTH];

public:
	Map();
	void PrintMap(); //Xuat ra man hinh cua tro choi
	void ResetMap(); //Dat lai man hinh ve co ban
	void SetMapObject(Player player1, Player player2, Ball ball); //Khoi tao cac object tren man hinh choi
};

