#include "header.h"

void setGBdata() { //��� ��ġ�� ���� ����ġ ����, ����
	
	// 1. �����ڸ��� �ƴ� ��
	for (int i = 1; i < BOARD_SIZE; i++) {  //for���� �����鼭 : �ٵ��� ���� ��� ��ġ Ȯ��
		for (int j=1 ; j < BOARD_SIZE; j++) {
			//�浹�̸�(0) �ֺ� +2
			if (point[i][j].getCondition() == 0) {
				point[i - 1][j - 1].setWeight(2); point[i][j - 1].setWeight(2); point[i + 1][j - 1].setWeight(2);
				point[i - 1][j].setWeight(2); point[i + 1][j].setWeight(2); 
				point[i - 1][j + 1].setWeight(2); point[i][j + 1].setWeight(2); point[i + 1][j + 1].setWeight(2);
			}
			//�鵹�̸�(1) �ֺ� -2
			if (point[i][j].getCondition() == 1) {
				point[i - 1][j - 1].setWeight(-2); point[i][j - 1].setWeight(-2); point[i + 1][j - 1].setWeight(-2);
				point[i - 1][j].setWeight(-2); point[i + 1][j].setWeight(-2);
				point[i - 1][j + 1].setWeight(-2); point[i][j + 1].setWeight(-2); point[i + 1][j + 1].setWeight(-2);
			}			
		}
	}

	// 2. �����ڸ�(��)�� ��
	//���� ��
	for (int i = 1; i < BOARD_SIZE; i++) {
		if (point[i][0].getCondition() == 0) { //��
			point[i - 1][0].setWeight(2); point[i + 1][0].setWeight(2); 
			point[i - 1][1].setWeight(2); point[i][1].setWeight(2); point[i + 1][1].setWeight(2);
		}
		if (point[i][0].getCondition() == 1) { //��
			point[i - 1][0].setWeight(-2); point[i + 1][0].setWeight(-2);
			point[i - 1][1].setWeight(-2); point[i][1].setWeight(-2); point[i + 1][1].setWeight(-2);
		}
	}
	//������ ��
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
	//���� ��
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
	//�Ʒ��� ��
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[BOARD_SIZE-1][j].getCondition() == 0) {
			point[BOARD_SIZE - 1][j - 1].setWeight(2); point[BOARD_SIZE - 1][j + 1].setWeight(2);
			point[BOARD_SIZE - 2][j - 1].setWeight(2); point[BOARD_SIZE - 2][j].setWeight(2); point[BOARD_SIZE - 2][j + 1].setWeight(2);
		}
	}

	// 3. �����ڸ�(������)�� ��
	//���� ��
	if (point[0][0].getCondition() == 0) { point[1][0].setWeight(2); point[0][1].setWeight(2); point[1][1].setWeight(2); } //�浹
	if (point[0][0].getCondition() == 1) { point[1][0].setWeight(-2); point[0][1].setWeight(-2); point[1][1].setWeight(-2); } //�鵹
	//������ ��
	if (point[0][BOARD_SIZE - 1].getCondition() == 0 ) { point[0][BOARD_SIZE-2].setWeight(2); point[1][BOARD_SIZE-2].setWeight(2); point[1][BOARD_SIZE-1].setWeight(2); } //�浹
	if (point[0][BOARD_SIZE - 1].getCondition() == 1) { point[0][BOARD_SIZE - 2].setWeight(-2); point[1][BOARD_SIZE - 2].setWeight(-2); point[1][BOARD_SIZE - 1].setWeight(-2); }//�鵹
	//���� �Ʒ�
	if (point[BOARD_SIZE - 1][0].getCondition() == 0) { point[BOARD_SIZE - 2][0].setWeight(2); point[BOARD_SIZE - 2][1].setWeight(2); point[BOARD_SIZE - 1][1].setWeight(2); } //�浹
	if (point[BOARD_SIZE - 1][0].getCondition() == 1) { point[BOARD_SIZE - 2][0].setWeight(-2); point[BOARD_SIZE - 2][1].setWeight(-2); point[BOARD_SIZE - 1][1].setWeight(-2); } //�鵹
	//������ �Ʒ�
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 0) { point[BOARD_SIZE - 1][BOARD_SIZE - 2].setWeight(2); point[BOARD_SIZE - 2][BOARD_SIZE - 2].setWeight(2); point[BOARD_SIZE - 2][BOARD_SIZE - 1].setWeight(2); } //�浹
	if (point[BOARD_SIZE - 1][BOARD_SIZE - 1].getCondition() == 1) { point[BOARD_SIZE - 1][BOARD_SIZE - 2].setWeight(-2); point[BOARD_SIZE - 2][BOARD_SIZE - 2].setWeight(-2); point[BOARD_SIZE - 2][BOARD_SIZE - 1].setWeight(-2); } //�鵹
}

int GameBoard::getGBdata(Location p) {
	//���ϰ� : ��� ���� ��� �ش� ��ġ�� ����ġ, ���� ���� ��� -500�� ����
	
	int row = p.getRow(); int col = p.getCol();
	if (point[row][col].getCondition() == -1) { //�ش� ��ġ�� ��� �ִ� ��� ����ġ�� ����
		return p.getWeight();
	}
	else { //�ش� ��ġ�� ���� ������ -500�� ����
		return -500;
	}

}


/*
	�����ϴ� �Լ����� ��� ��ġ�� ���� ����ġ�� ����ؼ�
	setGBData�Լ��� ���� ����ġ�� set��
	getGBData������ ����ġ�� ������
*/