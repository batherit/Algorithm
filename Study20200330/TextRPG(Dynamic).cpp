#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

const int ciNameSize = 32;
const int ciMonsterSize = 5;
const int ciBattleStartSec = 3;
const int ciAddAmount = 5;
const int ciMinPropertyValue = 0;
const int ciMaxPropertyValue = 100;

// 키에 대응하는 값은 1부터 시작
enum E_CLASS			{ CLASS_WARRIOR = 1, CLASS_WIZARD, CLASS_THIEF, CLASS_EOF };
enum E_BEHAVIOR			{ BEHAVIOR_BATTLE = 1, BEHAVIOR_RUN, BEHAVIOR_EOF };
enum E_DIFFICULTY		{ DIF_LOW, DIF_MIDDLE, DIF_HIGH, DIF_EOF };
enum E_MENU				{ MENU_LOW = 1, MENU_MIDDLE, MENU_HIGH, MENU_EXIT, MENU_EOF };

// 플레이어 속성값은 E_CLASS에 종속적
const int ciPlayerHP[CLASS_EOF] = { -1, 40, 30, 20 };
const int ciPlayerAtk[CLASS_EOF] = { -1, 30, 45, 20 };
const int ciPlayerDef[CLASS_EOF] = { -1, 15, 10, 5 };
const int ciPlayerLck[CLASS_EOF] = { -1, 5 , 5, 35 };

// 클래스 이름값은 E_CLASS에 종속
const char ccClassName[CLASS_EOF][ciNameSize] = { "NULL", "전사", "마법사", "도적" };

// 몬스터 속성값은 E_DIFFICULTY 값에 종속
const int ciMonsterNum[DIF_EOF] = { 3, 4, 3 };
const char ccMonsterName[DIF_EOF][ciMonsterSize][ciNameSize] = {
	{ "아기돼지", "모기", "사슴" }, 
	{ "다큰돼지", "흡혈모기", "드라큘라", "코뿔소" },
	{ "근육돼지", "짱쎈 코끼리", "대왕" }
}; 
const int ciMonsterMaxHp[DIF_EOF] = { 30, 100, 200 };
const int ciMonsterMinHp[DIF_EOF] = { 10, 50, 120 };
const int ciMonsterMaxAtk[DIF_EOF] = { 15, 30, 80 };
const int ciMonsterMinAtk[DIF_EOF] = { 5, 10, 50 };
const int ciMonsterMaxDef[DIF_EOF] = { 5, 30, 80 };
const int ciMonsterMinDef[DIF_EOF] = { 2, 10, 50 };
const int ciMonsterMaxLck[DIF_EOF] = { 5, 15, 30 };
const int ciMonsterMinLck[DIF_EOF] = { 1, 5, 10 };

typedef struct _player {
	char szName[ciNameSize];
	E_CLASS eClass;
	int iLevel;
	int iHp;
	int iMaxHp;
	int iAtk;
	int iDef;
	int iLck;
	double dExp;
}Player;

typedef struct _monster {
	char szName[ciNameSize];
	int iHp;
	int iAtk;
	int iDef;
	int iLck;
}Monster;


void ErrorAssertion(const char szErrorString[]);
void SystemWarning(const char szWarningString[]);
void PrintTitle(void);
bool _IsNaturalNumber(int iNum);
void _SetNaturalNumber(const char szNumberName[], int* iValueToSave);
void _SetClass(E_CLASS* pClass);
void SetPlayerInfo(Player* _pPlayer);
Player* GetPlayerInfo(void);
void DeletePlayerInfo(Player** _ppPlayer);
void PrintPlayerInfo(const Player* _pPlayer);
int GetNumberMinBetweenMax(int _iMin, int _iMax);
void SetMonsterInfo(Monster* _pMonster, E_DIFFICULTY _eDifficulty);
Monster* GetMonsterInfo(E_DIFFICULTY _eDifficulty);
void DeleteMonsterInfo(Monster** _ppMonster);
void PrintMonsterInfo(const Monster* _pMonster);
void PrintMenuInterface(void);
int GetSelectMenuIndex(void);
void PrintBehaviorInterface(void);
int GetSelectBehaviorIndex(void);
bool _CheckAttackeEvasion(int iLck);
void _Attack(Player* pTo, Monster* pFrom);
void _Attack(Monster* pTo, Player* pFrom);
bool _IsPlayerDied(const Player* _pPlayer);
bool _CheckHP(const Player* _pPlayer, const Monster* _pMonster);
void _Lerp(int* _iValue, int _iMin, int _iMax);
void _ProcessBattleResult(Player* _pPlayer, Monster* _pMonster);
void IncreasePlayerExp(Player* _pPlayer, int iExpToAdd);
void EnterBattleStage(Player* _pPlayer, E_DIFFICULTY _eDifficulty);
void PrintExitCase(void);
void RunTextRpg(void);


int main(void) {
	RunTextRpg();

	return 0;
}










void ErrorAssertion(const char szErrorString[]) {
	cout << "[ERROR] : " << szErrorString << endl;
	system("pause");
	system("exit");
}

void SystemWarning(const char szWarningString[]) {
	cout << "[WARNING] : " << szWarningString << endl;
	system("pause");
}

void PrintTitle(void) {
	cout << "\t\t======================================================" << endl;
	cout << "\t\t=                                                    =" << endl;
	cout << "\t\t=                     TextRPG                        =" << endl;
	cout << "\t\t=                                                    =" << endl;
	cout << "\t\t======================================================" << endl;
	cout << endl;
	cout << "\t\t\t\tby shim jung hwan (2020~)" << endl << endl << endl << endl;
	system("pause");
}

bool _IsNaturalNumber(int iNum) {
	return iNum > 0;
}

void _SetNaturalNumber(const char szNumberName[], int* iValueToSave) {
	while (true) {
		system("cls");
		cout << '[' << szNumberName << "] 입력 :";
		cin >> *iValueToSave;

		if (!_IsNaturalNumber(*iValueToSave)) {
			SystemWarning("이 값은 0이하가 될 수 없습니다!");
		}
		else break;
	}
}

void _SetClass(E_CLASS* pClass) {
	int iInput;
	while (true) {
		system("cls");
		cout << "어떤 직업을 가지겠습니까? (1 - 전사, 2 - 마법사, 3 - 도적) :";
		cin >> iInput;
		if (CLASS_WARRIOR <= iInput && iInput < CLASS_EOF) {
			//strcpy_s(_szClassName, ciNameSize, ccClassName[iInput]);
			*pClass = (E_CLASS)iInput;
			break;
		}
		else {
			SystemWarning("잘못된 입력입니다!");
		}
	}
}

void SetPlayerInfo(Player* _pPlayer) {
	while (true) {
		system("cls");
		cout << "플레이어 이름을 입력하세요. :";
		cin >> _pPlayer->szName;
		break;
	}

	/*_SetNaturalNumber("플레이어 HP", &_pPlayer->iMaxHp);
	_pPlayer->iHp = _pPlayer->iMaxHp;
	_SetNaturalNumber("플레이어 공격력", &_pPlayer->iAtk);
	_SetNaturalNumber("플레이어 방어력", &_pPlayer->iDef);*/
	_SetClass(&_pPlayer->eClass);
	_pPlayer->iMaxHp = ciPlayerHP[_pPlayer->eClass];
	_pPlayer->iHp = ciPlayerHP[_pPlayer->eClass];
	_pPlayer->iAtk = ciPlayerAtk[_pPlayer->eClass];
	_pPlayer->iDef = ciPlayerDef[_pPlayer->eClass];
	_pPlayer->iLck = ciPlayerLck[_pPlayer->eClass];
	_pPlayer->iLevel = 1;
	_pPlayer->dExp = 0.0;
}

Player* GetPlayerInfo(void) {
	Player* pPlayer = new Player;
	while (true) {
		system("cls");
		cout << "플레이어 이름을 입력하세요. :";
		cin >> pPlayer->szName;
		break;
	}

	/*_SetNaturalNumber("플레이어 HP", &_pPlayer->iMaxHp);
	_pPlayer->iHp = _pPlayer->iMaxHp;
	_SetNaturalNumber("플레이어 공격력", &_pPlayer->iAtk);
	_SetNaturalNumber("플레이어 방어력", &_pPlayer->iDef);*/
	_SetClass(&pPlayer->eClass);
	pPlayer->iMaxHp = ciPlayerHP[pPlayer->eClass];
	pPlayer->iHp = ciPlayerHP[pPlayer->eClass];
	pPlayer->iAtk = ciPlayerAtk[pPlayer->eClass];
	pPlayer->iDef = ciPlayerDef[pPlayer->eClass];
	pPlayer->iLck = ciPlayerLck[pPlayer->eClass];
	pPlayer->iLevel = 1;
	pPlayer->dExp = 0.0;

	return pPlayer;
}

void DeletePlayerInfo(Player** _ppPlayer) {
	if (*_ppPlayer) {
		delete *_ppPlayer;
		*_ppPlayer = nullptr;
	}
}

void PrintPlayerInfo(const Player* _pPlayer) {
	cout << "-----[플레이어 정보]-----" << endl;
	cout << "  레벨   : " << _pPlayer->iLevel << '(' << _pPlayer->dExp << "%)" << endl;
	cout << "  직업   : " << ccClassName[_pPlayer->eClass] << endl;
	cout << "  이름   : " << _pPlayer->szName << endl;
	cout << endl;
	cout << "  HP     : " << _pPlayer->iHp << endl;
	cout << "  공격력 : " << _pPlayer->iAtk << endl;
	cout << "  방어력 : " << _pPlayer->iDef << endl;
	cout << "  행운   : " << _pPlayer->iLck << endl;
}

int GetNumberMinBetweenMax(int _iMin, int _iMax) {
	if (_iMin > _iMax) {
		ErrorAssertion("최솟값이 최댓값보다 클 수 없습니다!");
	}

	return rand() % (_iMax - _iMin + 1) + _iMin;
}

void SetMonsterInfo(Monster* _pMonster, E_DIFFICULTY _eDifficulty) {
	strcpy_s(_pMonster->szName, ciNameSize, ccMonsterName[_eDifficulty][rand() % ciMonsterNum[_eDifficulty]]);
	_pMonster->iHp = GetNumberMinBetweenMax(ciMonsterMinHp[_eDifficulty], ciMonsterMaxHp[_eDifficulty]);
	_pMonster->iAtk = GetNumberMinBetweenMax(ciMonsterMinAtk[_eDifficulty], ciMonsterMaxAtk[_eDifficulty]);
	_pMonster->iDef = GetNumberMinBetweenMax(ciMonsterMinDef[_eDifficulty], ciMonsterMaxDef[_eDifficulty]);
	_pMonster->iLck = GetNumberMinBetweenMax(ciMonsterMinLck[_eDifficulty], ciMonsterMaxLck[_eDifficulty]);
}

Monster* GetMonsterInfo(E_DIFFICULTY _eDifficulty) {
	Monster* pMonster = new Monster;

	strcpy_s(pMonster->szName, ciNameSize, ccMonsterName[_eDifficulty][rand() % ciMonsterNum[_eDifficulty]]);
	pMonster->iHp = GetNumberMinBetweenMax(ciMonsterMinHp[_eDifficulty], ciMonsterMaxHp[_eDifficulty]);
	pMonster->iAtk = GetNumberMinBetweenMax(ciMonsterMinAtk[_eDifficulty], ciMonsterMaxAtk[_eDifficulty]);
	pMonster->iDef = GetNumberMinBetweenMax(ciMonsterMinDef[_eDifficulty], ciMonsterMaxDef[_eDifficulty]);
	pMonster->iLck = GetNumberMinBetweenMax(ciMonsterMinLck[_eDifficulty], ciMonsterMaxLck[_eDifficulty]);

	return pMonster;
}

void DeleteMonsterInfo(Monster** _ppMonster) {
	if (*_ppMonster) {
		delete *_ppMonster;
		*_ppMonster = nullptr;
	}
}

void PrintMonsterInfo(const Monster* _pMonster) {
	cout << "-----[몬스터 정보]-----" << endl;
	cout << "  이름   : " << _pMonster->szName << endl;
	cout << endl;
	cout << "  HP     : " << _pMonster->iHp << endl;
	cout << "  공격력 : " << _pMonster->iAtk << endl;
	cout << "  방어력 : " << _pMonster->iDef << endl;
	cout << "  행운   : " << _pMonster->iLck << endl;
}

void PrintMenuInterface(void) {
	cout << "1. 초급, 2. 중급, 3. 고급, 4. 나가기" << endl;
	cout << "입력 : ";
}

int GetSelectMenuIndex(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

void PrintBehaviorInterface(void) {
	cout << "1. 공격하기, 2. 도망가기" << endl;
	cout << "입력 : ";
}

int GetSelectBehaviorIndex(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

bool _CheckAttackeEvasion(int iLck) {
	return iLck >= rand() % 100;
}

void _Attack(Player* pTo, Monster* pFrom) {
	if (_CheckAttackeEvasion(pFrom->iLck)) {
		cout <<  pFrom->szName << "은/는 " << ccClassName[pTo->eClass] << ' ' << pTo->szName << "의 공격을 피했습니다!" << endl;
	}
	else {
		int iDamage = pTo->iAtk - pFrom->iDef;
		if (0 > iDamage) {
			iDamage = 0;
		}

		pFrom->iHp -= iDamage;
		if (0 > pFrom->iHp) {
			pFrom->iHp = 0;
		}
		cout << ccClassName[pTo->eClass] << ' ' << pTo->szName << "은/는 " << pFrom->szName << "에게 " << iDamage << "의 피해를 입혔습니다!" << endl;
	}
}

void _Attack(Monster* pTo, Player* pFrom) {
	if (_CheckAttackeEvasion(pFrom->iLck)) {
		cout << pFrom->szName << "은/는 " << pTo->szName << "의 공격을 피했습니다!" << endl;
	}
	else {
		int iDamage = pTo->iAtk - pFrom->iDef;
		if (0 > iDamage) {
			iDamage = 0;
		}

		pFrom->iHp -= iDamage;
		if (0 > pFrom->iHp) {
			pFrom->iHp = 0;
		}
		cout << pTo->szName << "은/는 " << ccClassName[pFrom->eClass] << ' ' << pFrom->szName << "에게 " << iDamage << "의 피해를 입혔습니다!" << endl;
	}
	
}

bool _IsPlayerDied(const Player* _pPlayer) {
	return 0 >= _pPlayer->iHp;
}

bool _IsMonsterDied(const Monster* _pMonster) {
	return 0 >= _pMonster->iHp;
}

bool _CheckHP(const Player* _pPlayer, const Monster* _pMonster) {
	return (_pPlayer->iHp > 0 && _pMonster->iHp > 0);
}

void _Lerp(int* _iValue, int _iMin, int _iMax) {
	if (*_iValue < _iMin)		*_iValue = _iMin;
	else if (*_iValue > _iMax)	*_iValue = _iMax;
}

void _ProcessBattleResult(Player* _pPlayer, Monster* _pMonster) {
	system("cls");
	PrintPlayerInfo(_pPlayer);
	cout << endl;
	PrintMonsterInfo(_pMonster);
	cout << endl;

	if (_IsPlayerDied(_pPlayer)) {
		cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "은/는 쓰러졌습니다!" << endl;
		system("pause");
		// HP를 원상태로 복귀시키고 종료.
		_pPlayer->iHp = _pPlayer->iMaxHp;
	}
	else {
		cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "은/는 이겼습니다!" << endl;
		// 경험치를 증가시킨다.
		IncreasePlayerExp(_pPlayer, double((_pMonster->iAtk + _pMonster->iDef + _pMonster->iLck)) / _pPlayer->iLevel);
		
		system("pause");
	}
}

void IncreasePlayerExp(Player* _pPlayer, int _iExpToAdd) {
	_pPlayer->dExp += _iExpToAdd;
	int iAddAmount = int(_pPlayer->dExp) / 100;
	if (iAddAmount != 0) {
		// 레벨이 올랐다면 속성값들을 증가시킨다.
		_Lerp(&(_pPlayer->iLevel += iAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_Lerp(&(_pPlayer->iMaxHp += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_pPlayer->iHp = _pPlayer->iMaxHp;
		_Lerp(&(_pPlayer->iAtk += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_Lerp(&(_pPlayer->iDef += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_Lerp(&(_pPlayer->iLck += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_pPlayer->dExp -= iAddAmount * 100;
		cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "은/는 레벨 '" << _pPlayer->iLevel << "'이/가 되었습니다!" << endl;
	}
}

void EnterBattleStage(Player* _pPlayer, E_DIFFICULTY _eDifficulty) {
	//Monster stMonster;
	//SetMonsterInfo(&stMonster, _eDifficulty);
	Monster* pMonster;
	pMonster = GetMonsterInfo(_eDifficulty);

	system("cls");
	cout << "전투가 시작됩니다!" << endl;
	cout << "당신은 [" << pMonster->szName << "]을/를 조우하였습니다!!" << endl;
	system("pause");

	while (_CheckHP(_pPlayer, pMonster)) {
		system("cls");
		// 플레이어 및 몬스터 정보 출력
		PrintPlayerInfo(_pPlayer);
		cout << endl;
		PrintMonsterInfo(pMonster);
		cout << endl;
		PrintBehaviorInterface();
		switch (GetSelectBehaviorIndex())
		{
		case BEHAVIOR_BATTLE:
			if (!_IsPlayerDied(_pPlayer)) {
				// 플레이어가 몬스터를 공격한다.
				_Attack(_pPlayer, pMonster);
			}
			else cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "은/는 행동불능 상태가 되었습니다!" << endl;
			
			if (!_IsMonsterDied(pMonster)) {
				// 몬스터가 플레이어를 공격한다.
				_Attack(pMonster, _pPlayer);
			}
			else cout << pMonster->szName << "은/는 행동불능 상태가 되었습니다!" << endl;
			system("pause");
			break;

		case BEHAVIOR_RUN:
			cout << "당신은 도망쳤습니다!" << endl;
			DeleteMonsterInfo(&pMonster);
			system("pause");
			return;
		default:
			SystemWarning("잘못된 입력입니다!");
			break;
		}
	}

	_ProcessBattleResult(_pPlayer, pMonster);
	DeleteMonsterInfo(&pMonster);
}

void PrintExitCase(void) {
	system("cls");
	cout << "게임을 종료합니다!" << endl;
	system("exit");
}

void RunTextRpg(void) {
	srand((unsigned int)time(nullptr));

	// Player stPlayer;
	Player* pPlayer = nullptr;

	PrintTitle();

	// SetPlayerInfo(&stPlayer);
	pPlayer = GetPlayerInfo();

	cout << endl;

	while (true) {
		system("cls");
		PrintPlayerInfo(pPlayer);
		cout << endl;
		PrintMenuInterface();
		switch (GetSelectMenuIndex())
		{
		case MENU_LOW:		EnterBattleStage(pPlayer, DIF_LOW);		break;
		case MENU_MIDDLE:	EnterBattleStage(pPlayer, DIF_MIDDLE);	break;
		case MENU_HIGH:		EnterBattleStage(pPlayer, DIF_HIGH);		break;
		case MENU_EXIT:
			DeletePlayerInfo(&pPlayer);
			PrintExitCase();
			return;
		default:			SystemWarning("잘못된 입력입니다!");			break;
		}
	}

	DeletePlayerInfo(&pPlayer);
}