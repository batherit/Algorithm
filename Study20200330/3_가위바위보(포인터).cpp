/*숙제 3. 가위 바위 보.
난수를 뽑아낸다 .
0~2, 1~3
메뉴는 가위, 바위, 보, 나가기
사용자가 낸것과 컴퓨터가 낸것 두개 비교해서 이겼는지 졌는지 혹은 비겼는지
매 라운드마다 출력
애도 마찬가지 3라운드
끝나면 승, 무, 패 출력할 것.
매 라운드 마다 낸수는 새로 뽑는다. */

#include<iostream>
#include<ctime>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int FUROSHIKI = 3;
const int END = 4;

const int WIN = 1;
const int DRAW = 0;
const int DEFEAT = -1;
const int NONE = -2;

void PrintGameRound(int iRemainingRound);
void SetComSelect(int* iComSelect);
void PrintGameInterface(void);
void SetMySelect(int* iMySelect);
void PrintEachOtherSelects(int iMySelect, int iComSelect);
void UpdateIntermediateResult(int iMySelect, int iComSelect, int* iWinCnt, int* iDefeatCnt);
void PrintIntermediateResult(int iMySelect, int iComSelect, int iWinCnt, int iDefeatCnt);
void PrintEndCase(void);
void PrintErrorCase(void);
void PrintFinalResult(int iWinCnt, int iDefeatCnt);
void RunRockPaperScissor(void);

int main(void) {
	RunRockPaperScissor();

	return 0;
}




























/*case SCISSORS:
case ROCK:
case FUROSHIKI:
if ((iMySelect % 3 + 1) == iComSelect)	cout << "졌습니다. =>" << iWinCnt << "승 " << ++iDefeatCnt << "패" << endl;
else if (iMySelect == iComSelect)		cout << "무승부입니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
else									cout << "이겼습니다. =>" << ++iWinCnt << "승 " << iDefeatCnt << "패" << endl;
break;*/

/* PrintGameRound
=> Input : 남은 게임 횟수
=> Ouput : void*/
void PrintGameRound(int iRemainingRound) {
	cout << "[" << 4 - iRemainingRound << "라운드]" << endl;
}

/* SetComSelect
=> Input : 컴퓨터 선택 변수의 주소
=> Output : void
*/
void SetComSelect(int* iComSelect) {
	*iComSelect = rand() % 3 + 1;
}

/* PrintGameInterface
=> Input : void
=> Output : void
*/
void PrintGameInterface(void) {
	cout << "컴퓨터가 가위/바위/보 중 하나를 냈습니다." << endl;
	cout << "1. 가위, 2. 바위, 3. 보, 4. 종료" << endl;
}

/* SetMySelect
=> Input : 내 선택 변수의 주소
=> Output : void */
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
}

/* PrintIntermediateResult
=> Input : 플레이어의 선택, 컴퓨터의 선택
=> Output : void
*/
void PrintEachOtherSelects(int iMySelect, int iComSelect) {
	if (SCISSORS <= iMySelect && iMySelect <= FUROSHIKI) {
		// 정상적인 값의 입력이 이루어진 경우, 각자 낸 것을 출력한다.
		if (SCISSORS == iMySelect)			cout << "플레이어는 가위를 냈습니다." << endl;
		else if (ROCK == iMySelect)			cout << "플레이어는 바위를 냈습니다." << endl;
		else if (FUROSHIKI == iMySelect)	cout << "플레이어는 보를 냈습니다." << endl;

		if (SCISSORS == iComSelect)			cout << "컴퓨터는 가위를 냈습니다." << endl;
		else if (ROCK == iComSelect)		cout << "컴퓨터는 바위를 냈습니다." << endl;
		else if (FUROSHIKI == iComSelect)	cout << "컴퓨터는 보를 냈습니다." << endl;
	}
}

/* GetIntermediateResult
=> input : 내 선택 변수, 컴퓨터 선택 변수
=> output : 승패 결과를 나타내는 정수형 값.
*/
int GetIntermediateResult(int iMySelect, int iComSelect) {
	switch (iMySelect)
	{
	case SCISSORS:
		// 가위
		if (SCISSORS == iComSelect)			return DRAW;
		else if (ROCK == iComSelect)		return DEFEAT;
		else if (FUROSHIKI == iComSelect)	return WIN;
		break;
	case ROCK:
		// 바위
		if (SCISSORS == iComSelect)			return WIN;
		else if (ROCK == iComSelect)		return DRAW;
		else if (FUROSHIKI == iComSelect)	return DEFEAT;
		break;
	case FUROSHIKI:
		// 보
		if (SCISSORS == iComSelect)			return DEFEAT;
		else if (ROCK == iComSelect)		return WIN;
		else if (FUROSHIKI == iComSelect)	return DRAW;
		break;
	}
	return NONE;
}

/* UpdateIntermediateResult
=> Input : 플레이어 선택, 컴퓨터의 선택, 승리 카운트, 패배 카운트
=> Output : void
*/
void UpdateIntermediateResult(int iMySelect, int iComSelect, int* iWinCnt, int* iDefeatCnt) {
	int iResult = GetIntermediateResult(iMySelect, iComSelect);
	if (WIN == iResult)			++(*iWinCnt);
	else if (DEFEAT == iResult)	++(*iDefeatCnt);
}

/* PrintIntermediateResult
=> Input : 플레이어 선택, 컴퓨터 선택, 승리 카운트, 패배 카운트
=> Output : void
*/
void PrintIntermediateResult(int iMySelect, int iComSelect, int iWinCnt, int iDefeatCnt) {
	int iResult = GetIntermediateResult(iMySelect, iComSelect);
	if (WIN == iResult)				cout << "이겼습니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
	else if (DEFEAT == iResult)		cout << "졌습니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
	else if (DRAW == iResult)		cout << "무승부입니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
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

void RunRockPaperScissor(void) {
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

		// 컴퓨터가 가위/바위/보 중 하나를 낸다.
		SetComSelect(&iComSelect); // 1~3
		PrintGameInterface();

		// 플레이어가 가위/바위/보 중 하나를 낸다.
		SetMySelect(&iMySelect);
		PrintEachOtherSelects(iMySelect, iComSelect);

		int iResult = 0;
		// 승패 결과를 따진다.
		switch (iMySelect)
		{
		case SCISSORS: case ROCK: case FUROSHIKI:
			UpdateIntermediateResult(iMySelect, iComSelect, &iWinCnt, &iDefeatCnt);
			PrintIntermediateResult(iMySelect, iComSelect, iWinCnt, iDefeatCnt);
			iGameCnt--;
			break;
		case END:
			PrintEndCase();
			return;
		default:
			PrintErrorCase();
			break;
		}
		system("pause");
		cout << endl;
	}

	PrintFinalResult(iWinCnt, iDefeatCnt);
}
