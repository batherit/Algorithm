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
		cout << "[" << 3 - iGameCnt << "����]" << endl;
		// ��ǻ�Ͱ� ����/����/�� �� �ϳ��� ����.
		iComSelect = rand() % 3 + 1; // 1~3
		cout << "��ǻ�Ͱ� ����/����/�� �� �ϳ��� �½��ϴ�." << endl;
		cout << "1. ����, 2. ����, 3. ��, 4. ����" << endl;

		// �÷��̾ ����/����/�� �� �ϳ��� ����.
		cin >> iMySelect;
		system("cls");

		if (SCISSORS <= iMySelect && iMySelect <= FUROSHIKI) {
			// �������� ���� �Է��� �̷���� ���, ���� �� ���� ����Ѵ�.
			if (SCISSORS == iMySelect)			cout << "�÷��̾�� ������ �½��ϴ�." << endl;
			else if (ROCK == iMySelect)			cout << "�÷��̾�� ������ �½��ϴ�." << endl;
			else if (FUROSHIKI == iMySelect)	cout << "�÷��̾�� ���� �½��ϴ�." << endl;

			if (SCISSORS == iComSelect)			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
			else if (ROCK == iComSelect)		cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
			else if (FUROSHIKI == iComSelect)	cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
		}
		// ���� ����� ������.
		switch (iMySelect)
		{
		case SCISSORS:
		case ROCK:
		case FUROSHIKI:
			if ((iMySelect % 3 + 1) == iComSelect)	cout << "�����ϴ�. =>" << iWinCnt << "�� " << ++iDefeatCnt << "��" << endl;
			else if (iMySelect == iComSelect)		cout << "���º��Դϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			else									cout << "�̰���ϴ�. =>" << ++iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			break;

			//case SCISSORS:
			//	// ����
			//	if (SCISSORS == iComSelect)			cout << "���º��Դϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			//	else if (ROCK == iComSelect)		cout << "�����ϴ�. =>" << iWinCnt << "�� " << ++iDefeatCnt << "��" << endl;
			//	else if (FUROSHIKI == iComSelect)	cout << "�̰���ϴ�. =>" << ++iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			//	break;
			//case ROCK:
			//	// ����
			//	if (SCISSORS == iComSelect)			cout << "�̰���ϴ�. =>" << ++iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			//	else if (ROCK == iComSelect)		cout << "���º��Դϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			//	else if (FUROSHIKI == iComSelect)	cout << "�����ϴ�. =>" << iWinCnt << "�� " << ++iDefeatCnt << "��" << endl;
			//	break;
			//case FUROSHIKI:
			//	// ��
			//	if (SCISSORS == iComSelect)			cout << "�����ϴ�. =>" << iWinCnt << "�� " << ++iDefeatCnt << "��" << endl;
			//	else if (ROCK == iComSelect)		cout << "�̰���ϴ�. =>" << ++iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			//	else if (FUROSHIKI == iComSelect)	cout << "���º��Դϴ�. =>" << iWinCnt << "�� " << iDefeatCnt << "��" << endl;
			//	break;

		case exit:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��ԷµǾ����ϴ�!" << endl;
			break;
		}
		cout << endl;
	}

	cout << "�� " << iWinCnt << "��" << ' ' << iDefeatCnt << "�з� ";
	if (iWinCnt > iDefeatCnt)		cout << "�¸��Ͽ����ϴ�.";
	else if (iWinCnt < iDefeatCnt)	cout << "�й��Ͽ����ϴ�.";
	else cout << "���º��Դϴ�.";

	return 0;
}