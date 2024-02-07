/* 2018112075 �̰��� */
#ifndef __header_h
#define __header_h
#include <iostream>
using namespace std;

#define BOARD_SIZE 9
//extern bool stone; //true:�浹(�����), false:�鵹(AI)

/*�ٵ��� ���� ��ġ�� ��� ���� �ޱ� ���� ������ Ŭ����*/
class Location {
private:
	int row = 0; //�� : i
	int col = 0; //�� : j	
	int condition = -1; //���� : �������(-1), �浹(0), �鵹(1)
	int weight = 0; //�ش� ��ġ�� ����ġ, ����Ʈ ���� 0
public:
	Location() { this->row = 0; this->col = 0; }
	Location(int col, int row) { this->col = col; this->row = row; }
	void set(int col, int row) { this->col = col; this->row = row; }
	void setCondition(int condition) { this->condition = condition; }
	int getCondition() { return condition; }
	int getRow() { return row; }
	int getCol() { return col; }
	int getWeight() { return weight; }
	void setWeight(int weight) { this->weight += weight; } //������ ����ġ�� �Է¹��� ����ġ��ŭ ������
};

/*�ٵ����� �����ϱ� ���� ������ Ŭ����*/ 
class GameBoard {
public:
	int check_closed_4(); //���� 4�� Ȯ�� : 1. x�ܡܡܡ�x��, 2. �ۡܡܡܡ�x��, 3. x�ܡܡܡܡ۲� ....
	int check_blanked_4(); //�� 4�� Ȯ�� : 1. �ܡ�x�ܡܲ�, 2. �ܡܡ�x�ܲ�, 3. ��x�ܡܡܲ� ....
	int  check_blanked_3(); //�� 3�� Ȯ�� : 1. ��x�ܡܲ�, 2. �ܡ�x�ܲ� ....
	int  check_opened_3(); //���� 3�� Ȯ�� :  1. x�ܡܡ�x��, 2. �ۡܡܡ�x��, 3. x�ܡܡܡ۲� .... 
	bool check_5(); //�¸����� Ȯ�� & �¸� ���� ���(����ڰ� �¸��ߴ��� AI�� �¸��ߴ��� ���)
	int getGBdata(Location p); //�ش� ��ġ�� ����ġ �Ǵ� ���� ���� �ҷ�����
};


#endif // !__header_h