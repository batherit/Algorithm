#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

const int ciNameSize = 32;
const int ciMonsterSize = 5;
const int ciBattleStartSec = 3;
const int ciAddAmount = 5;

enum E_CLASS			{ CLASS_WARRIOR = 1, CLASS_WIZARD, CLASS_THIEF, CLASS_EOF };
enum E_BEHAVIOR			{ BEHAVIOR_BATTLE = 1, BEHAVIOR_RUN, BEHAVIOR_EOF };
enum E_DIFFICULTY		{ DIF_LOW, DIF_MIDDLE, DIF_HIGH, DIF_EOF };
enum E_MENU				{ MENU_LOW = 1, MENU_MIDDLE, MENU_HIGH, MENU_EXIT, MENU_EOF };

// �÷��̾� �Ӽ����� E_CLASS�� ������
const int ciPlayerHP[CLASS_EOF] = { -1, 40, 30, 20 };
const int ciPlayerAtk[CLASS_EOF] = { -1, 30, 45, 20 };
const int ciPlayerDef[CLASS_EOF] = { -1, 15, 10, 5 };
const int ciPlayerLck[CLASS_EOF] = { -1, 5 , 5, 35 };

// Ŭ���� �̸����� E_CLASS�� ����
const char ccClassName[CLASS_EOF][ciNameSize] = { "NULL", "����", "������", "����" };

// ���� �Ӽ����� E_DIFFICULTY ���� ����
const int ciMonsterNum[DIF_EOF] = { 3, 4, 3 };
const char ccMonsterName[DIF_EOF][ciMonsterSize][ciNameSize] = {
	{ "�Ʊ����", "���", "�罿" }, 
	{ "��ū����", "�������", "���ŧ��", "�ڻԼ�" },
	{ "��������", "¯�� �ڳ���", "���" }
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
void PrintPlayerInfo(const Player* _pPlayer);
int GetNumberMinBetweenMax(int _iMin, int _iMax);
void SetMonsterInfo(Monster* _pMonster, E_DIFFICULTY _eDifficulty);
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
		cout << '[' << szNumberName << "] �Է� :";
		cin >> *iValueToSave;

		if (!_IsNaturalNumber(*iValueToSave)) {
			SystemWarning("�� ���� 0���ϰ� �� �� �����ϴ�!");
		}
		else break;
	}
}

void _SetClass(E_CLASS* pClass) {
	int iInput;
	while (true) {
		system("cls");
		cout << "� ������ �����ڽ��ϱ�? (1 - ����, 2 - ������, 3 - ����) :";
		cin >> iInput;
		if (CLASS_WARRIOR <= iInput && iInput < CLASS_EOF) {
			//strcpy_s(_szClassName, ciNameSize, ccClassName[iInput]);
			*pClass = (E_CLASS)iInput;
			break;
		}
		else {
			SystemWarning("�߸��� �Է��Դϴ�!");
		}
	}
}

void SetPlayerInfo(Player* _pPlayer) {
	while (true) {
		system("cls");
		cout << "�÷��̾� �̸��� �Է��ϼ���. :";
		cin >> _pPlayer->szName;
		break;
	}

	/*_SetNaturalNumber("�÷��̾� HP", &_pPlayer->iMaxHp);
	_pPlayer->iHp = _pPlayer->iMaxHp;
	_SetNaturalNumber("�÷��̾� ���ݷ�", &_pPlayer->iAtk);
	_SetNaturalNumber("�÷��̾� ����", &_pPlayer->iDef);*/
	_SetClass(&_pPlayer->eClass);
	_pPlayer->iMaxHp = ciPlayerHP[_pPlayer->eClass];
	_pPlayer->iHp = ciPlayerHP[_pPlayer->eClass];
	_pPlayer->iAtk = ciPlayerAtk[_pPlayer->eClass];
	_pPlayer->iDef = ciPlayerDef[_pPlayer->eClass];
	_pPlayer->iLck = ciPlayerLck[_pPlayer->eClass];
	_pPlayer->iLevel = 1;
	_pPlayer->dExp = 0.0;
}

void PrintPlayerInfo(const Player* _pPlayer) {
	cout << "-----[�÷��̾� ����]-----" << endl;
	cout << "  ����   : " << _pPlayer->iLevel << '(' << _pPlayer->dExp << "%)" << endl;
	cout << "  ����   : " << ccClassName[_pPlayer->eClass] << endl;
	cout << "  �̸�   : " << _pPlayer->szName << endl;
	cout << "  HP     : " << _pPlayer->iHp << endl;
	cout << "  ���ݷ� : " << _pPlayer->iAtk << endl;
	cout << "  ���� : " << _pPlayer->iDef << endl;
	cout << "  ���   : " << _pPlayer->iLck << endl;
}

int GetNumberMinBetweenMax(int _iMin, int _iMax) {
	if (_iMin > _iMax) {
		ErrorAssertion("�ּڰ��� �ִ񰪺��� Ŭ �� �����ϴ�!");
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

void PrintMonsterInfo(const Monster* _pMonster) {
	cout << "-----[���� ����]-----" << endl;
	cout << "  �̸�   : " << _pMonster->szName << endl;
	cout << "  HP     : " << _pMonster->iHp << endl;
	cout << "  ���ݷ� : " << _pMonster->iAtk << endl;
	cout << "  ���� : " << _pMonster->iDef << endl;
	cout << "  ���   : " << _pMonster->iLck << endl;
}

void PrintMenuInterface(void) {
	cout << "1. �ʱ�, 2. �߱�, 3. ����, 4. ������" << endl;
	cout << "�Է� : ";
}

int GetSelectMenuIndex(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

void PrintBehaviorInterface(void) {
	cout << "1. �����ϱ�, 2. ��������" << endl;
	cout << "�Է� : ";
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
		cout <<  pFrom->szName << "��/�� " << ccClassName[pTo->eClass] << ' ' << pTo->szName << "�� ������ ���߽��ϴ�!" << endl;
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
		cout << ccClassName[pTo->eClass] << ' ' << pTo->szName << "��/�� " << pFrom->szName << "���� " << iDamage << "�� ���ظ� �������ϴ�!" << endl;
	}
}

void _Attack(Monster* pTo, Player* pFrom) {
	if (_CheckAttackeEvasion(pFrom->iLck)) {
		cout << pFrom->szName << "��/�� " << pTo->szName << "�� ������ ���߽��ϴ�!" << endl;
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
		cout << pTo->szName << "��/�� " << ccClassName[pFrom->eClass] << ' ' << pFrom->szName << "���� " << iDamage << "�� ���ظ� �������ϴ�!" << endl;
	}
	
}

bool _IsPlayerDied(const Player* _pPlayer) {
	return 0 >= _pPlayer->iHp;
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
		cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "��/�� ���������ϴ�!" << endl;
		system("pause");
		// HP�� �����·� ���ͽ�Ű�� ����.
		_pPlayer->iHp = _pPlayer->iMaxHp;
	}
	else {
		cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "��/�� �̰���ϴ�!" << endl;
		// ����ġ�� ������Ų��.
		_pPlayer->dExp += double((_pMonster->iAtk + _pMonster->iDef + _pMonster->iLck)) / _pPlayer->iLevel;

		// ������ �ö��ٸ� �Ӽ������� ������Ų��.
		int iAddAmount = int(_pPlayer->dExp) / 100;
		if (iAddAmount != 0) {
			_Lerp(&(_pPlayer->iLevel += iAddAmount), 0, 100);
			_Lerp(&(_pPlayer->iMaxHp += ciAddAmount), 0, 100);
			_pPlayer->iHp = _pPlayer->iMaxHp;
			_Lerp(&(_pPlayer->iAtk += ciAddAmount), 0, 100);
			_Lerp(&(_pPlayer->iDef += ciAddAmount), 0, 100);
			_Lerp(&(_pPlayer->iLck += ciAddAmount), 0, 100);
			_pPlayer->dExp -= iAddAmount * 100;
			cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "��/�� ���� '"<< _pPlayer->iLevel << "'��/�� �Ǿ����ϴ�!" << endl;
		}
		
		system("pause");
	}
}

void EnterBattleStage(Player* _pPlayer, E_DIFFICULTY _eDifficulty) {
	Monster stMonster;
	SetMonsterInfo(&stMonster, _eDifficulty);

	system("cls");
	cout << "������ ���۵˴ϴ�!" << endl;
	cout << "����� [" << stMonster.szName << "]��/�� �����Ͽ����ϴ�!!" << endl;
	system("pause");

	while (_CheckHP(_pPlayer, &stMonster)) {
		system("cls");
		// �÷��̾� �� ���� ���� ���
		PrintPlayerInfo(_pPlayer);
		cout << endl;
		PrintMonsterInfo(&stMonster);
		cout << endl;
		PrintBehaviorInterface();
		switch (GetSelectBehaviorIndex())
		{
		case BEHAVIOR_BATTLE:
			// �÷��̾ ���͸� �����Ѵ�.
			_Attack(_pPlayer, &stMonster);
			// ���Ͱ� �÷��̾ �����Ѵ�.
			_Attack(&stMonster, _pPlayer);
			system("pause");
			break;

		case BEHAVIOR_RUN:
			cout << "����� �����ƽ��ϴ�!" << endl;
			system("pause");
			return;
		default:
			SystemWarning("�߸��� �Է��Դϴ�!");
			break;
		}
	}

	_ProcessBattleResult(_pPlayer, &stMonster);
}

void PrintExitCase(void) {
	system("cls");
	cout << "������ �����մϴ�!" << endl;
	system("exit");
}

void RunTextRpg(void) {
	srand((unsigned int)time(nullptr));

	Player stPlayer;

	PrintTitle();

	SetPlayerInfo(&stPlayer);
	cout << endl;

	while (true) {
		system("cls");
		PrintPlayerInfo(&stPlayer);
		cout << endl;
		PrintMenuInterface();
		switch (GetSelectMenuIndex())
		{
		case MENU_LOW:		EnterBattleStage(&stPlayer, DIF_LOW);		break;
		case MENU_MIDDLE:	EnterBattleStage(&stPlayer, DIF_MIDDLE);	break;
		case MENU_HIGH:		EnterBattleStage(&stPlayer, DIF_HIGH);		break;
		case MENU_EXIT:		PrintExitCase();							return;
		default:			SystemWarning("�߸��� �Է��Դϴ�!");			break;
		}
	}
}