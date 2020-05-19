/*���� 3. ���� ���� ��.
������ �̾Ƴ��� .
0~2, 1~3
�޴��� ����, ����, ��, ������
����ڰ� ���Ͱ� ��ǻ�Ͱ� ���� �ΰ� ���ؼ� �̰���� ������ Ȥ�� ������
�� ���帶�� ���
�ֵ� �������� 3����
������ ��, ��, �� ����� ��.
�� ���� ���� ������ ���� �̴´�. */

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
if ((iMySelect % 3 + 1) == iComSelect)	cout << "�����ϴ�. =>" << iWinCnt << "�� " << ++iDefeatCnt << "��" << endl;
else if (iMySelect == iComSelect)		cout << "���º��Դϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
else									cout << "�̰���ϴ�. =>" << ++iWinCnt << "�� " << iDefeatCnt << "��" << endl;
break;*/

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
	*iComSelect = rand() % 3 + 1;
}

/* PrintGameInterface
=> Input : void
=> Output : void
*/
void PrintGameInterface(void) {
	cout << "��ǻ�Ͱ� ����/����/�� �� �ϳ��� �½��ϴ�." << endl;
	cout << "1. ����, 2. ����, 3. ��, 4. ����" << endl;
}

/* SetMySelect
=> Input : �� ���� ������ �ּ�
=> Output : void */
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
}

/* PrintIntermediateResult
=> Input : �÷��̾��� ����, ��ǻ���� ����
=> Output : void
*/
void PrintEachOtherSelects(int iMySelect, int iComSelect) {
	if (SCISSORS <= iMySelect && iMySelect <= FUROSHIKI) {
		// �������� ���� �Է��� �̷���� ���, ���� �� ���� ����Ѵ�.
		if (SCISSORS == iMySelect)			cout << "�÷��̾�� ������ �½��ϴ�." << endl;
		else if (ROCK == iMySelect)			cout << "�÷��̾�� ������ �½��ϴ�." << endl;
		else if (FUROSHIKI == iMySelect)	cout << "�÷��̾�� ���� �½��ϴ�." << endl;

		if (SCISSORS == iComSelect)			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
		else if (ROCK == iComSelect)		cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
		else if (FUROSHIKI == iComSelect)	cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
	}
}

/* GetIntermediateResult
=> input : �� ���� ����, ��ǻ�� ���� ����
=> output : ���� ����� ��Ÿ���� ������ ��.
*/
int GetIntermediateResult(int iMySelect, int iComSelect) {
	switch (iMySelect)
	{
	case SCISSORS:
		// ����
		if (SCISSORS == iComSelect)			return DRAW;
		else if (ROCK == iComSelect)		return DEFEAT;
		else if (FUROSHIKI == iComSelect)	return WIN;
		break;
	case ROCK:
		// ����
		if (SCISSORS == iComSelect)			return WIN;
		else if (ROCK == iComSelect)		return DRAW;
		else if (FUROSHIKI == iComSelect)	return DEFEAT;
		break;
	case FUROSHIKI:
		// ��
		if (SCISSORS == iComSelect)			return DEFEAT;
		else if (ROCK == iComSelect)		return WIN;
		else if (FUROSHIKI == iComSelect)	return DRAW;
		break;
	}
	return NONE;
}

/* UpdateIntermediateResult
=> Input : �÷��̾� ����, ��ǻ���� ����, �¸� ī��Ʈ, �й� ī��Ʈ
=> Output : void
*/
void UpdateIntermediateResult(int iMySelect, int iComSelect, int* iWinCnt, int* iDefeatCnt) {
	int iResult = GetIntermediateResult(iMySelect, iComSelect);
	if (WIN == iResult)			++(*iWinCnt);
	else if (DEFEAT == iResult)	++(*iDefeatCnt);
}

/* PrintIntermediateResult
=> Input : �÷��̾� ����, ��ǻ�� ����, �¸� ī��Ʈ, �й� ī��Ʈ
=> Output : void
*/
void PrintIntermediateResult(int iMySelect, int iComSelect, int iWinCnt, int iDefeatCnt) {
	int iResult = GetIntermediateResult(iMySelect, iComSelect);
	if (WIN == iResult)				cout << "�̰���ϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
	else if (DEFEAT == iResult)		cout << "�����ϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
	else if (DRAW == iResult)		cout << "���º��Դϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
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

void RunRockPaperScissor(void) {
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

		// ��ǻ�Ͱ� ����/����/�� �� �ϳ��� ����.
		SetComSelect(&iComSelect); // 1~3
		PrintGameInterface();

		// �÷��̾ ����/����/�� �� �ϳ��� ����.
		SetMySelect(&iMySelect);
		PrintEachOtherSelects(iMySelect, iComSelect);

		int iResult = 0;
		// ���� ����� ������.
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
