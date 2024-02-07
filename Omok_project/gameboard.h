/* 2018112075 이가현 */
#ifndef __gameboard_h
#define __gameboard_h
#include "header.h"
#include "weight.h"

/*GameBoard 클래스 구현*/
/*검은돌(사용자)의 형태가 어떤지를 기반으로 AI가 취할 행동을 제시 : 판단 & 착수까지 구현*/


int GameBoard::check_closed_4() {//닫힌 4목이 있는지 확인: 세 가지 경우의 수에 대해 다른 숫자 리턴하여 어떤 형태인지 판별

	// 1. x●●●●x꼴     -> x자리에 ○넣어야 됨 (앞의 x자리에 넣도록 하자)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0 && point[i][j + 5].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
			// 2. 세로로 4개 연속인 경우
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0 && point[j + 5][i].getCondition() == -1) {
				chaksu(j, i, false); return 1;
			}
			// 3. 대각선으로 4개 연속인 경우
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0 && point[i + 5][j + 5].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 5; j < BOARD_SIZE; j++) {
			// 4. 반대각선으로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0 && point[i + 5][j - 5].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}

	// 2. ○●●●●x꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로로 4개 연속인 경우
			if (point[i][j].getCondition() == 1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0 && point[i][j + 5].getCondition() == -1) {
				chaksu(i, j, false); return 2;
			}
			// 2. 세로로 4개 연속인 경우
			else if (point[j][i].getCondition() == 1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0 && point[j + 5][i].getCondition() == -1) {
				chaksu(j + 5, i, false); return 2;
			}
			// 3. 대각선으로 4개 연속인 경우
			else if (point[i][j].getCondition() == 1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0 && point[i + 5][j + 5].getCondition() == -1) {
				chaksu(i + 5, j + 5, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 5; j < BOARD_SIZE; j++) {
			// 4. 반대각선으로 4개 연속인 경우
			if (point[i][j].getCondition() == 1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0 && point[i + 5][j - 5].getCondition() == -1) {
				chaksu(i + 5, j - 5, false); return 2;
			}
		}
	}

	// 3. x●●●●○꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0 && point[i][j + 5].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
			// 2. 세로로 4개 연속인 경우
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0 && point[j + 5][i].getCondition() == 1) {
				chaksu(j, i, false); return 3;
			}
			// 3. 대각선으로 4개 연속인 경우
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0 && point[i + 5][j + 5].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 5; j < BOARD_SIZE; j++) {
			// 4. 반대각선으로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0 && point[i + 5][j - 5].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}

	// 4. ●●●●x꼴 (바둑판의 가장자리에서 시작하는 경우)   -> x자리에 ○넣어야 됨 
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 1. 왼쪽에서 오른쪽
		if (point[i][0].getCondition() == 0 && point[i][1].getCondition() == 0 && point[i][2].getCondition() == 0
			&& point[i][3].getCondition() == 0 && point[i][4].getCondition() == -1) {
			chaksu(i, 4, false); return 4;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 2. 오른쪽에서 왼쪽
		if (point[i][BOARD_SIZE - 1].getCondition() == 0 && point[i][BOARD_SIZE - 2].getCondition() == 0 && point[i][BOARD_SIZE - 3].getCondition() == 0
			&& point[i][BOARD_SIZE - 4].getCondition() == 0 && point[i][BOARD_SIZE - 5].getCondition() == -1) {
			chaksu(i, BOARD_SIZE - 5, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 3. 위에서 아래
		if (point[0][j].getCondition() == 0 && point[1][j].getCondition() == 0 && point[2][j].getCondition() == 0
			&& point[3][j].getCondition() == 0 && point[4][j].getCondition() == -1) {
			chaksu(4, j, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 4. 아래에서 위
		if (point[BOARD_SIZE - 1][j].getCondition() == 0 && point[BOARD_SIZE - 2][j].getCondition() == 0
			&& point[BOARD_SIZE - 3][j].getCondition() == 0 && point[BOARD_SIZE - 4][j].getCondition() == 0 && point[BOARD_SIZE - 5][j].getCondition() == -1) {
			chaksu(BOARD_SIZE - 5, j, false); return 4;
		}
	}
	// 5. 왼쪽 위 대각선에서 출발
	if (point[0][0].getCondition() == 0 && point[1][1].getCondition() == 0 && point[2][2].getCondition() == 0
		&& point[3][3].getCondition() == 0 && point[4][4].getCondition() == -1) {
		chaksu(4, 4, false); return 4;
	}
	// 6. 오른쪽 위 대각선에서 출발
	if (point[0][BOARD_SIZE - 1].getCondition() == 0 && point[1][BOARD_SIZE - 2].getCondition() == 0
		&& point[2][BOARD_SIZE - 3].getCondition() == 0 && point[3][BOARD_SIZE - 4].getCondition() == 0 && point[4][BOARD_SIZE - 5].getCondition() == -1) {
		chaksu(4, BOARD_SIZE - 5, false); return 4;
	}
	// 7. 왼쪽 아래 대각선에서 출발
	if (point[BOARD_SIZE - 1][0].getCondition() == 0 && point[BOARD_SIZE - 2][1].getCondition() == 0
		&& point[BOARD_SIZE - 3][2].getCondition() == 0 && point[BOARD_SIZE - 4][3].getCondition() == 0 && point[BOARD_SIZE - 5][4].getCondition() == -1) {
		chaksu(BOARD_SIZE - 5, 4, false); return 4;
	}
	// 8. 오른쪽 아래 대각선에서 출발
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 0 && point[BOARD_SIZE - 2][BOARD_SIZE - 2].getCondition() == 0
		&& point[BOARD_SIZE - 3][BOARD_SIZE - 3].getCondition() == 0 && point[BOARD_SIZE - 4][BOARD_SIZE - 4].getCondition() == 0 && point[BOARD_SIZE - 5][BOARD_SIZE - 5].getCondition() == -1) {
		chaksu(BOARD_SIZE - 5, BOARD_SIZE - 5, false); return 4;
	}

	return 0;//아무 형태에도 해당되지 않으면 0 리턴
}


int GameBoard::check_blanked_4() {//띈 4목이 있는지 : 세 가지 경우의 수에 대해 다른 숫자 리턴하여 어떤 형태인지 판별

	/*검은돌(사용자)의 형태가 어떤지?*/     //:: x는 비어 있는 것

	// 1. ●●x●●꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == -1 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0) {
				chaksu(i, j + 2, false); return 1;
			}
			// 2. 세로
			else if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == -1 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0) {
				chaksu(j + 2, i, false); return 1;
			}
			// 3. 대각선
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == -1 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0) {
				chaksu(i + 2, j + 2, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. 반대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == -1 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0) {
				chaksu(i + 2, j - 2, false); return 1;
			}
		}
	}

	// 2. ●●●x●꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == -1 && point[i][j + 4].getCondition() == 0) {
				chaksu(i, j + 3, false); return 2;
			}
			// 2. 세로
			if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == -1 && point[j + 4][i].getCondition() == 0) {
				chaksu(j + 3, i, false); return 2;
			}
			// 3. 대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == -1 && point[i + 4][j + 4].getCondition() == 0) {
				chaksu(i + 3, j + 3, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. 반대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == -1 && point[i + 4][j - 4].getCondition() == 0) {
				chaksu(i + 3, j - 3, false); return 2;
			}
		}
	}

	// 3. ●x●●●꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == -1 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0) {
				chaksu(i, j + 1, false); return 3;
			}
			// 2. 세로
			if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == -1 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0) {
				chaksu(j + 1, i, false); return 3;
			}
			// 3. 대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == -1 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0) {
				chaksu(i + 1, j + 1, false); return 3;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. 반대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == -1 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0) {
				chaksu(i + 1, j - 1, false); return 3;
			}
		}
	}

	return 0; //아무 형태에도 해당되지 않으면 0 리턴

}


int GameBoard::check_blanked_3() {//띈 3목이 있는지 확인 : 두 가지 경우의 수에 대해 다른 숫자 리턴하여 어떤 형태인지 판별

	// 1. ●x●●꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == -1 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0) {
				chaksu(i, j + 1, false); return 1;
			}
			// 2. 세로
			if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == -1 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0) {
				chaksu(j + 1, i, false); return 1;
			}
			// 3. 대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == -1 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0) {
				chaksu(i + 1, j + 1, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 3; j < BOARD_SIZE; j++) {
			// 4. 반대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == -1 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0) {
				chaksu(i + 1, j - 1, false); return 1;
			}
		}
	}
	// 2. ●●x●꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == -1 && point[i][j + 3].getCondition() == 0) {
				chaksu(i, j + 2, false); return 2;
			}
			// 2. 세로
			else if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == -1 && point[j + 3][i].getCondition() == 0) {
				chaksu(j + 2, i, false); return 2;
			}
			// 3. 대각선
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == -1 && point[i + 3][j + 3].getCondition() == 0) {
				chaksu(i + 2, j + 2, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 3; j < BOARD_SIZE; j++) {
			// 4. 반대각선
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == -1 && point[i + 3][j - 3].getCondition() == 0) {
				chaksu(i + 2, j - 2, false); return 2;
			}
			else return 0; //아무 형태에도 해당되지 않으면 0 리턴
		}
	}

	return 0;
}


int GameBoard::check_opened_3() {//열린 3목이 있는지 확인
	/*검은돌(사용자)의 형태가 어떤지?*/

	// 1. x●●●x꼴     -> x자리에 ○넣어야 됨 (앞의 x자리에 넣도록 하자)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
			// 2. 세로로 4개 연속인 경우
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == -1) {
				chaksu(j, i, false); return 1;
			}
			// 3. 대각선으로 4개 연속인 경우
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. 반대각선으로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}

	// 2. ○●●●x꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로로 4개 연속인 경우
			if (point[i][j].getCondition() == 1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == -1) {
				chaksu(i, j + 4, false); return 2;
			}
			// 2. 세로로 4개 연속인 경우
			else if (point[j][i].getCondition() == 1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == -1) {
				chaksu(j + 4, i, false); return 2;
			}
			// 3. 대각선으로 4개 연속인 경우
			else if (point[i][j].getCondition() == 1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == -1) {
				chaksu(i + 4, j + 4, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. 반대각선으로 4개 연속인 경우
			if (point[i][j].getCondition() == 1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == -1) {
				chaksu(i + 4, j - 4, false); return 2;
			}
		}
	}

	// 3. x●●●○꼴     -> x자리에 ○넣어야 됨
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. 가로로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
			// 2. 세로로 4개 연속인 경우
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 1) {
				chaksu(j, i, false); return 3;
			}
			// 3. 대각선으로 4개 연속인 경우
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. 반대각선으로 4개 연속인 경우
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}
	// 4. ●●●x꼴 (바둑판의 가장자리에서 시작하는 경우)   -> x자리에 ○넣어야 됨 
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 1. 왼쪽에서 오른쪽
		if (point[i][0].getCondition() == 0 && point[i][1].getCondition() == 0 && point[i][2].getCondition() == 0 && point[i][3].getCondition() == -1) {
			chaksu(i, 3, false); return 4;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 2. 오른쪽에서 왼쪽
		if (point[i][BOARD_SIZE - 1].getCondition() == 0 && point[i][BOARD_SIZE - 2].getCondition() == 0 && point[i][BOARD_SIZE - 3].getCondition() == 0 && point[i][BOARD_SIZE - 4].getCondition() == -1) {
			chaksu(i, BOARD_SIZE - 4, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 3. 위에서 아래
		if (point[0][j].getCondition() == 0 && point[1][j].getCondition() == 0 && point[2][j].getCondition() == 0 && point[3][j].getCondition() == -1) {
			chaksu(3, j, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 4. 아래에서 위
		if (point[BOARD_SIZE - 1][j].getCondition() == 0 && point[BOARD_SIZE - 2][j].getCondition() == 0 && point[BOARD_SIZE - 3][j].getCondition() == 0 && point[BOARD_SIZE - 4][j].getCondition() == -1) {
			chaksu(BOARD_SIZE - 4, j, false); return 4;
		}
	}
	// 5. 왼쪽 위 대각선에서 출발
	if (point[0][0].getCondition() == 0 && point[1][1].getCondition() == 0 && point[2][2].getCondition() == 0 && point[3][3].getCondition() == -1) {
		chaksu(3, 4, false); return 4;
	}
	// 6. 오른쪽 위 대각선에서 출발
	if (point[0][BOARD_SIZE - 1].getCondition() == 0 && point[1][BOARD_SIZE - 2].getCondition() == 0 && point[2][BOARD_SIZE - 3].getCondition() == 0 && point[3][BOARD_SIZE - 4].getCondition() == -1) {
		chaksu(3, BOARD_SIZE - 4, false); return 4;
	}
	// 7. 왼쪽 아래 대각선에서 출발
	if (point[BOARD_SIZE - 1][0].getCondition() == 0 && point[BOARD_SIZE - 2][1].getCondition() == 0 && point[BOARD_SIZE - 3][2].getCondition() == 0 && point[BOARD_SIZE - 4][3].getCondition() == -1) {
		chaksu(BOARD_SIZE - 4, 3, false); return 4;
	}
	// 8. 오른쪽 아래 대각선에서 출발
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 0 && point[BOARD_SIZE - 2][BOARD_SIZE - 2].getCondition() == 0 && point[BOARD_SIZE - 3][BOARD_SIZE - 3].getCondition() == 0 && point[BOARD_SIZE - 4][BOARD_SIZE - 4].getCondition() == -1) {
		chaksu(BOARD_SIZE - 4, BOARD_SIZE - 4, false); return 4;
	}

	return 0;//아무 형태에도 해당되지 않으면 0 리턴

}

bool GameBoard::check_5() {//승리조건 확인 & 누가 승리했는지 출력 (사용자가 승리했는지 AI가 승리했는지 출력)
	//true : 누군가가 승리함 , false : 승패가 결정나지 않음

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			/*검은돌(사용자)이 승리할 경우*/
			// 1. 가로로 5개 연속인 경우
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}
			// 2. 세로로 5개 연속인 경우
			else if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}
			// 3. 대각선으로 5개 연속인 경우
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}

			/*AI가 승리할 경우*/
			// 1. 가로로 5개 연속인 경우
			else if (point[i][j].getCondition() == 1 && point[i][j + 1].getCondition() == 1 && point[i][j + 2].getCondition() == 1 
				&& point[i][j + 3].getCondition() == 1 && point[i][j + 4].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
			// 2. 세로로 5개 연속인 경우
			else if (point[j][i].getCondition() == 1 && point[j + 1][i].getCondition() == 1 && point[j + 2][i].getCondition() == 1 
				&& point[j + 3][i].getCondition() == 1 && point[j + 4][i].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
			// 3. 대각선으로 5개 연속인 경우
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 1 && point[i + 2][j + 2].getCondition() == 1 
				&& point[i + 3][j + 3].getCondition() == 1 && point[i + 4][j + 4].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
		}
	}

	// 4. 반대각선으로 5개 연속인 경우
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			/*검은돌(사용자)이 승리할 경우*/
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}
			/*AI가 승리할 경우*/
			else if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 1 && point[i + 2][j - 2].getCondition() == 1 
				&& point[i + 3][j - 3].getCondition() == 1 && point[i + 4][j - 4].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
		}
	}

	return false;
}
#endif // !__gameboard_h