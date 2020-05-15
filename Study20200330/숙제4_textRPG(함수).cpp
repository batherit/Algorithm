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

/* InputPlayerAttackDamage
=> Input : void
=> Output : void
*/
int InputPlayerAttackDamage(void) {
	int iPlayerAttackDamage;

START:
	system("cls");
	cout << "플레이어 공격력 입력 :";
	cin >> iPlayerAttackDamage;

	if (0 > iPlayerAttackDamage) {
		cout << "공격력이 음수일 수는 없습니다." << endl;
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
	cout << "플레이어 HP 입력 :";
	cin >> iPlayerHp;

	if (0 >= iPlayerHp) {
		cout << "HP가 0이하일 수는 없습니다." << endl;
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
	cout << "몬스터 공격력 입력 :";
	cin >> iMonsterAttackDamage;

	if (0 > iMonsterAttackDamage) {
		cout << "공격력이 음수일 수는 없습니다." << endl;
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
	cout << "몬스터 HP 입력 :";
	cin >> iMonsterHp;

	if (0 >= iMonsterHp) {
		cout << "HP가 0이하일 수는 없습니다." << endl;
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
	cout << "최초의 턴(플레이어-1번, 몬스터 - 0번) 입력 :";
	cin >> iTurn;

	if (PLAYER != iTurn && MONSTER != iTurn) {
		cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
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
	cout << "행동을 하나 선택하세요." << endl;
	cout << "1. 공격한다, 2. 도망간다. => 입력 :";
}

/* GetMySelect
=> Input : void
=> Output : 사용자가 입력한 값을 그대로 반환한다.*/
int GetMySelect(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

/* GetMonsterHpAfterPlayerAttack
=> input : 몬스터 Hp, 플레이어 공격력
=> Output : 플레이어한테 공격당한 이후 몬스터 Hp
*/
int GetMonsterHpAfterPlayerAttack(int iMonsterHp, int iPlayerAttackDamage) {
	iMonsterHp -= iPlayerAttackDamage;

	if (iMonsterHp >= 0) return iMonsterHp;
	return 0;
}

/* GetPlayerHpAfterMonsterAttack
=> input : 플레이어 Hp, 몬스터 공격력
=> Output : 몬스터한테 공격당한 이후 플레이어 Hp
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

	cout << "플레이어와 몬스터가 서로 싸웁니다!" << endl << endl;
START:
	{
		if (PLAYER == iTurn) {
			PrintGameInterface();

			switch (GetMySelect())
			{
			case ATTACK:
				iMonsterHp = GetMonsterHpAfterPlayerAttack(iMonsterHp, iPlayerAttackDamage);
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
			iPlayerHp = GetPlayerHpAfterMonsterAttack(iPlayerHp, iMonsterAttackDamage);
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
	return 0;
}