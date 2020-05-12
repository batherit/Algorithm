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

int main(void) {
	srand((unsigned int)time(nullptr));
	const int SCISSORS = 1;
	const int ROCK = 2;
	const int FUROSHIKI = 3;
	const int exit = 4;

	int iDefeatCnt = 0;
	int iWinCnt = 0;

	int iGameCnt = 3;
	int iMySelect = 0;
	int iComSelect = 0;

	while (iGameCnt--) {
		cout << "[" << 3 - iGameCnt << "라운드]" << endl;
		// 컴퓨터가 가위/바위/보 중 하나를 낸다.
		iComSelect = rand() % 3 + 1; // 1~3
		cout << "컴퓨터가 가위/바위/보 중 하나를 냈습니다." << endl;
		cout << "1. 가위, 2. 바위, 3. 보, 4. 종료" << endl;

		// 플레이어가 가위/바위/보 중 하나를 낸다.
		cin >> iMySelect;
		system("cls");

		if (SCISSORS <= iMySelect && iMySelect <= FUROSHIKI) {
			// 정상적인 값의 입력이 이루어진 경우, 각자 낸 것을 출력한다.
			if (SCISSORS == iMySelect)			cout << "플레이어는 가위를 냈습니다." << endl;
			else if (ROCK == iMySelect)			cout << "플레이어는 바위를 냈습니다." << endl;
			else if (FUROSHIKI == iMySelect)	cout << "플레이어는 보를 냈습니다." << endl;

			if (SCISSORS == iComSelect)			cout << "컴퓨터는 가위를 냈습니다." << endl;
			else if (ROCK == iComSelect)		cout << "컴퓨터는 바위를 냈습니다." << endl;
			else if (FUROSHIKI == iComSelect)	cout << "컴퓨터는 보를 냈습니다." << endl;
		}
		// 승패 결과를 따진다.
		switch (iMySelect)
		{
		case SCISSORS:
		case ROCK:
		case FUROSHIKI:
			if ((iMySelect % 3 + 1) == iComSelect)	cout << "졌습니다. =>" << iWinCnt << "승 " << ++iDefeatCnt << "패" << endl;
			else if (iMySelect == iComSelect)		cout << "무승부입니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			else									cout << "이겼습니다. =>" << ++iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			break;

			//case SCISSORS:
			//	// 가위
			//	if (SCISSORS == iComSelect)			cout << "무승부입니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			//	else if (ROCK == iComSelect)		cout << "졌습니다. =>" << iWinCnt << "승 " << ++iDefeatCnt << "패" << endl;
			//	else if (FUROSHIKI == iComSelect)	cout << "이겼습니다. =>" << ++iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			//	break;
			//case ROCK:
			//	// 바위
			//	if (SCISSORS == iComSelect)			cout << "이겼습니다. =>" << ++iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			//	else if (ROCK == iComSelect)		cout << "무승부입니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			//	else if (FUROSHIKI == iComSelect)	cout << "졌습니다. =>" << iWinCnt << "승 " << ++iDefeatCnt << "패" << endl;
			//	break;
			//case FUROSHIKI:
			//	// 보
			//	if (SCISSORS == iComSelect)			cout << "졌습니다. =>" << iWinCnt << "승 " << ++iDefeatCnt << "패" << endl;
			//	else if (ROCK == iComSelect)		cout << "이겼습니다. =>" << ++iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			//	else if (FUROSHIKI == iComSelect)	cout << "무승부입니다. =>" << iWinCnt << "승 " << iDefeatCnt << "패" << endl;
			//	break;

		case exit:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못입력되었습니다!" << endl;
			break;
		}
		cout << endl;
	}

	cout << "총 " << iWinCnt << "승" << ' ' << iDefeatCnt << "패로 ";
	if (iWinCnt > iDefeatCnt)		cout << "승리하였습니다.";
	else if (iWinCnt < iDefeatCnt)	cout << "패배하였습니다.";
	else cout << "무승부입니다.";

	return 0;
}