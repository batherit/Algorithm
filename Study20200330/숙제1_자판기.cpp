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

int main(void) {
	const int iColaCost = 200;
	const int iCiderCost = 300;

	const int cola = 1;
	const int cider = 2;
	const int exit = 0;

	int iMyMoney;

	while (true) {
		cout << "������ �������� �Է��ϼ���. : ";
		cin >> iMyMoney;
		cout << endl;

		if (0 > iMyMoney) {
			cout << "�����ݾ��� ������ ���� �����ϴ�.";
			continue;
		}
		break;
	}

	int iSelect;
	while (true) {
		cout << "[������ ������ : " << iMyMoney << "��]" << endl;
		cout << "1. �ݶ�(200��), 2. ���̴�(300��), 0. ����" << endl;
		cout << "������ ���Ḧ �Է��ϼ���. : ";
		cin >> iSelect;
		cout << endl;
		system("cls");
		switch (iSelect)
		{
		case cola:
			if (0 > iMyMoney - iColaCost) {
				cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
			}
			else {
				cout << "�ݶ� �����Ͽ����ϴ�." << endl;
				iMyMoney -= iColaCost;
			}
			break;
		case cider:
			if (0 > iMyMoney - iCiderCost) {
				cout << "������ ���������δ� ������ �� �����ϴ�!" << endl;
			}
			else {
				cout << "���̴ٸ� �����Ͽ����ϴ�." << endl;
				iMyMoney -= iCiderCost;
			}
			break;
		case exit:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�!" << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}