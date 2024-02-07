/* 2018112075 이가현 */
#ifndef __header_h
#define __header_h
#include <iostream>
using namespace std;

#define BOARD_SIZE 9
//extern bool stone; //true:흑돌(사용자), false:백돌(AI)

/*바둑판 상의 위치를 행과 열로 받기 위해 정의한 클래스*/
class Location {
private:
	int row = 0; //행 : i
	int col = 0; //열 : j	
	int condition = -1; //상태 : 비어있음(-1), 흑돌(0), 백돌(1)
	int weight = 0; //해당 위치의 가중치, 디폴트 값은 0
public:
	Location() { this->row = 0; this->col = 0; }
	Location(int col, int row) { this->col = col; this->row = row; }
	void set(int col, int row) { this->col = col; this->row = row; }
	void setCondition(int condition) { this->condition = condition; }
	int getCondition() { return condition; }
	int getRow() { return row; }
	int getCol() { return col; }
	int getWeight() { return weight; }
	void setWeight(int weight) { this->weight += weight; } //현재의 가중치에 입력받은 가중치만큼 더해줌
};

/*바둑판을 관리하기 위해 정의한 클래스*/ 
class GameBoard {
public:
	int check_closed_4(); //닫힌 4목 확인 : 1. x●●●●x꼴, 2. ○●●●●x꼴, 3. x●●●●○꼴 ....
	int check_blanked_4(); //띈 4목 확인 : 1. ●●x●●꼴, 2. ●●●x●꼴, 3. ●x●●●꼴 ....
	int  check_blanked_3(); //띈 3목 확인 : 1. ●x●●꼴, 2. ●●x●꼴 ....
	int  check_opened_3(); //열린 3목 확인 :  1. x●●●x꼴, 2. ○●●●x꼴, 3. x●●●○꼴 .... 
	bool check_5(); //승리조건 확인 & 승리 여부 출력(사용자가 승리했는지 AI가 승리했는지 출력)
	int getGBdata(Location p); //해당 위치의 가중치 또는 착수 여부 불러오기
};


#endif // !__header_h