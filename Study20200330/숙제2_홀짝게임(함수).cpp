/*숙제 2. 홀짝 게임
난수 1 부터 10까지 중 하나를 뽑는다.
1.메뉴 1.홀수 2. 짝수 3. 종료
2. 사용자가 숫자를 눌러서 난수가 홀수인지 짝수인지 맞추는 게임 만들면 됨.
3. 총 3라운드로 반복문을 사용할 것. 마지막 라운드가 끝나면 총 라운드 승, 패 출력후 끝.
난수는 매번 새로 뽑느다. */

#include<iostream>
#include<ctime>
using namespace std;

const int ODD = 1;
const int EVEN = 2;
const int END = 3;

/* PrintGameRound
=> Input : 남은 게임 횟수
=> Ouput : void*/
void PrintGameRound(int iRemainingRound) {
	cout << "[" << 4 - iRemainingRound << "라운드]" << endl;
}

/* GetComSelect
=> Input : void
=> Output : rand로 뽑은 1~10의 수 중 하나
*/
int GetComSelect(void) {
	int iComSelect = rand() % 10 + 1;
	return iComSelect;
}

/* PrintGameInterface
=> Input : void
=> Output : void
*/
void PrintGameInterface(void) {
	cout << "컴퓨터가 홀 또는 짝을 뽑았습니다." << endl;
	cout << "1. 홀수, 2. 짝수, 3. 종료" << endl;
}

/* GetMySelect
=> Input : void
=> Output : 사용자가 선택한 입력값을 입력받아 그대로 반환합니다. */
int GetMySelect(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

/* PrintIntermediateResult
=> Input : 컴퓨터의 선택
=> Output : void
*/
void PrintComSelect(int iComSelect) {
	if (iComSelect % 2 != 0) {
		cout << "컴퓨터는 홀수인 " << iComSelect << "을/를 뽑았습니다." << endl;
	}
	else {
		cout << "컴퓨터는 짝수인 " << iComSelect << "을/를 뽑았습니다." << endl;
	}
}

/* GetIntermediateResult
=> Input : 플레이어 선택, 컴퓨터의 선택
=> Output : 플레이어가 맞췄으면 true, 아니라면 false
*/
bool GetIntermediateResult(int iMySelect, int iComSelect) {
	if (iMySelect % 2 == iComSelect % 2) return true;
	return false;
}

/* PrintEndCase
=> Input : void
=> Output : void
*/
void PrintEndCase(void) {
	cout << "프로그램을 종료합니다." << endl;
}

/* PrintErrorCase
=> Input : void
=> Output : void
*/
void PrintErrorCase(void) {
	cout << "잘못된 입력입니다!" << endl;
}

/* PrintFinalResult
=> input : 승리 카운트, 패배 카운트
=> output : void
*/
void PrintFinalResult(int iWinCnt, int iDefeatCnt) {
	cout << "총 " << iWinCnt << "승" << ' ' << iDefeatCnt << "패로 ";
	if (iWinCnt > iDefeatCnt) cout << "승리하였습니다.";
	else if (iWinCnt < iDefeatCnt) cout << "패배하였습니다.";
	else cout << "무승부입니다.";
	cout << endl;
}

int main(void) {
	// 난수 생성을 위한 씨드값 전달
	srand((unsigned int)time(nullptr));
	int iGameCnt = 3;

	int iDefeatCnt = 0;
	int iWinCnt = 0;

	int iMySelect = 0;
	int iComSelect = 0;
	while (iGameCnt) {
		system("cls");
		PrintGameRound(iGameCnt);

		iComSelect = GetComSelect();
		PrintGameInterface();

		switch (iMySelect = GetMySelect())
		{
		case ODD: case EVEN:
			PrintComSelect(iComSelect);
			if (GetIntermediateResult(iMySelect, iComSelect)) {
				cout << "맞췄습니다! =>" << ++iWinCnt << "승" << ' ' << iDefeatCnt << "패" << endl;
			}
			else {
				cout << "틀렸습니다! =>" << iWinCnt << "승" << ' ' << ++iDefeatCnt << "패" << endl;
			}
			iGameCnt--;
			break;
		case END:
			PrintEndCase();
			return 0;
		default:
			PrintErrorCase();
			break;
		}
		system("pause");
		cout << endl;

	}

	PrintFinalResult(iWinCnt, iDefeatCnt);

	return 0;
}