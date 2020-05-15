// �÷��̾� ���� ���� HP �ο��(HP--) ��������(HP �״�� ����) => �� �� �ϳ� HP 0�� �Ǹ� ����ȴ�. 
#include<iostream>
using namespace std;

const int ATTACK = 1;
const int RUN = 2;

const int PLAYER = 1;
const int MONSTER = 0;

const int WIN = 1;
const int DEFEAT = -1;
const int NONE = 0;

/* InputPlayerAttackDamage
=> Input : void
=> Output : void
*/
int InputPlayerAttackDamage(void) {
	int iPlayerAttackDamage;

START:
	system("cls");
	cout << "�÷��̾� ���ݷ� �Է� :";
	cin >> iPlayerAttackDamage;

	if (0 > iPlayerAttackDamage) {
		cout << "���ݷ��� ������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	return iPlayerAttackDamage;
}

/* InputPlayerHp
=> Input : void
=> Output : void
*/
int InputPlayerHp(void) {
	int iPlayerHp;

START:
	system("cls");
	cout << "�÷��̾� HP �Է� :";
	cin >> iPlayerHp;

	if (0 >= iPlayerHp) {
		cout << "HP�� 0������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	return iPlayerHp;
}

/* InputMonsterAttackDamage
=> Input : void
=> Output : void
*/
int InputMonsterAttackDamage(void) {
	int iMonsterAttackDamage;

START:
	system("cls");
	cout << "���� ���ݷ� �Է� :";
	cin >> iMonsterAttackDamage;

	if (0 > iMonsterAttackDamage) {
		cout << "���ݷ��� ������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	return iMonsterAttackDamage;
}

/* InputMonsterHp
=> Input : void
=> Output : void
*/
int InputMonsterHp(void) {
	int iMonsterHp;

START:
	system("cls");
	cout << "���� HP �Է� :";
	cin >> iMonsterHp;

	if (0 >= iMonsterHp) {
		cout << "HP�� 0������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	return iMonsterHp;
}

/* InputTurn
=> Input : void
=> Output : void
*/
int InputTurn(void) {
	int iTurn;

START:
	system("cls");
	cout << "������ ��(�÷��̾�-1��, ���� - 0��) �Է� :";
	cin >> iTurn;

	if (PLAYER != iTurn && MONSTER != iTurn) {
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	return iTurn;
}

/* PrintGameInterface
=> Input : void
=> Output : void
*/
void PrintGameInterface(void) {
	cout << "�ൿ�� �ϳ� �����ϼ���." << endl;
	cout << "1. �����Ѵ�, 2. ��������. => �Է� :";
}

/* GetMySelect
=> Input : void
=> Output : ����ڰ� �Է��� ���� �״�� ��ȯ�Ѵ�.*/
int GetMySelect(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

/* GetMonsterHpAfterPlayerAttack
=> input : ���� Hp, �÷��̾� ���ݷ�
=> Output : �÷��̾����� ���ݴ��� ���� ���� Hp
*/
int GetMonsterHpAfterPlayerAttack(int iMonsterHp, int iPlayerAttackDamage) {
	iMonsterHp -= iPlayerAttackDamage;

	if (iMonsterHp >= 0) return iMonsterHp;
	return 0;
}

/* GetPlayerHpAfterMonsterAttack
=> input : �÷��̾� Hp, ���� ���ݷ�
=> Output : �������� ���ݴ��� ���� �÷��̾� Hp
*/
int GetPlayerHpAfterMonsterAttack(int iPlayerHp, int iMonsterAttackDamage) {
	iPlayerHp -= iMonsterAttackDamage;

	if (iPlayerHp >= 0) return iPlayerHp;
	return 0;
}

/* PrintErrorCase
=> Input : void
=> Output : void
*/
void PrintErrorCase(void) {
	cout << "�߸��� �Է��Դϴ�!" << endl;
}

/* GetFinalResult
=> input : �÷��̾� HP, ���� HP
=> output : void
*/
int GetFinalResult(int iPlayerHp, int iMonsterHp) {
	if (iPlayerHp <= 0)			return DEFEAT;
	else if (iMonsterHp <= 0)	return WIN;
	return NONE;
}

/* PrintFinalResult
=> input : ���а�� (WIN, DEFEAT, NONE)
=> output : void
*/
void PrintFinalResult(int iResult) {
	if (WIN == iResult)			cout << "���Ͱ� �й��ϰ� �÷��̾ �¸��Ͽ����ϴ�." << endl;
	else if (DEFEAT == iResult)	cout << "�÷��̾ �й��ϰ� ���Ͱ� �¸��Ͽ����ϴ�." << endl;
}

/* PrintEndGame
=> Input : void
=> Output : void
*/
void PrintEndGame(void) {
	cout << "������ �����մϴ�." << endl;
}

int main(void) {
	int iTurn = PLAYER;

	int iPlayerAttackDamage = 0;
	int iPlayerHp = 0;
	int iMonsterAttackDamage = 0;
	int iMonsterHp = 0;

	iPlayerAttackDamage = InputPlayerAttackDamage();
	iPlayerHp = InputPlayerHp();
	iMonsterAttackDamage = InputMonsterAttackDamage();
	iMonsterHp = InputMonsterHp();
	iTurn = InputTurn();

	cout << "�÷��̾�� ���Ͱ� ���� �ο�ϴ�!" << endl << endl;
START:
	{
		if (PLAYER == iTurn) {
			PrintGameInterface();

			switch (GetMySelect())
			{
			case ATTACK:
				iMonsterHp = GetMonsterHpAfterPlayerAttack(iMonsterHp, iPlayerAttackDamage);
				cout << "[����]���� ���� ������ HP�� '" << iMonsterHp << "'��/�� �Ǿ����ϴ�." << endl;
				break;
			case RUN:
				cout << "[����]���� ���� ������ ����Ǿ����ϴ�." << endl;
				goto END;
				break;
			default:
				PrintErrorCase();
				goto START;
			}
			// ���� ������ ����
			iTurn = MONSTER;
		}
		else if (MONSTER == iTurn) {
			cout << "���Ͱ� �����մϴ�!" << endl;
			iPlayerHp = GetPlayerHpAfterMonsterAttack(iPlayerHp, iMonsterAttackDamage);
			cout << "[����]���� ���� �÷��̾��� HP�� '" << iPlayerHp << "'��/�� �Ǿ����ϴ�." << endl;
			// player ������ ����
			iTurn = PLAYER;
		}
	}
	cout << endl;
	// ���� ����
	int iResult = GetFinalResult(iPlayerHp, iMonsterHp);
	if (NONE != iResult) {
		PrintFinalResult(iResult);
		goto END;
	} // ���� ����� �ȳ��Դ�(NONE)�̸� ��� �����Ѵ�.

	goto START;
END:
	PrintEndGame();
	return 0;
}