/* 2018112075 �̰��� */
#ifndef __gameboard_h
#define __gameboard_h
#include "header.h"
#include "weight.h"

/*GameBoard Ŭ���� ����*/
/*������(�����)�� ���°� ����� ������� AI�� ���� �ൿ�� ���� : �Ǵ� & �������� ����*/


int GameBoard::check_closed_4() {//���� 4���� �ִ��� Ȯ��: �� ���� ����� ���� ���� �ٸ� ���� �����Ͽ� � �������� �Ǻ�

	// 1. x�ܡܡܡ�x��     -> x�ڸ��� �۳־�� �� (���� x�ڸ��� �ֵ��� ����)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ���η� 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0 && point[i][j + 5].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
			// 2. ���η� 4�� ������ ���
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0 && point[j + 5][i].getCondition() == -1) {
				chaksu(j, i, false); return 1;
			}
			// 3. �밢������ 4�� ������ ���
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0 && point[i + 5][j + 5].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 5; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢������ 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0 && point[i + 5][j - 5].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}

	// 2. �ۡܡܡܡ�x��     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ���η� 4�� ������ ���
			if (point[i][j].getCondition() == 1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0 && point[i][j + 5].getCondition() == -1) {
				chaksu(i, j, false); return 2;
			}
			// 2. ���η� 4�� ������ ���
			else if (point[j][i].getCondition() == 1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0 && point[j + 5][i].getCondition() == -1) {
				chaksu(j + 5, i, false); return 2;
			}
			// 3. �밢������ 4�� ������ ���
			else if (point[i][j].getCondition() == 1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0 && point[i + 5][j + 5].getCondition() == -1) {
				chaksu(i + 5, j + 5, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 5; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢������ 4�� ������ ���
			if (point[i][j].getCondition() == 1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0 && point[i + 5][j - 5].getCondition() == -1) {
				chaksu(i + 5, j - 5, false); return 2;
			}
		}
	}

	// 3. x�ܡܡܡܡ۲�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ���η� 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0 && point[i][j + 5].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
			// 2. ���η� 4�� ������ ���
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0 && point[j + 5][i].getCondition() == 1) {
				chaksu(j, i, false); return 3;
			}
			// 3. �밢������ 4�� ������ ���
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0 && point[i + 5][j + 5].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 5; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢������ 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0 && point[i + 5][j - 5].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}

	// 4. �ܡܡܡ�x�� (�ٵ����� �����ڸ����� �����ϴ� ���)   -> x�ڸ��� �۳־�� �� 
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 1. ���ʿ��� ������
		if (point[i][0].getCondition() == 0 && point[i][1].getCondition() == 0 && point[i][2].getCondition() == 0
			&& point[i][3].getCondition() == 0 && point[i][4].getCondition() == -1) {
			chaksu(i, 4, false); return 4;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 2. �����ʿ��� ����
		if (point[i][BOARD_SIZE - 1].getCondition() == 0 && point[i][BOARD_SIZE - 2].getCondition() == 0 && point[i][BOARD_SIZE - 3].getCondition() == 0
			&& point[i][BOARD_SIZE - 4].getCondition() == 0 && point[i][BOARD_SIZE - 5].getCondition() == -1) {
			chaksu(i, BOARD_SIZE - 5, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 3. ������ �Ʒ�
		if (point[0][j].getCondition() == 0 && point[1][j].getCondition() == 0 && point[2][j].getCondition() == 0
			&& point[3][j].getCondition() == 0 && point[4][j].getCondition() == -1) {
			chaksu(4, j, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 4. �Ʒ����� ��
		if (point[BOARD_SIZE - 1][j].getCondition() == 0 && point[BOARD_SIZE - 2][j].getCondition() == 0
			&& point[BOARD_SIZE - 3][j].getCondition() == 0 && point[BOARD_SIZE - 4][j].getCondition() == 0 && point[BOARD_SIZE - 5][j].getCondition() == -1) {
			chaksu(BOARD_SIZE - 5, j, false); return 4;
		}
	}
	// 5. ���� �� �밢������ ���
	if (point[0][0].getCondition() == 0 && point[1][1].getCondition() == 0 && point[2][2].getCondition() == 0
		&& point[3][3].getCondition() == 0 && point[4][4].getCondition() == -1) {
		chaksu(4, 4, false); return 4;
	}
	// 6. ������ �� �밢������ ���
	if (point[0][BOARD_SIZE - 1].getCondition() == 0 && point[1][BOARD_SIZE - 2].getCondition() == 0
		&& point[2][BOARD_SIZE - 3].getCondition() == 0 && point[3][BOARD_SIZE - 4].getCondition() == 0 && point[4][BOARD_SIZE - 5].getCondition() == -1) {
		chaksu(4, BOARD_SIZE - 5, false); return 4;
	}
	// 7. ���� �Ʒ� �밢������ ���
	if (point[BOARD_SIZE - 1][0].getCondition() == 0 && point[BOARD_SIZE - 2][1].getCondition() == 0
		&& point[BOARD_SIZE - 3][2].getCondition() == 0 && point[BOARD_SIZE - 4][3].getCondition() == 0 && point[BOARD_SIZE - 5][4].getCondition() == -1) {
		chaksu(BOARD_SIZE - 5, 4, false); return 4;
	}
	// 8. ������ �Ʒ� �밢������ ���
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 0 && point[BOARD_SIZE - 2][BOARD_SIZE - 2].getCondition() == 0
		&& point[BOARD_SIZE - 3][BOARD_SIZE - 3].getCondition() == 0 && point[BOARD_SIZE - 4][BOARD_SIZE - 4].getCondition() == 0 && point[BOARD_SIZE - 5][BOARD_SIZE - 5].getCondition() == -1) {
		chaksu(BOARD_SIZE - 5, BOARD_SIZE - 5, false); return 4;
	}

	return 0;//�ƹ� ���¿��� �ش���� ������ 0 ����
}


int GameBoard::check_blanked_4() {//�� 4���� �ִ��� : �� ���� ����� ���� ���� �ٸ� ���� �����Ͽ� � �������� �Ǻ�

	/*������(�����)�� ���°� ���?*/     //:: x�� ��� �ִ� ��

	// 1. �ܡ�x�ܡܲ�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ����
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == -1 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0) {
				chaksu(i, j + 2, false); return 1;
			}
			// 2. ����
			else if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == -1 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0) {
				chaksu(j + 2, i, false); return 1;
			}
			// 3. �밢��
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == -1 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0) {
				chaksu(i + 2, j + 2, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == -1 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0) {
				chaksu(i + 2, j - 2, false); return 1;
			}
		}
	}

	// 2. �ܡܡ�x�ܲ�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ����
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == -1 && point[i][j + 4].getCondition() == 0) {
				chaksu(i, j + 3, false); return 2;
			}
			// 2. ����
			if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == -1 && point[j + 4][i].getCondition() == 0) {
				chaksu(j + 3, i, false); return 2;
			}
			// 3. �밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == -1 && point[i + 4][j + 4].getCondition() == 0) {
				chaksu(i + 3, j + 3, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == -1 && point[i + 4][j - 4].getCondition() == 0) {
				chaksu(i + 3, j - 3, false); return 2;
			}
		}
	}

	// 3. ��x�ܡܡܲ�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ����
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == -1 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0) {
				chaksu(i, j + 1, false); return 3;
			}
			// 2. ����
			if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == -1 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0) {
				chaksu(j + 1, i, false); return 3;
			}
			// 3. �밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == -1 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0) {
				chaksu(i + 1, j + 1, false); return 3;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == -1 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0) {
				chaksu(i + 1, j - 1, false); return 3;
			}
		}
	}

	return 0; //�ƹ� ���¿��� �ش���� ������ 0 ����

}


int GameBoard::check_blanked_3() {//�� 3���� �ִ��� Ȯ�� : �� ���� ����� ���� ���� �ٸ� ���� �����Ͽ� � �������� �Ǻ�

	// 1. ��x�ܡܲ�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ����
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == -1 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0) {
				chaksu(i, j + 1, false); return 1;
			}
			// 2. ����
			if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == -1 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0) {
				chaksu(j + 1, i, false); return 1;
			}
			// 3. �밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == -1 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0) {
				chaksu(i + 1, j + 1, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 3; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == -1 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0) {
				chaksu(i + 1, j - 1, false); return 1;
			}
		}
	}
	// 2. �ܡ�x�ܲ�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ����
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == -1 && point[i][j + 3].getCondition() == 0) {
				chaksu(i, j + 2, false); return 2;
			}
			// 2. ����
			else if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == -1 && point[j + 3][i].getCondition() == 0) {
				chaksu(j + 2, i, false); return 2;
			}
			// 3. �밢��
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == -1 && point[i + 3][j + 3].getCondition() == 0) {
				chaksu(i + 2, j + 2, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 3; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢��
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == -1 && point[i + 3][j - 3].getCondition() == 0) {
				chaksu(i + 2, j - 2, false); return 2;
			}
			else return 0; //�ƹ� ���¿��� �ش���� ������ 0 ����
		}
	}

	return 0;
}


int GameBoard::check_opened_3() {//���� 3���� �ִ��� Ȯ��
	/*������(�����)�� ���°� ���?*/

	// 1. x�ܡܡ�x��     -> x�ڸ��� �۳־�� �� (���� x�ڸ��� �ֵ��� ����)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ���η� 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
			// 2. ���η� 4�� ������ ���
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == -1) {
				chaksu(j, i, false); return 1;
			}
			// 3. �밢������ 4�� ������ ���
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢������ 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == -1) {
				chaksu(i, j, false); return 1;
			}
		}
	}

	// 2. �ۡܡܡ�x��     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ���η� 4�� ������ ���
			if (point[i][j].getCondition() == 1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == -1) {
				chaksu(i, j + 4, false); return 2;
			}
			// 2. ���η� 4�� ������ ���
			else if (point[j][i].getCondition() == 1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == -1) {
				chaksu(j + 4, i, false); return 2;
			}
			// 3. �밢������ 4�� ������ ���
			else if (point[i][j].getCondition() == 1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == -1) {
				chaksu(i + 4, j + 4, false); return 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢������ 4�� ������ ���
			if (point[i][j].getCondition() == 1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == -1) {
				chaksu(i + 4, j - 4, false); return 2;
			}
		}
	}

	// 3. x�ܡܡܡ۲�     -> x�ڸ��� �۳־�� ��
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// 1. ���η� 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 && point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
			// 2. ���η� 4�� ������ ���
			else if (point[j][i].getCondition() == -1 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 && point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 1) {
				chaksu(j, i, false); return 3;
			}
			// 3. �밢������ 4�� ������ ���
			else if (point[i][j].getCondition() == -1 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 && point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// 4. �ݴ밢������ 4�� ������ ���
			if (point[i][j].getCondition() == -1 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 && point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 1) {
				chaksu(i, j, false); return 3;
			}
		}
	}
	// 4. �ܡܡ�x�� (�ٵ����� �����ڸ����� �����ϴ� ���)   -> x�ڸ��� �۳־�� �� 
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 1. ���ʿ��� ������
		if (point[i][0].getCondition() == 0 && point[i][1].getCondition() == 0 && point[i][2].getCondition() == 0 && point[i][3].getCondition() == -1) {
			chaksu(i, 3, false); return 4;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		// 2. �����ʿ��� ����
		if (point[i][BOARD_SIZE - 1].getCondition() == 0 && point[i][BOARD_SIZE - 2].getCondition() == 0 && point[i][BOARD_SIZE - 3].getCondition() == 0 && point[i][BOARD_SIZE - 4].getCondition() == -1) {
			chaksu(i, BOARD_SIZE - 4, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 3. ������ �Ʒ�
		if (point[0][j].getCondition() == 0 && point[1][j].getCondition() == 0 && point[2][j].getCondition() == 0 && point[3][j].getCondition() == -1) {
			chaksu(3, j, false); return 4;
		}
	}
	for (int j = 0; j < BOARD_SIZE; j++) {
		// 4. �Ʒ����� ��
		if (point[BOARD_SIZE - 1][j].getCondition() == 0 && point[BOARD_SIZE - 2][j].getCondition() == 0 && point[BOARD_SIZE - 3][j].getCondition() == 0 && point[BOARD_SIZE - 4][j].getCondition() == -1) {
			chaksu(BOARD_SIZE - 4, j, false); return 4;
		}
	}
	// 5. ���� �� �밢������ ���
	if (point[0][0].getCondition() == 0 && point[1][1].getCondition() == 0 && point[2][2].getCondition() == 0 && point[3][3].getCondition() == -1) {
		chaksu(3, 4, false); return 4;
	}
	// 6. ������ �� �밢������ ���
	if (point[0][BOARD_SIZE - 1].getCondition() == 0 && point[1][BOARD_SIZE - 2].getCondition() == 0 && point[2][BOARD_SIZE - 3].getCondition() == 0 && point[3][BOARD_SIZE - 4].getCondition() == -1) {
		chaksu(3, BOARD_SIZE - 4, false); return 4;
	}
	// 7. ���� �Ʒ� �밢������ ���
	if (point[BOARD_SIZE - 1][0].getCondition() == 0 && point[BOARD_SIZE - 2][1].getCondition() == 0 && point[BOARD_SIZE - 3][2].getCondition() == 0 && point[BOARD_SIZE - 4][3].getCondition() == -1) {
		chaksu(BOARD_SIZE - 4, 3, false); return 4;
	}
	// 8. ������ �Ʒ� �밢������ ���
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 0 && point[BOARD_SIZE - 2][BOARD_SIZE - 2].getCondition() == 0 && point[BOARD_SIZE - 3][BOARD_SIZE - 3].getCondition() == 0 && point[BOARD_SIZE - 4][BOARD_SIZE - 4].getCondition() == -1) {
		chaksu(BOARD_SIZE - 4, BOARD_SIZE - 4, false); return 4;
	}

	return 0;//�ƹ� ���¿��� �ش���� ������ 0 ����

}

bool GameBoard::check_5() {//�¸����� Ȯ�� & ���� �¸��ߴ��� ��� (����ڰ� �¸��ߴ��� AI�� �¸��ߴ��� ���)
	//true : �������� �¸��� , false : ���а� �������� ����

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			/*������(�����)�� �¸��� ���*/
			// 1. ���η� 5�� ������ ���
			if (point[i][j].getCondition() == 0 && point[i][j + 1].getCondition() == 0 && point[i][j + 2].getCondition() == 0 
				&& point[i][j + 3].getCondition() == 0 && point[i][j + 4].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}
			// 2. ���η� 5�� ������ ���
			else if (point[j][i].getCondition() == 0 && point[j + 1][i].getCondition() == 0 && point[j + 2][i].getCondition() == 0 
				&& point[j + 3][i].getCondition() == 0 && point[j + 4][i].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}
			// 3. �밢������ 5�� ������ ���
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 0 && point[i + 2][j + 2].getCondition() == 0 
				&& point[i + 3][j + 3].getCondition() == 0 && point[i + 4][j + 4].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}

			/*AI�� �¸��� ���*/
			// 1. ���η� 5�� ������ ���
			else if (point[i][j].getCondition() == 1 && point[i][j + 1].getCondition() == 1 && point[i][j + 2].getCondition() == 1 
				&& point[i][j + 3].getCondition() == 1 && point[i][j + 4].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
			// 2. ���η� 5�� ������ ���
			else if (point[j][i].getCondition() == 1 && point[j + 1][i].getCondition() == 1 && point[j + 2][i].getCondition() == 1 
				&& point[j + 3][i].getCondition() == 1 && point[j + 4][i].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
			// 3. �밢������ 5�� ������ ���
			else if (point[i][j].getCondition() == 0 && point[i + 1][j + 1].getCondition() == 1 && point[i + 2][j + 2].getCondition() == 1 
				&& point[i + 3][j + 3].getCondition() == 1 && point[i + 4][j + 4].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
		}
	}

	// 4. �ݴ밢������ 5�� ������ ���
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			/*������(�����)�� �¸��� ���*/
			if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 0 && point[i + 2][j - 2].getCondition() == 0 
				&& point[i + 3][j - 3].getCondition() == 0 && point[i + 4][j - 4].getCondition() == 0) {
				cout << "PLAYER WINS" << endl; return true;
			}
			/*AI�� �¸��� ���*/
			else if (point[i][j].getCondition() == 0 && point[i + 1][j - 1].getCondition() == 1 && point[i + 2][j - 2].getCondition() == 1 
				&& point[i + 3][j - 3].getCondition() == 1 && point[i + 4][j - 4].getCondition() == 1) {
				cout << "AI WINS" << endl; return true;
			}
		}
	}

	return false;
}
#endif // !__gameboard_h