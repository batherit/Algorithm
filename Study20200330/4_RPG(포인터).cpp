// 플레이어 몬스터 공격 HP 싸운다(HP--) 도망간다(HP 그대로 종료) => 둘 중 하나 HP 0이 되면 종료된다. 
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
=> Input : 플레이어 공격력 변수의 주소
=> Output : void
*/
void SetPlayerAttackDamage(int* iPlayerAttackDamage) {
	int iTempPlayerAttackDamage;

START:
	system("cls");
	cout << "플레이어 공격력 입력 :";
	cin >> iTempPlayerAttackDamage;

	if (0 > iTempPlayerAttackDamage) {
		cout << "공격력이 음수일 수는 없습니다." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iPlayerAttackDamage = iTempPlayerAttackDamage;
}

/* SetPlayerHp
=> Input : 플레이어 체력 변수의 주소
=> Output : void
*/
void SetPlayerHp(int* iPlayerHp) {
	int iTempPlayerHp;

START:
	system("cls");
	cout << "플레이어 HP 입력 :";
	cin >> iTempPlayerHp;

	if (0 >= iTempPlayerHp) {
		cout << "HP가 0이하일 수는 없습니다." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iPlayerHp = iTempPlayerHp;
}

/* SetMonsterAttackDamage
=> Input : 몬스터 공격력 변수의 주소
=> Output : void
*/
void SetMonsterAttackDamage(int* iMonsterAttackDamage) {
	int iTempMonsterAttackDamage;

START:
	system("cls");
	cout << "몬스터 공격력 입력 :";
	cin >> iTempMonsterAttackDamage;

	if (0 > iTempMonsterAttackDamage) {
		cout << "공격력이 음수일 수는 없습니다." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iMonsterAttackDamage = iTempMonsterAttackDamage;
}

/* SetMonsterHp
=> Input : 몬스터 체력 변수의 주소
=> Output : void
*/
void SetMonsterHp(int* iMonsterHp) {
	int iTempMonsterHp;

START:
	system("cls");
	cout << "몬스터 HP 입력 :";
	cin >> iTempMonsterHp;

	if (0 >= iTempMonsterHp) {
		cout << "HP가 0이하일 수는 없습니다." << endl;
		system("pause");
		goto START;
	}
	system("cls");

	*iMonsterHp = iTempMonsterHp;
}

/* SetTurn
=> Input : 턴 변수의 주소
=> Output : void
*/
void SetTurn(int* iTurn) {
	int iTempTurn;

START:
	system("cls");
	cout << "최초의 턴(플레이어-1번, 몬스터 - 0번) 입력 :";
	cin >> iTempTurn;

	if (PLAYER != iTempTurn && MONSTER != iTempTurn) {
		cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
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
	cout << "행동을 하나 선택하세요." << endl;
	cout << "1. 공격한다, 2. 도망간다. => 입력 :";
}

/* SetMySelect
=> Input : 내 선택 변수의 주소
=> Output : void*/
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
}

/* SetMonsterHpAfterPlayerAttack
=> input : 몬스터 Hp, 플레이어 공격력
=> Output : 플레이어한테 공격당한 이후 몬스터 Hp
*/
void SetMonsterHpAfterPlayerAttack(int* iMonsterHp, int iPlayerAttackDamage) {
	*iMonsterHp -= iPlayerAttackDamage;

	if (*iMonsterHp < 0)	*iMonsterHp = 0;
}

/* SetPlayerHpAfterMonsterAttack
=> input : 플레이어 Hp, 몬스터 공격력
=> Output : 몬스터한테 공격당한 이후 플레이어 Hp
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
	cout << "잘못된 입력입니다!" << endl;
}

/* GetFinalResult
=> input : 플레이어 HP, 몬스터 HP
=> output : void
*/
int GetFinalResult(int iPlayerHp, int iMonsterHp) {
	if (iPlayerHp <= 0)			return DEFEAT;
	else if (iMonsterHp <= 0)	return WIN;
	return NONE;
}

/* PrintFinalResult
=> input : 승패결과 (WIN, DEFEAT, NONE)
=> output : void
*/
void PrintFinalResult(int iResult) {
	if (WIN == iResult)			cout << "몬스터가 패배하고 플레이어가 승리하였습니다." << endl;
	else if (DEFEAT == iResult)	cout << "플레이어가 패배하고 몬스터가 승리하였습니다." << endl;
}

/* PrintEndGame
=> Input : void
=> Output : void
*/
void PrintEndGame(void) {
	cout << "게임을 종료합니다." << endl;
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

	cout << "플레이어와 몬스터가 서로 싸웁니다!" << endl << endl;
START:
	{
		if (PLAYER == iTurn) {
			PrintGameInterface();
			SetMySelect(&iMySelect);
			switch (iMySelect)
			{
			case ATTACK:
				SetMonsterHpAfterPlayerAttack(&iMonsterHp, iPlayerAttackDamage);
				cout << "[공격]으로 인해 몬스터의 HP가 '" << iMonsterHp << "'이/가 되었습니다." << endl;
				break;
			case RUN:
				cout << "[도망]으로 인해 게임이 종료되었습니다." << endl;
				goto END;
				break;
			default:
				PrintErrorCase();
				goto START;
			}
			// 몬스터 턴으로 변경
			iTurn = MONSTER;
		}
		else if (MONSTER == iTurn) {
			cout << "몬스터가 공격합니다!" << endl;
			SetPlayerHpAfterMonsterAttack(&iPlayerHp, iMonsterAttackDamage);
			cout << "[공격]으로 인해 플레이어의 HP가 '" << iPlayerHp << "'이/가 되었습니다." << endl;
			// player 턴으로 변경
			iTurn = PLAYER;
		}
	}
	cout << endl;
	// 승패 판정
	int iResult = GetFinalResult(iPlayerHp, iMonsterHp);
	if (NONE != iResult) {
		PrintFinalResult(iResult);
		goto END;
	} // 아직 결과가 안나왔다(NONE)이면 계속 진행한다.

	goto START;
END:
	PrintEndGame();
}