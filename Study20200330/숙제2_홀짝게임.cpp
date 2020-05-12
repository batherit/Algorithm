/*숙제 2. 홀짝 게임
	난수 1 부터 10까지 중 하나를 뽑는다.
	1.메뉴 1.홀수 2. 짝수 3. 종료
	2. 사용자가 숫자를 눌러서 난수가 홀수인지 짝수인지 맞추는 게임 만들면 됨.
	3. 총 3라운드로 반복문을 사용할 것. 마지막 라운드가 끝나면 총 라운드 승, 패 출력후 끝.
	난수는 매번 새로 뽑느다. */

#include<iostream>
#include<ctime>
using namespace std;

int main(void) {
	srand((unsigned int)time(nullptr));
	const int odd = 1;
	const int even = 2;
	const int exit = 3;

	int iDefeatCnt = 0;
	int iWinCnt = 0;

	int iGameCnt = 3;
	int iMySelect = 0;
	int iComSelect = 0;
	while (iGameCnt--) {
		cout << "[" << 3 - iGameCnt << "라운드]" << endl;
		// 컴퓨터가 홀 또는 짝 중 하나를 뽑는다.
		iComSelect = rand() % 10 + 1;
		cout << "컴퓨터가 홀 또는 짝을 뽑았습니다." << endl;
		cout << "1. 홀수, 2. 짝수, 3. 종료" << endl;
		cin >> iMySelect;
		system("cls");

		switch (iMySelect)
		{
		case odd: case even:
			if (iComSelect % 2 != 0) {
				cout << "컴퓨터는 홀수인 " << iComSelect << "을/를 뽑았습니다." << endl;
			}
			else {
				cout << "컴퓨터는 짝수인 " << iComSelect << "을/를 뽑았습니다." << endl;
			}

			if (iMySelect % 2 == iComSelect % 2) {
				cout << "맞췄습니다! =>" << ++iWinCnt << "승" << ' ' << iDefeatCnt << "패" << endl;
			}
			else {
				cout << "틀렸습니다! =>" << iWinCnt << "승" << ' ' << ++iDefeatCnt << "패" << endl;
			}
			break;
		case exit:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못입력되었습니다." << endl;
			break;
		}
		cout << endl;
	}

	cout << "총 " << iWinCnt << "승" << ' ' << iDefeatCnt << "패로 ";
	if (iWinCnt > iDefeatCnt) cout << "승리하였습니다.";
	else if (iWinCnt < iDefeatCnt) cout << "패배하였습니다.";
	else cout << "무승부입니다.";

	return 0;
}