#include "Map.h"
#include<windows.h>

void DoiMauChuGD(int a) //Ham to mau
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

Map::Map() //Constructor cua man hinh choi
{
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (i == 0 || i == MAX_HEIGHT-1) { //Dat hang dau tien voi cuoi cung la bien ngang
				map[i][j] = WALL_CHAR;
			}
			else if (j == 0 || j == MAX_WIDTH - 1) //Dat cot dau tien va cuoi cung la bien doc
			{
				map[i][j] = WALL_CHAR;
			}
			else if (i == MAX_HEIGHT/2) { //Dat hang chinh giua la vach ke giua
				map[i][j] = MIDDLE_MAP_CHAR;
			}
			else {
				map[i][j] = MAP_CHAR; //Dat nhung phan con lai la khoang trong
			}
		}
	}
}

// Xuat ra man hinh choi
void Map::PrintMap() {
	//Xet man hinh choi la mang 2 chieu
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (map[i][j] == MAP_CHAR) { //Neu vi tri do la khoang trong thi xuat ra "  "
				cout << " ";
			}
			else if (map[i][j] == WALL_CHAR) { //Neu vi tri do la bien thi xuat ra ki tu 219 trong bang ma ASCII voi ma mau 2
				DoiMauChuGD(2);
				cout << (char)219;
			}
			else if (map[i][j] == MIDDLE_MAP_CHAR) { //Neu vi tri do la vach ke giua thi xuat ra ki tu 250 trong bang ma ASCII voi ma mau 15
				DoiMauChuGD(15);
				cout << (char)250;
			}
			else if (map[i][j] == PLAYER_CHAR) { //Neu vi tri do la nguoi choi thi xuat ra ki tu 205 trong bang ma ASCII voi ma mau 12
				DoiMauChuGD(12);
				cout << (char)205;
			}
			else if (map[i][j] == BALL_CHAR) { //Neu vi tri do la qua bong thi xuat ra ki tu 15 trong bang ma ASCII voi ma mau 9
				DoiMauChuGD(9);
				cout << (char)15;
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void Map::ResetMap() { //Dat lai man hinh choi ve co ban
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (i == 0 || i == MAX_HEIGHT-1) { //Dat hang dau tien voi cuoi cung la bien ngang
				map[i][j] = WALL_CHAR;
			}
			else if (j == 0 || j == MAX_WIDTH - 1) //Dat cot dau tien va cuoi cung la bien doc
			{
				map[i][j] = WALL_CHAR;
			}
			else if (i == MAX_HEIGHT/2) { //Dat hang chinh giua la vach ke giua
				map[i][j] = MIDDLE_MAP_CHAR;
			}
			else { //Dat nhung phan con lai la khoang trong
				map[i][j] = MAP_CHAR;
			}
		}
	}
}

void Map::SetMapObject(Player player1, Player player2, Ball ball) { //Khoi tao cac object cho man hinh choi
	ResetMap(); //Dat man hinh ve trong rong

	map[player1.getPositionH()][player1.getPositionW()] = PLAYER_CHAR; //Dat vi tri nguoi choi len man hinh choi (player 1)
	for (int i = 1; i <= PAD_LENGTH; i++) { //Keo dai nguoi choi ra 2 ben de duoc thanh truot
		map[player1.getPositionH()][player1.getPositionW() + i] = PLAYER_CHAR;
		map[player1.getPositionH()][player1.getPositionW() - i] = PLAYER_CHAR;
	}

	map[player2.getPositionH()][player2.getPositionW()] = PLAYER_CHAR; //Dat vi tri thanh truot len man hinh choi (player 2)
	for (int i = 1; i <= PAD_LENGTH; i++) { //Keo dai nguoi choi ra 2 ben de duoc thanh truot
		map[player2.getPositionH()][player2.getPositionW() + i] = PLAYER_CHAR;
		map[player2.getPositionH()][player2.getPositionW() - i] = PLAYER_CHAR;
	}

	map[ball.getPosHeight()][ball.getPosWidth()] = BALL_CHAR; //Dat vi tri cua qua bong len man hinh choi
}