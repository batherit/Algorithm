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

void SetPlayerAttackDamage(int* iPlayerAttackDamage);
void SetPlayerHp(int* iPlayerHp);
void SetMonsterAttackDamage(int* iMonsterAttackDamage);
void SetMonsterHp(int* iMonsterHp);
void SetTurn(int* iTurn);
void PrintGameInterface(void);
void SetMySelect(int* iMySelect);
void SetMonsterHpAfterPlayerAttack(int* iMonsterHp, int iPlayerAttackDamage);
void SetPlayerHpAfterMonsterAttack(int* iPlayerHp, int iMonsterAttackDamage);
void PrintErrorCase(void);
int GetFinalResult(int iPlayerHp, int iMonsterHp);
void PrintFinalResult(int iResult);
void PrintEndGame(void);
void RunTextRPG(void);

int main(void) {
	RunTextRPG();

	return 0;
}




























/* SetPlayerAttackDamage
=> Input : �÷��̾� ���ݷ� ������ �ּ�
=> Output : void
*/
void SetPlayerAttackDamage(int* iPlayerAttackDamage) {
	int iTempPlayerAttackDamage;

START:
	system("cls");
	cout << "�÷��̾� ���ݷ� �Է� :";
	cin >> iTempPlayerAttackDamage;

	if (0 > iTempPlayerAttackDamage) {
		cout << "���ݷ��� ������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iPlayerAttackDamage = iTempPlayerAttackDamage;
}

/* SetPlayerHp
=> Input : �÷��̾� ü�� ������ �ּ�
=> Output : void
*/
void SetPlayerHp(int* iPlayerHp) {
	int iTempPlayerHp;

START:
	system("cls");
	cout << "�÷��̾� HP �Է� :";
	cin >> iTempPlayerHp;

	if (0 >= iTempPlayerHp) {
		cout << "HP�� 0������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iPlayerHp = iTempPlayerHp;
}

/* SetMonsterAttackDamage
=> Input : ���� ���ݷ� ������ �ּ�
=> Output : void
*/
void SetMonsterAttackDamage(int* iMonsterAttackDamage) {
	int iTempMonsterAttackDamage;

START:
	system("cls");
	cout << "���� ���ݷ� �Է� :";
	cin >> iTempMonsterAttackDamage;

	if (0 > iTempMonsterAttackDamage) {
		cout << "���ݷ��� ������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iMonsterAttackDamage = iTempMonsterAttackDamage;
}

/* SetMonsterHp
=> Input : ���� ü�� ������ �ּ�
=> Output : void
*/
void SetMonsterHp(int* iMonsterHp) {
	int iTempMonsterHp;

START:
	system("cls");
	cout << "���� HP �Է� :";
	cin >> iTempMonsterHp;

	if (0 >= iTempMonsterHp) {
		cout << "HP�� 0������ ���� �����ϴ�." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iMonsterHp = iTempMonsterHp;
}

/* SetTurn
=> Input : �� ������ �ּ�
=> Output : void
*/
void SetTurn(int* iTurn) {
	int iTempTurn;

START:
	system("cls");
	cout << "������ ��(�÷��̾�-1��, ���� - 0��) �Է� :";
	cin >> iTempTurn;

	if (PLAYER != iTempTurn && MONSTER != iTempTurn) {
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iTurn = iTempTurn;
}

/* PrintGameInterface
=> Input : void
=> Output : void
*/
void PrintGameInterface(void) {
	cout << "�ൿ�� �ϳ� �����ϼ���." << endl;
	cout << "1. �����Ѵ�, 2. ��������. => �Է� :";
}

/* SetMySelect
=> Input : �� ���� ������ �ּ�
=> Output : void*/
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
}

/* SetMonsterHpAfterPlayerAttack
=> input : ���� Hp, �÷��̾� ���ݷ�
=> Output : �÷��̾����� ���ݴ��� ���� ���� Hp
*/
void SetMonsterHpAfterPlayerAttack(int* iMonsterHp, int iPlayerAttackDamage) {
	*iMonsterHp -= iPlayerAttackDamage;

	if (*iMonsterHp < 0)	*iMonsterHp = 0;
}

/* SetPlayerHpAfterMonsterAttack
=> input : �÷��̾� Hp, ���� ���ݷ�
=> Output : �������� ���ݴ��� ���� �÷��̾� Hp
*/
void SetPlayerHpAfterMonsterAttack(int* iPlayerHp, int iMonsterAttackDamage) {
	*iPlayerHp -= iMonsterAttackDamage;

	if (*iPlayerHp < 0)		*iPlayerHp = 0;
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

/* RunTextRPG
=> input : void
=> output : void
*/
void RunTextRPG(void) {
	int iTurn = PLAYER;

	int iPlayerAttackDamage = 0;
	int iPlayerHp = 0;
	int iMonsterAttackDamage = 0;
	int iMonsterHp = 0;

	int iMySelect;

	SetPlayerAttackDamage(&iPlayerAttackDamage);
	SetPlayerHp(&iPlayerHp);
	SetMonsterAttackDamage(&iMonsterAttackDamage);
	SetMonsterHp(&iMonsterHp);
	SetTurn(&iTurn);

	cout << "�÷��̾�� ���Ͱ� ���� �ο�ϴ�!" << endl << endl;
START:
	{
		if (PLAYER == iTurn) {
			PrintGameInterface();
			SetMySelect(&iMySelect);
			switch (iMySelect)
			{
			case ATTACK:
				SetMonsterHpAfterPlayerAttack(&iMonsterHp, iPlayerAttackDamage);
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
			SetPlayerHpAfterMonsterAttack(&iPlayerHp, iMonsterAttackDamage);
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
}