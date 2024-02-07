/* 2018112075 이가현 */
#include "header.h"
#include "weight.h"
#include "gameboard.h"

int main() {

	GameBoard USER; // 사용자 객체
	GameBoard AI; // AI 객체
	int x, y; // x,y좌표

	//기본 바둑판을 그리고 시작 : 바둑판 초기화
	cout << " ";
	for (int k = 0; k < BOARD_SIZE; k++) {
		cout << " " <<k << " ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i;
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << " + ";
		}
		cout << endl;
	}

	// 모든 좌표 상태를 - 1로 초기화 (-1 : 비어있음)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			point[i][j].set(i, j); //x,y좌표 저장
			point[i][j].setCondition(-1);	 //그 좌표 상태 초기화		
			point[i][j].setWeight(0); //좌표 가중치 초기화
		}
	}

	//누군가가 이길 때까지 계속 반복
	while (1) {		

		if (USER.check_5() == true || AI.check_5() == true) {//누군가가 이기면 루프를 빠져나오고 게임은 끝남
			break; cout<< endl << "GAME OVER" << endl;
		}

		//	1. 사용자로부터 흑돌의 위치를 입력받음

		bool stone = true; 
		cout << "사용자(흑돌) : 착수할 위치를 입력하세요>>";
		cin >> x >> y; //착수할 x,y좌표를 입력받음
		chaksu(x, y, true);



		//	2. AI가 위치를 판단하여 흰돌을 놓음 

		// => 어떤 경우에 해당이 된다면 그 함수 내에서 착수까지 진행될 것임. 그리고 0이 아닌 수를 리턴
		// => 아무 경우의 수에도 해당 되지 않을 경우 가중치를 불러와서 가중치가 가장 큰 위치에 착수
		stone = false;	
		if (AI.check_closed_4() == 0 && AI.check_blanked_4() == 0 && AI.check_blanked_3() == 0 && AI.check_opened_3() == 0) {//아무 경우의 수에도 해당 되지 않을 경우

			int max = AI.getGBdata(point[0][0]); //가중치 최댓값
			int weight; //가중치
			int x, y; //가중치 최대가 되는 점의 x,y좌표

			// 모든 위치의 가중치를 불러와서 비교함
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					weight = AI.getGBdata(point[i][j]);
					if (weight > max) {
						max = weight;
						x = i; y = j;
					}
				}
			}
			//그리고 가중치가 가장 큰 위치 선택, 거기에 착수
			chaksu(x, y, false);
		}
		else {
			int s;
			//s = AI.check_closed_4(); s = AI.check_blanked_4(); s = AI.check_blanked_3(); s = AI.check_opened_3();
		}

		cout << endl;
		//이걸 반복


	}

	return 0;
}