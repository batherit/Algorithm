/*���� 2. Ȧ¦ ����
	���� 1 ���� 10���� �� �ϳ��� �̴´�.
	1.�޴� 1.Ȧ�� 2. ¦�� 3. ����
	2. ����ڰ� ���ڸ� ������ ������ Ȧ������ ¦������ ���ߴ� ���� ����� ��.
	3. �� 3����� �ݺ����� ����� ��. ������ ���尡 ������ �� ���� ��, �� ����� ��.
	������ �Ź� ���� �̴���. */

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
		cout << "[" << 3 - iGameCnt << "����]" << endl;
		// ��ǻ�Ͱ� Ȧ �Ǵ� ¦ �� �ϳ��� �̴´�.
		iComSelect = rand() % 10 + 1;
		cout << "��ǻ�Ͱ� Ȧ �Ǵ� ¦�� �̾ҽ��ϴ�." << endl;
		cout << "1. Ȧ��, 2. ¦��, 3. ����" << endl;
		cin >> iMySelect;
		system("cls");

		switch (iMySelect)
		{
		case odd: case even:
			if (iComSelect % 2 != 0) {
				cout << "��ǻ�ʹ� Ȧ���� " << iComSelect << "��/�� �̾ҽ��ϴ�." << endl;
			}
			else {
				cout << "��ǻ�ʹ� ¦���� " << iComSelect << "��/�� �̾ҽ��ϴ�." << endl;
			}

			if (iMySelect % 2 == iComSelect % 2) {
				cout << "������ϴ�! =>" << ++iWinCnt << "��" << ' ' << iDefeatCnt << "��" << endl;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�! =>" << iWinCnt << "��" << ' ' << ++iDefeatCnt << "��" << endl;
			}
			break;
		case exit:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��ԷµǾ����ϴ�." << endl;
			break;
		}
		cout << endl;
	}

	cout << "�� " << iWinCnt << "��" << ' ' << iDefeatCnt << "�з� ";
	if (iWinCnt > iDefeatCnt) cout << "�¸��Ͽ����ϴ�.";
	else if (iWinCnt < iDefeatCnt) cout << "�й��Ͽ����ϴ�.";
	else cout << "���º��Դϴ�.";

	return 0;
}