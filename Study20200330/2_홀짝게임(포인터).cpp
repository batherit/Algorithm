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

void PrintGameRound(int iRemainingRound);
void SetComSelect(int* iComSelect);
void PrintGameInterface(void);
void SetMySelect(int* iMySelect);
void PrintComSelect(int iComSelect);
bool GetIntermediateResult(int iMySelect, int iComSelect);
void UpdateIntermediateResult(int iMySelect, int iComSelect, int* iWinCnt, int* iDefeatCnt);
void PrintIntermediateResult(int iMySelect, int iComSelect, int iWinCnt, int iDefeatCnt);
void PrintEndCase(void);
void PrintErrorCase(void);
void PrintFinalResult(int iWinCnt, int iDefeatCnt);
void RunSippingGame(void);

int main(void) {
	RunSippingGame();

	return 0;
}




























/* PrintGameRound
=> Input : ���� ���� Ƚ��
=> Ouput : void*/
void PrintGameRound(int iRemainingRound) {
	cout << "[" << 4 - iRemainingRound << "����]" << endl;
}

/* SetComSelect
=> Input : ��ǻ�� ���� ������ �ּ�
=> Output : void
*/
void SetComSelect(int* iComSelect) {
	*iComSelect = rand() % 10 + 1;
}

/* PrintGameInterface
=> Input : void
=> Output : void
*/
void PrintGameInterface(void) {
	cout << "��ǻ�Ͱ� Ȧ �Ǵ� ¦�� �̾ҽ��ϴ�." << endl;
	cout << "1. Ȧ��, 2. ¦��, 3. ����" << endl;
}

/* SetMySelect
=> Input : void
=> Output : void */
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
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
=> Input : �� ���� ����, �� ��ǻ�� ����
=> Output : �÷��̾ �̱�� true, ���� false�� ��ȯ
*/
bool GetIntermediateResult(int iMySelect, int iComSelect) {
	if (iMySelect % 2 == iComSelect % 2) return true;
	return false;
}

/* UpdateIntermediateResult
=> Input : �÷��̾� ����, ��ǻ���� ����, �¸� ī��Ʈ, �й� ī��Ʈ
=> Output : void
*/
void UpdateIntermediateResult(int iMySelect, int iComSelect, int* iWinCnt, int* iDefeatCnt) {
	int iResult = GetIntermediateResult(iMySelect, iComSelect);
	if (true == iResult)			++(*iWinCnt);
	else if (false == iResult)	++(*iDefeatCnt);
}

/* PrintIntermediateResult
=> Input : �÷��̾� ����, ��ǻ���� ����, �¸� ī��Ʈ, �й� ī��Ʈ
=> Output : void
*/
void PrintIntermediateResult(int iMySelect, int iComSelect, int iWinCnt, int iDefeatCnt) {
	int iResult = GetIntermediateResult(iMySelect, iComSelect);
	if (true == iResult)		cout << "������ϴ�! =>";
	else if (false == iResult)	cout << "Ʋ�Ƚ��ϴ�! =>";
	cout << iWinCnt << "��" << ' ' << iDefeatCnt << "��" << endl;
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

/* RunSippingGame
=> input : void
=> output : void
*/
void RunSippingGame(void) {
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

		// ������
		SetComSelect(&iComSelect);
		PrintGameInterface();

		// ������
		SetMySelect(&iMySelect);

		switch (iMySelect)
		{
		case ODD: case EVEN:
			PrintComSelect(iComSelect);
			// ������
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