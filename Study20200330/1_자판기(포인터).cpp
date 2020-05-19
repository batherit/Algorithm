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

const int COLA_COST = 200;
const int CIDER_COST = 300;


void SetMyMoney(int* iMyMoney);
void PrintMachineInterface(int iMyMoney);
void SetMySelect(int* iMySelect);
void SetMoneyAfterColaSelection(int* iCurrentMoney);
void SetMoneyAfterCiderSelection(int* iCurrentMoney);
void SetMyMoneyAfterPurchase(int* iMyMoney, int iCost);
void PrintEndCase(int iMyMoney);
void PrintErrorCase(void);
void RunVendingMachine(void);

int main(void) {
	RunVendingMachine();

	return 0;
}




























/* SetMyMoney
=> Input : �� �����ݾ� ���� �ּ�
=> Ouput : void*/
void SetMyMoney(int* iMyMoney) {
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

	// �ùٸ� �����ݾ��� ���� iMyMoney�� �����Ѵ�.
	*iMyMoney = iMoney;
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

/* SetMySelect
=> Input : ���� ���� ������ �ּ�
=> Output : void */
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
	cout << endl;
}

/* SetMoneyAfterColaSelection
=> Input : ������ �����ݾ�
=> Output : void*/
void SetMoneyAfterColaSelection(int* iCurrentMoney) {
	// �ݶ� ������ 200������ å��
	const int iColaCost = 200;

	if (0 > *iCurrentMoney - iColaCost) {
		cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
	}
	else {
		cout << "�ݶ� �����Ͽ����ϴ�." << endl;

		// �Ž������� �����Ѵ�.
		*iCurrentMoney -= iColaCost;
	}
}

/* SetMoneyAfterCiderSelection
=> Input : ������ �����ݾ�
=> Output : void*/
void SetMoneyAfterCiderSelection(int* iCurrentMoney) {
	// ���̴� ������ 300������ å��
	const int iCiderCost = 300;

	if (0 > *iCurrentMoney - iCiderCost) {
		cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
	}
	else {
		cout << "���̴ٸ� �����Ͽ����ϴ�." << endl;

		// �Ž������� �����Ѵ�.
		*iCurrentMoney -= iCiderCost;
	}
}

void SetMyMoneyAfterPurchase(int* iMyMoney, int iCost) {
	if (0 > *iMyMoney - iCost) {
		cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
	}
	else {
		cout << "���Ḧ �����Ͽ����ϴ�!" << endl;

		// �Ž������� �����Ѵ�.
		*iMyMoney -= iCost;
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

/* RunVendingMachine
=> Input : void
=> Output : void
*/
void RunVendingMachine(void) {
	int iMyMoney;
	// ������
	SetMyMoney(&iMyMoney);

	int iMySelect;
	while (true) {
		PrintMachineInterface(iMyMoney);
		SetMySelect(&iMySelect);
		switch (iMySelect)
		{
		case COLA:
			// ������
			SetMyMoneyAfterPurchase(&iMyMoney, COLA_COST);
			break;
		case CIDER:
			// ������
			SetMyMoneyAfterPurchase(&iMyMoney, CIDER_COST);
			break;
		case END:	PrintEndCase(iMyMoney);
			return;
		default:	PrintErrorCase();
			break;
		}
		system("pause");
		cout << endl;
	}
}