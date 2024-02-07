/* 2018112075 �̰��� */
#include "header.h"
#include "weight.h"
#include "gameboard.h"

int main() {

	GameBoard USER; // ����� ��ü
	GameBoard AI; // AI ��ü
	int x, y; // x,y��ǥ

	//�⺻ �ٵ����� �׸��� ���� : �ٵ��� �ʱ�ȭ
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

	// ��� ��ǥ ���¸� - 1�� �ʱ�ȭ (-1 : �������)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			point[i][j].set(i, j); //x,y��ǥ ����
			point[i][j].setCondition(-1);	 //�� ��ǥ ���� �ʱ�ȭ		
			point[i][j].setWeight(0); //��ǥ ����ġ �ʱ�ȭ
		}
	}

	//�������� �̱� ������ ��� �ݺ�
	while (1) {		

		if (USER.check_5() == true || AI.check_5() == true) {//�������� �̱�� ������ ���������� ������ ����
			break; cout<< endl << "GAME OVER" << endl;
		}

		//	1. ����ڷκ��� �浹�� ��ġ�� �Է¹���

		bool stone = true; 
		cout << "�����(�浹) : ������ ��ġ�� �Է��ϼ���>>";
		cin >> x >> y; //������ x,y��ǥ�� �Է¹���
		chaksu(x, y, true);



		//	2. AI�� ��ġ�� �Ǵ��Ͽ� ���� ���� 

		// => � ��쿡 �ش��� �ȴٸ� �� �Լ� ������ �������� ����� ����. �׸��� 0�� �ƴ� ���� ����
		// => �ƹ� ����� ������ �ش� ���� ���� ��� ����ġ�� �ҷ��ͼ� ����ġ�� ���� ū ��ġ�� ����
		stone = false;	
		if (AI.check_closed_4() == 0 && AI.check_blanked_4() == 0 && AI.check_blanked_3() == 0 && AI.check_opened_3() == 0) {//�ƹ� ����� ������ �ش� ���� ���� ���

			int max = AI.getGBdata(point[0][0]); //����ġ �ִ�
			int weight; //����ġ
			int x, y; //����ġ �ִ밡 �Ǵ� ���� x,y��ǥ

			// ��� ��ġ�� ����ġ�� �ҷ��ͼ� ����
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					weight = AI.getGBdata(point[i][j]);
					if (weight > max) {
						max = weight;
						x = i; y = j;
					}
				}
			}
			//�׸��� ����ġ�� ���� ū ��ġ ����, �ű⿡ ����
			chaksu(x, y, false);
		}
		else {
			int s;
			//s = AI.check_closed_4(); s = AI.check_blanked_4(); s = AI.check_blanked_3(); s = AI.check_opened_3();
		}

		cout << endl;
		//�̰� �ݺ�


	}

	return 0;
}