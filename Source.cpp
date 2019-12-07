#include <windows.h>
#include "Map.h"
#include "Player.h"
#include<conio.h>


void XoaManHinh() //Giup thao tac xuat lai man hinh muot ma hon
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;

	SetConsoleCursorPosition(hOut, Position);
}

int main() {
	SetConsoleTitle(TEXT("PONG GAME")); //Dat ten console la PONG GAME
	cout << "===== Please set console to fullscreen ====="<<endl<<endl<<"===== Press any key to begin =====";
	_getch();
	system("CLS");

	int ballDirection = DIR_LEFT_DOWN; //Huong bong khoi tao la di xuong huong ben trai
	int GameStatus = GAME_ON; //Trang thai game khoi tao la GAME_ON
	int Speed = 200; //Thoi gian ngu khoi tao se la 200 (0.2 second)

	Map map; //Khoi tao map
	Player player1 = Player(1, MAX_WIDTH/2); //Khoi tao nguoi choi 1 nam giua sat mep tren
	Player player2 = Player(MAX_HEIGHT-2, MAX_WIDTH/2); //Khoi tao nguoi choi 2 nam giua sat mep duoi
	Ball ball = Ball(MAX_HEIGHT/2, MAX_WIDTH/2); //Khoi tao bong o giua man hinh choi

	map.SetMapObject(player1, player2, ball); //Dat cac object vao man hinh choi
	map.PrintMap(); //Xuat ra man hinh choi

	while (TRUE)
	{
		if (GetAsyncKeyState('D')) { //Neu nhap phim D thi nguoi choi 1 di chuyen qua phai
			player1.moveRight();
		}
		
		if (GetAsyncKeyState('A')) { //Neu nhap phim A thi nguoi choi 1 di chuyen qua trai
			player1.moveLeft();
		}

		if (GetAsyncKeyState(VK_RIGHT)) { //Neu nhap mui ten qua phai thi nguoi choi 2 di chuyen qua phai
			player2.moveRight();
		}

		if (GetAsyncKeyState(VK_LEFT)) { //Neu nhap mui ten qua trai thi nguoi choi 2 di chuyen qua trai
			player2.moveLeft();
		}

		GameStatus = ball.autoMove(ballDirection, player1, player2, Speed); //Dat trang thai game theo gia tri ma ham di chuyen qua bong tra ve
		map.SetMapObject(player1, player2, ball); //Dat lai cac object vao man hinh choi (bong luon di chuyen, neu nguoi choi di chuyen thi dat lai)
		XoaManHinh();
		if (GameStatus == GAME_ON) //O trang thai GAME_ON thi xuat ra man hinh choi moi vong lap
			map.PrintMap();
		//Neu 1 trong 2 nguoi choi thang thi xoa man hinh choi, xuat ra ket qua va pha vong lap while
		else if (GameStatus == PLAYER1_WIN) {
			system("CLS");
			cout << "===== PLAYER 1 WINS !!! =====";
			break;
		}
		else {
			system("CLS");
			cout << "===== PLAYER 2 WINS !!! =====";
			break;
		}
		Sleep(Speed); //Thoi gian ngu cua console (Speed cang thap thi toc do tro choi cang cao)
	}

	Sleep(3000); //Dung man hinh trong 3 giay de nguoi choi nhin thay ket qua

	_getch();
	return 0;
}