#include "header.h"

void setGBdata() { //모든 위치에 대해 가중치 설정, 갱신
	
	// 1. 가장자리가 아닐 때
	for (int i = 1; i < BOARD_SIZE; i++) {  //for문을 돌리면서 : 바둑판 내의 모든 위치 확인
		for (int j=1 ; j < BOARD_SIZE; j++) {
			//흑돌이면(0) 주변 +2
			if (point[i][j].getCondition() == 0) {
				point[i - 1][j - 1].setWeight(2); point[i][j - 1].setWeight(2); point[i + 1][j - 1].setWeight(2);
				point[i - 1][j].setWeight(2); point[i + 1][j].setWeight(2); 
				point[i - 1][j + 1].setWeight(2); point[i][j + 1].setWeight(2); point[i + 1][j + 1].setWeight(2);
			}
			//백돌이면(1) 주변 -2
			if (point[i][j].getCondition() == 1) {
				point[i - 1][j - 1].setWeight(-2); point[i][j - 1].setWeight(-2); point[i + 1][j - 1].setWeight(-2);
				point[i - 1][j].setWeight(-2); point[i + 1][j].setWeight(-2);
				point[i - 1][j + 1].setWeight(-2); point[i][j + 1].setWeight(-2); point[i + 1][j + 1].setWeight(-2);
			}			
		}
	}

	// 2. 가장자리(변)일 때
	//왼쪽 변
	for (int i = 1; i < BOARD_SIZE; i++) {
		if (point[i][0].getCondition() == 0) { //흑
			point[i - 1][0].setWeight(2); point[i + 1][0].setWeight(2); 
			point[i - 1][1].setWeight(2); point[i][1].setWeight(2); point[i + 1][1].setWeight(2);
		}
		if (point[i][0].getCondition() == 1) { //백
			point[i - 1][0].setWeight(-2); point[i + 1][0].setWeight(-2);
			point[i - 1][1].setWeight(-2); point[i][1].setWeight(-2); point[i + 1][1].setWeight(-2);
		}
	}
	//오른쪽 변
	for (int i = 1; i < BOARD_SIZE; i++) {
		if (point[i][BOARD_SIZE - 1].getCondition() == 0) {
			point[i - 1][BOARD_SIZE - 1].setWeight(2); point[i + 1][BOARD_SIZE - 1].setWeight(2);
			point[i - 1][BOARD_SIZE - 2].setWeight(2); point[i][BOARD_SIZE - 2].setWeight(2); point[i + 1][BOARD_SIZE - 2].setWeight(2);
		}
		if (point[i][BOARD_SIZE - 1].getCondition() == 1) {
			point[i - 1][BOARD_SIZE - 1].setWeight(-2); point[i + 1][BOARD_SIZE - 1].setWeight(-2);
			point[i - 1][BOARD_SIZE - 2].setWeight(-2); point[i][BOARD_SIZE - 2].setWeight(-2); point[i + 1][BOARD_SIZE - 2].setWeight(-2);
		}
	}
	//위쪽 변
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[0][j].getCondition() == 0) {
			point[0][j - 1].setWeight(2); point[0][j + 1].setWeight(2);
			point[1][j - 1].setWeight(2); point[1][j].setWeight(2); point[1][j + 1].setWeight(2);
		}
		if (point[0][j].getCondition() == 1) {
			point[0][j - 1].setWeight(-2); point[0][j + 1].setWeight(-2);
			point[1][j - 1].setWeight(-2); point[1][j].setWeight(-2); point[1][j + 1].setWeight(-2);
		}
	}
	//아래쪽 변
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[BOARD_SIZE-1][j].getCondition() == 0) {
			point[BOARD_SIZE - 1][j - 1].setWeight(2); point[BOARD_SIZE - 1][j + 1].setWeight(2);
			point[BOARD_SIZE - 2][j - 1].setWeight(2); point[BOARD_SIZE - 2][j].setWeight(2); point[BOARD_SIZE - 2][j + 1].setWeight(2);
		}
	}

	// 3. 가장자리(꼭짓점)일 때
	//왼쪽 위
	if (point[0][0].getCondition() == 0) { point[1][0].setWeight(2); point[0][1].setWeight(2); point[1][1].setWeight(2); } //흑돌
	if (point[0][0].getCondition() == 1) { point[1][0].setWeight(-2); point[0][1].setWeight(-2); point[1][1].setWeight(-2); } //백돌
	//오른쪽 위
	if (point[0][BOARD_SIZE - 1].getCondition() == 0 ) { point[0][BOARD_SIZE-2].setWeight(2); point[1][BOARD_SIZE-2].setWeight(2); point[1][BOARD_SIZE-1].setWeight(2); } //흑돌
	if (point[0][BOARD_SIZE - 1].getCondition() == 1) { point[0][BOARD_SIZE - 2].setWeight(-2); point[1][BOARD_SIZE - 2].setWeight(-2); point[1][BOARD_SIZE - 1].setWeight(-2); }//백돌
	//왼쪽 아래
	if (point[BOARD_SIZE - 1][0].getCondition() == 0) { point[BOARD_SIZE - 2][0].setWeight(2); point[BOARD_SIZE - 2][1].setWeight(2); point[BOARD_SIZE - 1][1].setWeight(2); } //흑돌
	if (point[BOARD_SIZE - 1][0].getCondition() == 1) { point[BOARD_SIZE - 2][0].setWeight(-2); point[BOARD_SIZE - 2][1].setWeight(-2); point[BOARD_SIZE - 1][1].setWeight(-2); } //백돌
	//오른쪽 아래
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 0) { point[BOARD_SIZE - 1][BOARD_SIZE - 2].setWeight(2); point[BOARD_SIZE - 2][BOARD_SIZE - 2].setWeight(2); point[BOARD_SIZE - 2][BOARD_SIZE - 1].setWeight(2); } //흑돌
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 1) { point[BOARD_SIZE - 1][BOARD_SIZE - 2].setWeight(-2); point[BOARD_SIZE - 2][BOARD_SIZE - 2].setWeight(-2); point[BOARD_SIZE - 2][BOARD_SIZE - 1].setWeight(-2); } //백돌
}

int GameBoard::getGBdata(Location p) {
	//리턴값 : 비어 있을 경우 해당 위치의 가중치, 돌이 있을 경우 -500을 리턴
	
	int row = p.getRow(); int col = p.getCol();
	if (point[row][col].getCondition() == -1) { //해당 위치가 비어 있는 경우 가중치를 리턴
		return p.getWeight();
	}
	else { //해당 위치에 돌이 있으면 -500을 리턴
		return -500;
	}

}


/*
	착수하는 함수에서 모든 위치에 대해 가중치를 계산해서
	setGBData함수를 만들어서 가중치를 set함
	getGBData에서는 가중치를 리턴함
*/