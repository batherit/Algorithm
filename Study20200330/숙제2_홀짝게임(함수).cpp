/*���� 2. Ȧ¦ ����
���� 1 ���� 10���� �� �ϳ��� �̴´�.
1.�޴� 1.Ȧ�� 2. ¦�� 3. ����
2. ����ڰ� ���ڸ� ������ ������ Ȧ������ ¦������ ���ߴ� ���� ����� ��.
3. �� 3����� �ݺ����� ����� ��. ������ ���尡 ������ �� ���� ��, �� ����� ��.
������ �Ź� ���� �̴���. */

#include<iostream>
#include<ctime>
using namespace std;

const int ODD = 1;
const int EVEN = 2;
const int END = 3;

/* PrintGameRound
=> Input : ���� ���� Ƚ��
=> Ouput : void*/
void PrintGameRound(int iRemainingRound) {
	cout << "[" << 4 - iRemainingRound << "����]" << endl;
}

/* GetComSelect
=> Input : void
=> Output : rand�� ���� 1~10�� �� �� �ϳ�
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
	cout << "��ǻ�Ͱ� Ȧ �Ǵ� ¦�� �̾ҽ��ϴ�." << endl;
	cout << "1. Ȧ��, 2. ¦��, 3. ����" << endl;
}

/* GetMySelect
=> Input : void
=> Output : ����ڰ� ������ �Է°��� �Է¹޾� �״�� ��ȯ�մϴ�. */
int GetMySelect(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

/* PrintIntermediateResult
=> Input : ��ǻ���� ����
=> Output : void
*/
void PrintComSelect(int iComSelect) {
	if (iComSelect % 2 != 0) {
		cout << "��ǻ�ʹ� Ȧ���� " << iComSelect << "��/�� �̾ҽ��ϴ�." << endl;
	}
	else {
		cout << "��ǻ�ʹ� ¦���� " << iComSelect << "��/�� �̾ҽ��ϴ�." << endl;
	}
}

/* GetIntermediateResult
=> Input : �÷��̾� ����, ��ǻ���� ����
=> Output : �÷��̾ �������� true, �ƴ϶�� false
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
	cout << "���α׷��� �����մϴ�." << endl;
}

/* PrintErrorCase
=> Input : void
=> Output : void
*/
void PrintErrorCase(void) {
	cout << "�߸��� �Է��Դϴ�!" << endl;
}

/* PrintFinalResult
=> input : �¸� ī��Ʈ, �й� ī��Ʈ
=> output : void
*/
void PrintFinalResult(int iWinCnt, int iDefeatCnt) {
	cout << "�� " << iWinCnt << "��" << ' ' << iDefeatCnt << "�з� ";
	if (iWinCnt > iDefeatCnt) cout << "�¸��Ͽ����ϴ�.";
	else if (iWinCnt < iDefeatCnt) cout << "�й��Ͽ����ϴ�.";
	else cout << "���º��Դϴ�.";
	cout << endl;
}

int main(void) {
	// ���� ������ ���� ���尪 ����
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
				cout << "������ϴ�! =>" << ++iWinCnt << "��" << ' ' << iDefeatCnt << "��" << endl;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! =>" << iWinCnt << "��" << ' ' << ++iDefeatCnt << "��" << endl;
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