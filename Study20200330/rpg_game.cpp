// �÷��̾� ���� ���� HP �ο��(HP--) ��������(HP �״�� ����) => �� �� �ϳ� HP 0�� �Ǹ� ����ȴ�. 
#include<iostream>
using namespace std;

int main(void) {
	const int attack = 1;
	const int run = 2;

	const int player = 1;
	const int monster = 0;
	bool turn = player;		// ������ ���� �÷��̾�� ����ϴ�.

	int iPlayerAttackDamage = 0;
	int iPlayerHp = 0;
	int iMonsterAttackDamage = 0;
	int iMonsterHp = 0;

	cout << "�÷��̾�� ���Ͱ� ���� �ο�ϴ�!" << endl << endl;

	cout << "���� ���ʴ�� ���ּ���." << endl;
	cout << "[�÷��̾� ���ݷ�, �÷��̾� HP] :";
	cin >> iPlayerAttackDamage >> iPlayerHp;
	cout << "[���� ���ݷ�, ���� HP] :";
	cin >> iMonsterAttackDamage >> iMonsterHp;
	cout << "[������ ��(�÷��̾�-1��, ���� - 0��)] :";
	cin >> turn;

START:
	{
		if (player == turn) {
			int iSelected;
			cout << "�ൿ�� �ϳ� �����ϼ���." << endl;
			cout << "1. �����Ѵ�, 2. ��������. => �Է� :";
			cin >> iSelected;

			switch (iSelected)
			{
			case attack:
				iMonsterHp -= iPlayerAttackDamage;
				cout << "[����]���� ���� ������ HP�� '" << iMonsterHp << "'�� �Ǿ����ϴ�." << endl;
				break;
			case run:
				cout << "[����]���� ���� ������ ����Ǿ����ϴ�." << endl;
				goto END;
				break;
			default:
				break;
			}
			// ���� ������ ����
			turn = monster;
		}
		else if (monster == turn) {
			cout << "���Ͱ� �����մϴ�!" << endl;
			iPlayerHp -= iMonsterAttackDamage;
			cout << "[����]���� ���� �÷��̾��� HP�� '" << iPlayerHp << "'�� �Ǿ����ϴ�." << endl;
			// player ������ ����
			turn = player;
		}
	}
	cout << endl;
	// ���� ����
	if (iMonsterHp <= 0 || iPlayerHp <= 0) {
		if (iPlayerHp <= 0) cout << "�÷��̾ �й��ϰ� ���Ͱ� �¸��Ͽ����ϴ�." << endl;
		else if (iMonsterHp <= 0) cout << "���Ͱ� �й��ϰ� �÷��̾ �¸��Ͽ����ϴ�." << endl;
		goto END;
	}

	goto START;
END:
	cout << "���� ����" << endl;
	return 0;
}