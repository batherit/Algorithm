#include<iostream>
using namespace std;

// 구조체 =
struct tagPlayer {
	char szName[50];
	char szJob[50];
	int iAtt;
	int iDef;
	int iHp;
	int iMaxHp;
};

int main(void) {
	tagPlayer tPlayer;

	return 0;
}

// 빙고 5*5 1줄 빙고, 5줄이면 게임 끝
// 학생 3명분 성적표 1. 입력, 2. 전체 출력 3. 검색 4. 종료 (구조체x, 구조체o 버젼)