// 플레이어 몬스터 공격 HP 싸운다(HP--) 도망간다(HP 그대로 종료) => 둘 중 하나 HP 0이 되면 종료된다. 
#include<iostream>
using namespace std;

int main(void) {
	const int attack = 1;
	const int run = 2;

	const int player = 1;
	const int monster = 0;
	bool turn = player;		// 현재의 턴을 플레이어로 맞춥니다.

	int iPlayerAttackDamage = 0;
	int iPlayerHp = 0;
	int iMonsterAttackDamage = 0;
	int iMonsterHp = 0;

	cout << "플레이어와 몬스터가 서로 싸웁니다!" << endl << endl;

	cout << "값을 차례대로 해주세요." << endl;
	cout << "[플레이어 공격력, 플레이어 HP] :";
	cin >> iPlayerAttackDamage >> iPlayerHp;
	cout << "[몬스터 공격력, 몬스터 HP] :";
	cin >> iMonsterAttackDamage >> iMonsterHp;
	cout << "[최초의 턴(플레이어-1번, 몬스터 - 0번)] :";
	cin >> turn;

START:
	{
		if (player == turn) {
			int iSelected;
			cout << "행동을 하나 선택하세요." << endl;
			cout << "1. 공격한다, 2. 도망간다. => 입력 :";
			cin >> iSelected;

			switch (iSelected)
			{
			case attack:
				iMonsterHp -= iPlayerAttackDamage;
				cout << "[공격]으로 인해 몬스터의 HP가 '" << iMonsterHp << "'가 되었습니다." << endl;
				break;
			case run:
				cout << "[도망]으로 인해 게임이 종료되었습니다." << endl;
				goto END;
				break;
			default:
				break;
			}
			// 몬스터 턴으로 변경
			turn = monster;
		}
		else if (monster == turn) {
			cout << "몬스터가 공격합니다!" << endl;
			iPlayerHp -= iMonsterAttackDamage;
			cout << "[공격]으로 인해 플레이어의 HP가 '" << iPlayerHp << "'가 되었습니다." << endl;
			// player 턴으로 변경
			turn = player;
		}
	}
	cout << endl;
	// 승패 판정
	if (iMonsterHp <= 0 || iPlayerHp <= 0) {
		if (iPlayerHp <= 0) cout << "플레이어가 패배하고 몬스터가 승리하였습니다." << endl;
		else if (iMonsterHp <= 0) cout << "몬스터가 패배하고 플레이어가 승리하였습니다." << endl;
		goto END;
	}

	goto START;
END:
	cout << "게임 종료" << endl;
	return 0;
}