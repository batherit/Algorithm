/*
���� 1.
�ݺ����� ���� �ݺ����� ���� ���Ǳ�.
1.������ �Է� �ޱ�
2. ���� �������� ���� �ܾ� ǥ��
3. �޴����
1.�ݶ�, 2.���̴�.3., , , 0, ��ȯ
���� ���ý� �ش� ��ǰ ���� �Ϸ� ����� ���� �ܾ� ����
��, �ش� �ܾ׺��� ���� ��ǰ ���� ũ�� ���� �Ұ�.
���� �޴� ���� ���� ��µ� ������ system�Լ��� �����ش�.
��ȯ�� ������ ���� �Ž������� �� �Դϴ� ����� ����.*/

#include<iostream>
using namespace std;

const int COLA = 1;
const int CIDER = 2;
const int END = 0;

/* InputMyMoney
=> Input : void
=> Ouput : �ùٸ� �����ݾ��� �ԷµǾ��� ���, �̸� ��ȯ�մϴ�.*/
int InputMyMoney(void) {
	int iMoney;

	while (true) {
		system("cls");
		cout << "������ �������� �Է��ϼ���. : ";
		cin >> iMoney;

		if (0 > iMoney) {
			cout << "�����ݾ��� ������ ���� �����ϴ�." << endl;
			system("pause");
			continue;
		}
		break;
	}
	system("cls");

	return iMoney;
}

/* PrintMachineInterface
=> Input : ������ �����ݾ�
=> Output : void*/
void PrintMachineInterface(int iMyMoney) {
	system("cls");
	cout << "[������ ������ : " << iMyMoney << "��]" << endl;
	cout << "1. �ݶ�(200��), 2. ���̴�(300��), 0. ��ȯ" << endl;
	cout << "������ ���Ḧ �Է��ϼ���. : ";
}

/* GetMenu
=> Input : void
=> Output : ����ڰ� ������ �޴����� �Է¹޾� �״�� ��ȯ�մϴ�. */
int GetMenu(void) {
	int iSelect;
	cin >> iSelect;
	cout << endl;
	return iSelect;
}

/* GetMoneyAfterColaSelection
=> Input : ������ �����ݾ�
=> Output : �ݶ� ������ ���� �Ž�����*/
int GetMoneyAfterColaSelection(int iCurrentMoney) {
	// �ݶ� ������ 200������ å��
	const int iColaCost = 200;

	if (0 > iCurrentMoney - iColaCost) {
		cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
		return iCurrentMoney;
	}
	else {
		cout << "�ݶ� �����Ͽ����ϴ�." << endl;
		return iCurrentMoney -= iColaCost;
	}
}

/* GetMoneyAfterCiderSelection
=> Input : ������ �����ݾ�
=> Output : ���̴ٸ� ������ ���� �Ž�����*/
int GetMoneyAfterCiderSelection(int iCurrentMoney) {
	// ���̴� ������ 300������ å��
	const int iCiderCost = 300;

	if (0 > iCurrentMoney - iCiderCost) {
		cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
		return iCurrentMoney;
	}
	else {
		cout << "���̴ٸ� �����Ͽ����ϴ�." << endl;
		return iCurrentMoney -= iCiderCost;
	}
}

/* PrintEndCase
=> Input : ������ �����ݾ�
=> Output : void
*/
void PrintEndCase(int iMyMoney) {
	cout << "��ȯ�� �ݾ��� " << iMyMoney << "���Դϴ�." << endl;
	cout << "���α׷��� �����մϴ�." << endl;
}

/* PrintErrorCase
=> Input : void
=> Output : void
*/
void PrintErrorCase(void) {
	cout << "�߸��� �Է��Դϴ�!" << endl;
}

int main(void) {
	int iMyMoney = InputMyMoney();
	while (true) {
		PrintMachineInterface(iMyMoney);
		switch (GetMenu())
		{
		case COLA:	iMyMoney = GetMoneyAfterColaSelection(iMyMoney);
			break;
		case CIDER:	iMyMoney = GetMoneyAfterCiderSelection(iMyMoney);
			break;
		case END:	PrintEndCase(iMyMoney);
			return 0;
		default:	PrintErrorCase();
			break;
		}
		system("pause");
		cout << endl;
	}

	return 0;
}