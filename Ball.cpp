#include "Ball.h"

Ball::Ball()
{
}
//Input: toa do cua bong
Ball::Ball(int positionH, int positionW) {
	posH = positionH;
	posW = positionW;
}

int Ball::getPosHeight() {
	return posH;
}

int Ball::getPosWidth() {
	return posW;
}


//Input: Huong di chuyen hien tai cua bong, vi tri cua 2 nguoi choi, thoi gian sleep cua console
//Output: Trang thai cua tro choi
int Ball::autoMove(int& direction, Player player1, Player player2, int& time) {
	int temp = time * 0.1; //temp la 10% cua thoi gian ngu ban dau
	switch (direction) //Kiem tra cac truong hop di chuyen cua bong
	{
	case DIR_LEFT_DOWN: //Truong hop bong di xuong theo huong ben trai
		posH++;
		posW--;
		//Neu cham bien doc thi dung lai va doi huong di chuyen
		if (posW == 0) {
			posH--;
			posW++;
			direction = DIR_RIGHT_DOWN;
			autoMove(direction, player1, player2, time);
		}
		//Neu cham bien ngang thi dung lai va tra ve gia tri nguoi choi 1 thang
		else if (posH == MAX_HEIGHT - 1) {
			posH--;
			posW++;
			return PLAYER1_WIN;
		}
		//Neu cham nguoi choi 2 thi dung lai, doi huong di chuyen va giam thoi gian sleep di 10%
		else if (posH == player2.getPositionH()) {
			if (posW <= (player2.getPositionW() + PAD_LENGTH) && posW >= (player2.getPositionW() - PAD_LENGTH)) {
				posH--;
				posW++;
				time -= temp;
				direction = DIR_LEFT_UP;
				autoMove(direction, player1, player2, time);
			}
		}
		break;
	case DIR_LEFT_UP: //Truong hop di len theo huong ben trai
		posH--;
		posW--;
		//Neu cham bien doc thi dung lai va doi huong di chuyen
		if (posW == 0) {
			posH++;
			posW++;
			direction = DIR_RIGHT_UP;
			autoMove(direction, player1, player2, time);
		} 
		//Neu cham bien ngang thi dung lai va tra ve gia tri nguoi choi 2 thang
		else if (posH == 0) {
			posH++;
			posW++;
			return PLAYER2_WIN;
		} 
		//Neu cham nguoi choi 1 thi dung lai, doi huong di chuyen va giam thoi gian sleep di 10%
		else if (posH == player1.getPositionH()) {
			if (posW <= (player1.getPositionW() + PAD_LENGTH) && posW >= (player1.getPositionW() - PAD_LENGTH)) {
				posH++;
				posW++;
				time -= temp;
				direction = DIR_LEFT_DOWN;
				autoMove(direction, player1, player2, time);
			}
		}
		break;
	case DIR_RIGHT_DOWN: //Truong hop di xuong theo huong ben phai
		posH++;
		posW++;
		//Neu cham bien doc thi dung lai va doi huong di chuyen
		if (posW == MAX_WIDTH - 1) {
			posH--;
			posW--;
			direction = DIR_LEFT_DOWN;
			autoMove(direction, player1, player2, time);
		}
		//Neu cham bien ngang thi dung lai va tra ve gia tri nguoi choi 1 thang
		else if (posH == MAX_HEIGHT - 1) {
			posH--;
			posW--;
			return PLAYER1_WIN;
		}
		//Neu cham nguoi choi 2 thi dung lai, doi huong di chuyen va giam thoi gian sleep di 10%
		else if (posH == player2.getPositionH()) {
			if (posW <= (player2.getPositionW() + PAD_LENGTH) && posW >= (player2.getPositionW() - PAD_LENGTH)) {
				posH--;
				posW++;
				time -= temp;
				direction = DIR_RIGHT_UP;
				autoMove(direction, player1, player2, time);
			}
		}
		break;
	case DIR_RIGHT_UP: //Truong hop di len theo huong ben phai
		posH--;
		posW++;
		//Neu cham bien doc thi dung lai va doi huong di chuyen
		if (posW == MAX_WIDTH-1) {
			posH++;
			posW--;
			direction = DIR_LEFT_UP;
			autoMove(direction, player1, player2, time);
		} 
		//Neu cham bien ngang thi dung lai va tra ve gia tri nguoi choi 2 thang
		else if (posH == 0) {
			posH++;
			posW--;
			return PLAYER2_WIN;
		} 
		//Neu cham nguoi choi 1 thi dung lai, doi huong di chuyen va giam thoi gian sleep di 10%
		else if (posH == player1.getPositionH()) {
			if (posW <= (player1.getPositionW() + PAD_LENGTH) && posW >= (player1.getPositionW() - PAD_LENGTH)) {
				posH++;
				posW--;
				time -= temp;
				direction = DIR_RIGHT_DOWN;
				autoMove(direction, player1, player2, time);
			}
		}
		break;
	default:
		return GAME_ON;
	}
	return GAME_ON;
}