/* 2018112075 이가현 */
#ifndef __weight_h
#define __weight_h
#include "header.h"

Location point[BOARD_SIZE][BOARD_SIZE];

/*
	setGBData : 가중치를 set함
	getGBData :  가중치를 리턴함
	chaksu :  돌을 착수시키고 이를 반영한 오목판을 새로 출력
*/

void setGBdata() { //모든 위치에 대해 가중치 설정, 갱신

	// 1. 가장자리가 아닐 때
	for (int i = 1; i < BOARD_SIZE; i++) {  //for문을 돌리면서 : 바둑판 내의 모든 위치 확인
		for (int j = 1; j < BOARD_SIZE; j++) {
			//흑돌이면(0) 주변 가중치 +2
			if (point[i][j].getCondition() == 0) {
				point[i - 1][j - 1].setWeight(2); point[i][j - 1].setWeight(2); point[i + 1][j - 1].setWeight(2);
				point[i - 1][j].setWeight(2); point[i + 1][j].setWeight(2);
				point[i - 1][j + 1].setWeight(2); point[i][j + 1].setWeight(2); point[i + 1][j + 1].setWeight(2);
			}
			//백돌이면(1) 주변 가중치 -2
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
		if (point[i][BOARD_SIZE - 1].getCondition() == 0) { //흑
			point[i - 1][BOARD_SIZE - 1].setWeight(2); point[i + 1][BOARD_SIZE - 1].setWeight(2);
			point[i - 1][BOARD_SIZE - 2].setWeight(2); point[i][BOARD_SIZE - 2].setWeight(2); point[i + 1][BOARD_SIZE - 2].setWeight(2);
		}
		if (point[i][BOARD_SIZE - 1].getCondition() == 1) { //백
			point[i - 1][BOARD_SIZE - 1].setWeight(-2); point[i + 1][BOARD_SIZE - 1].setWeight(-2);
			point[i - 1][BOARD_SIZE - 2].setWeight(-2); point[i][BOARD_SIZE - 2].setWeight(-2); point[i + 1][BOARD_SIZE - 2].setWeight(-2);
		}
	}
	//위쪽 변
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[0][j].getCondition() == 0) { //흑
			point[0][j - 1].setWeight(2); point[0][j + 1].setWeight(2);
			point[1][j - 1].setWeight(2); point[1][j].setWeight(2); point[1][j + 1].setWeight(2);
		}
		if (point[0][j].getCondition() == 1) { //백
			point[0][j - 1].setWeight(-2); point[0][j + 1].setWeight(-2);
			point[1][j - 1].setWeight(-2); point[1][j].setWeight(-2); point[1][j + 1].setWeight(-2);
		}
	}
	//아래쪽 변
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[BOARD_SIZE - 1][j].getCondition() == 0) { //흑
			point[BOARD_SIZE - 1][j - 1].setWeight(2); point[BOARD_SIZE - 1][j + 1].setWeight(2);
			point[BOARD_SIZE - 2][j - 1].setWeight(2); point[BOARD_SIZE - 2][j].setWeight(2); point[BOARD_SIZE - 2][j + 1].setWeight(2);
		}
		if (point[BOARD_SIZE - 1][j].getCondition() == 1) { //백
			point[BOARD_SIZE - 1][j - 1].setWeight(-2); point[BOARD_SIZE - 1][j + 1].setWeight(-2);
			point[BOARD_SIZE - 2][j - 1].setWeight(-2); point[BOARD_SIZE - 2][j].setWeight(-2); point[BOARD_SIZE - 2][j + 1].setWeight(-2);
		}
	}

	// 3. 가장자리(꼭짓점)일 때
	//왼쪽 위
	if (point[0][0].getCondition() == 0) { point[1][0].setWeight(2); point[0][1].setWeight(2); point[1][1].setWeight(2); } //흑돌
	if (point[0][0].getCondition() == 1) { point[1][0].setWeight(-2); point[0][1].setWeight(-2); point[1][1].setWeight(-2); } //백돌
	//오른쪽 위
	if (point[0][BOARD_SIZE - 1].getCondition() == 0) { point[0][BOARD_SIZE - 2].setWeight(2); point[1][BOARD_SIZE - 2].setWeight(2); point[1][BOARD_SIZE - 1].setWeight(2); } //흑돌
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
	else { //해당 위치에 돌이 있으면 -500(매우 작은 수)을 리턴
		return -500;
	}

}

void chaksu(int x, int y, bool stone) {
	//(x,y) 좌표에 착수, stone으로 흑백 판별,  새로운 오목판 출력

	if (stone == true) { //흑돌(사용자) 차례이면
		point[x][y].set(x, y); //좌표 저장
		point[x][y].setCondition(0); //그 좌표 0으로 초기화
	}
	else { //백돌(AI) 차례이면
		point[x][y].set(x, y);//좌표 저장
		point[x][y].setCondition(1); //그 좌표 1로 초기화
	}

	cout << " ";
	for (int k = 0; k < BOARD_SIZE; k++) {
		cout << " " << k << " ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i;
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (point[i][j].getCondition() == -1) cout << " + "; //격자를 그림
			else if (point[i][j].getCondition() == 0) cout << " ●"; //검은돌(사용자) 착수 시 흑돌 그림
			else if (point[i][j].getCondition() == 1) cout << " ○"; //흰돌(AI) 착수 시 흰돌 그림
		}
		cout << endl;
	}


	setGBdata(); // 모든 위치에 대해 가중치 갱신
}



#endif // ! __weight_h