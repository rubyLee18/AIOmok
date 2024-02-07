/* 2018112075 �̰��� */
#ifndef __weight_h
#define __weight_h
#include "header.h"

Location point[BOARD_SIZE][BOARD_SIZE];

/*
	setGBData : ����ġ�� set��
	getGBData :  ����ġ�� ������
	chaksu :  ���� ������Ű�� �̸� �ݿ��� �������� ���� ���
*/

void setGBdata() { //��� ��ġ�� ���� ����ġ ����, ����

	// 1. �����ڸ��� �ƴ� ��
	for (int i = 1; i < BOARD_SIZE; i++) {  //for���� �����鼭 : �ٵ��� ���� ��� ��ġ Ȯ��
		for (int j = 1; j < BOARD_SIZE; j++) {
			//�浹�̸�(0) �ֺ� ����ġ +2
			if (point[i][j].getCondition() == 0) {
				point[i - 1][j - 1].setWeight(2); point[i][j - 1].setWeight(2); point[i + 1][j - 1].setWeight(2);
				point[i - 1][j].setWeight(2); point[i + 1][j].setWeight(2);
				point[i - 1][j + 1].setWeight(2); point[i][j + 1].setWeight(2); point[i + 1][j + 1].setWeight(2);
			}
			//�鵹�̸�(1) �ֺ� ����ġ -2
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
		if (point[i][BOARD_SIZE - 1].getCondition() == 0) { //��
			point[i - 1][BOARD_SIZE - 1].setWeight(2); point[i + 1][BOARD_SIZE - 1].setWeight(2);
			point[i - 1][BOARD_SIZE - 2].setWeight(2); point[i][BOARD_SIZE - 2].setWeight(2); point[i + 1][BOARD_SIZE - 2].setWeight(2);
		}
		if (point[i][BOARD_SIZE - 1].getCondition() == 1) { //��
			point[i - 1][BOARD_SIZE - 1].setWeight(-2); point[i + 1][BOARD_SIZE - 1].setWeight(-2);
			point[i - 1][BOARD_SIZE - 2].setWeight(-2); point[i][BOARD_SIZE - 2].setWeight(-2); point[i + 1][BOARD_SIZE - 2].setWeight(-2);
		}
	}
	//���� ��
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[0][j].getCondition() == 0) { //��
			point[0][j - 1].setWeight(2); point[0][j + 1].setWeight(2);
			point[1][j - 1].setWeight(2); point[1][j].setWeight(2); point[1][j + 1].setWeight(2);
		}
		if (point[0][j].getCondition() == 1) { //��
			point[0][j - 1].setWeight(-2); point[0][j + 1].setWeight(-2);
			point[1][j - 1].setWeight(-2); point[1][j].setWeight(-2); point[1][j + 1].setWeight(-2);
		}
	}
	//�Ʒ��� ��
	for (int j = 1; j < BOARD_SIZE; j++) {
		if (point[BOARD_SIZE - 1][j].getCondition() == 0) { //��
			point[BOARD_SIZE - 1][j - 1].setWeight(2); point[BOARD_SIZE - 1][j + 1].setWeight(2);
			point[BOARD_SIZE - 2][j - 1].setWeight(2); point[BOARD_SIZE - 2][j].setWeight(2); point[BOARD_SIZE - 2][j + 1].setWeight(2);
		}
		if (point[BOARD_SIZE - 1][j].getCondition() == 1) { //��
			point[BOARD_SIZE - 1][j - 1].setWeight(-2); point[BOARD_SIZE - 1][j + 1].setWeight(-2);
			point[BOARD_SIZE - 2][j - 1].setWeight(-2); point[BOARD_SIZE - 2][j].setWeight(-2); point[BOARD_SIZE - 2][j + 1].setWeight(-2);
		}
	}

	// 3. �����ڸ�(������)�� ��
	//���� ��
	if (point[0][0].getCondition() == 0) { point[1][0].setWeight(2); point[0][1].setWeight(2); point[1][1].setWeight(2); } //�浹
	if (point[0][0].getCondition() == 1) { point[1][0].setWeight(-2); point[0][1].setWeight(-2); point[1][1].setWeight(-2); } //�鵹
	//������ ��
	if (point[0][BOARD_SIZE - 1].getCondition() == 0) { point[0][BOARD_SIZE - 2].setWeight(2); point[1][BOARD_SIZE - 2].setWeight(2); point[1][BOARD_SIZE - 1].setWeight(2); } //�浹
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
	else { //�ش� ��ġ�� ���� ������ -500(�ſ� ���� ��)�� ����
		return -500;
	}

}

void chaksu(int x, int y, bool stone) {
	//(x,y) ��ǥ�� ����, stone���� ��� �Ǻ�,  ���ο� ������ ���

	if (stone == true) { //�浹(�����) �����̸�
		point[x][y].set(x, y); //��ǥ ����
		point[x][y].setCondition(0); //�� ��ǥ 0���� �ʱ�ȭ
	}
	else { //�鵹(AI) �����̸�
		point[x][y].set(x, y);//��ǥ ����
		point[x][y].setCondition(1); //�� ��ǥ 1�� �ʱ�ȭ
	}

	cout << " ";
	for (int k = 0; k < BOARD_SIZE; k++) {
		cout << " " << k << " ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i;
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (point[i][j].getCondition() == -1) cout << " + "; //���ڸ� �׸�
			else if (point[i][j].getCondition() == 0) cout << " ��"; //������(�����) ���� �� �浹 �׸�
			else if (point[i][j].getCondition() == 1) cout << " ��"; //��(AI) ���� �� �� �׸�
		}
		cout << endl;
	}


	setGBdata(); // ��� ��ġ�� ���� ����ġ ����
}



#endif // ! __weight_h