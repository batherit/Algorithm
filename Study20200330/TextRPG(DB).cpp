#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;


// ��� ����
const int ciNameSize = 32;
const int ciDescSize = 256;
const int ciItemSize = 10;

const int ciMonsterSize = 5;
const int ciBattleStartSec = 3;
const int ciAddAmount = 5;
const int ciMinPropertyValue = 0;
const int ciMaxPropertyValue = 100;

const int ciStoredItemsSize = 20;
const int ciCommonItemSize = 0;
const int ciWarriorItemSize = 2;
const int ciWizardItemSize = 0;
const int ciThiefItemSize = 0;

const int ciFileNameSize = 64;
const char ccPlayerSaveFileDirectory[ciFileNameSize] = "../SaveFile/PlayerInfo.dat";

// Ű�� �����ϴ� ���� 1���� ����
enum E_CLASS {
	CLASS_COMMON, CLASS_WARRIOR = 1, CLASS_WIZARD, CLASS_THIEF, CLASS_END
};
enum E_BEHAVIOR {
	BEHAVIOR_BATTLE = 1, BEHAVIOR_RUN, BEHAVIOR_END
};
enum E_DIFFICULTY {
	DIFF_LOW, DIFF_MIDDLE, DIFF_HIGH, DIFF_END
};
enum E_MENU {
	MENU_LOW = 1, MENU_MIDDLE, MENU_HIGH, MENU_INVENTORY, MENU_EXIT, MENU_END
};
enum E_ITEM_USE {
	IU_EQUIPMENT, IU_POTION, IU_END
};

enum E_EQUIPMENT_POS {
	EP_NONE, EP_WEAPON, EP_HEAD, EP_BODY, EP_ARM, EP_LEG, EP_ACCESSORY, EP_END
};

// ����ü ����
typedef struct _item {
	E_ITEM_USE eItemUse;
	float fDropRate;
	char szName[ciNameSize];
	char szDesc[ciDescSize];
	E_EQUIPMENT_POS eEquipmentPos;
	int iDeltaHp;
	int iDeltaMaxHp;
	int iDeltaAtk;
	int iDeltaDef;
	int iDeltaLck;
}Item;

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
	int iStoredItemsNum;
	Item eStoredItemsArr[ciStoredItemsSize];
}Player;

typedef struct _monster {
	char szName[ciNameSize];
	int iHp;
	int iAtk;
	int iDef;
	int iLck;
}Monster;

const Item ceItems[CLASS_END][ciItemSize] = { 
	// ����
	{
		{ IU_POTION, 30.0f, "������", "�ܻ�ó�� ġ���ϴµ� ȿ������ �� �ϴ�.",     EP_NONE,			10, 0, 0, 0, 0}
	},
	// ����
	{
																												 
		{ IU_EQUIPMENT, 70.0f, "����", "������ ���µ� ���� ���� ���� �����̴�.",	EP_WEAPON	,		0, 0, 15, 0, 0},
		{ IU_EQUIPMENT, 50.0f, "��ɲ��� ��", "����� �ϱ⿡ ���� ���̴�.",		EP_BODY	,		0, 10, 0, 15, 0}
	},
	// ������
	{

	},
	// ����
	{

	}
};


// �÷��̾� �Ӽ����� E_CLASS�� ������
const int ciPlayerHP[CLASS_END] = { -1, 40, 30, 20 };
const int ciPlayerAtk[CLASS_END] = { -1, 30, 45, 20 };
const int ciPlayerDef[CLASS_END] = { -1, 15, 10, 5 };
const int ciPlayerLck[CLASS_END] = { -1, 5 , 5, 35 };

// Ŭ���� �̸����� E_CLASS�� ����
const char ccClassName[CLASS_END][ciNameSize] = { "NULL", "����", "������", "����" };

// ���� �Ӽ����� E_DIFFICULTY ���� ����
const int ciMonsterNum[DIFF_END] = { 3, 4, 3 };
const char ccMonsterName[DIFF_END][ciMonsterSize][ciNameSize] = {
	{ "�Ʊ����", "���", "�罿" }, 
	{ "��ū����", "�������", "���ŧ��", "�ڻԼ�" },
	{ "��������", "¯�� �ڳ���", "���" }
}; 
const int ciMonsterMaxHp[DIFF_END] = { 30, 100, 200 };
const int ciMonsterMinHp[DIFF_END] = { 10, 50, 120 };
const int ciMonsterMaxAtk[DIFF_END] = { 15, 30, 80 };
const int ciMonsterMinAtk[DIFF_END] = { 5, 10, 50 };
const int ciMonsterMaxDef[DIFF_END] = { 5, 30, 80 };
const int ciMonsterMinDef[DIFF_END] = { 2, 10, 50 };
const int ciMonsterMaxLck[DIFF_END] = { 5, 15, 30 };
const int ciMonsterMinLck[DIFF_END] = { 1, 5, 10 };




void ErrorAssertion(const char _szErrorString[]);
void SystemWarning(const char _szWarningString[]);
void InitGameEnvironment(void);
void _CreateItemDatas(void);
void PrintTitle(void);
bool _IsNaturalNumber(int _iNum);
void _SetNaturalNumber(const char _szNumberName[], int* _iValueToSave);
void _SetClass(E_CLASS* _pClass);
void SetPlayerInfo(Player* _pPlayer);
bool _IsSaveFileExist(void);
bool CheckContinueGame(void);
void _SavePlayerInfo(const Player* _pPlayer);
Player* AllocatePlayerInfoFromSaveFile(void);
Player* AllocatePlayerInfo(void);
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
bool _CheckAttackeEvasion(int _iLck);
void _Attack(Player* _pTo, Monster* _pFrom);
void _Attack(Monster* _pTo, Player* _pFrom);
bool _IsPlayerDied(const Player* _pPlayer);
bool _CheckHP(const Player* _pPlayer, const Monster* _pMonster);
void _Clamp(int* _iValue, int _iMin, int _iMax);
void _ProcessBattleResult(Player* _pPlayer, Monster* _pMonster);
void IncreasePlayerExp(Player* _pPlayer, int _iExpToAdd);
void EnterBattleStage(Player* _pPlayer, E_DIFFICULTY _eDifficulty);
void PrintInventory(Player* _pPlayer);
void EnterInventory(Player* _pPlayer);
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

void InitGameEnvironment(void) {
	_CreateItemDatas();
}
void _CreateItemDatas(void) {

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
		if (CLASS_WARRIOR <= iInput && iInput < CLASS_END) {
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

	_SetClass(&_pPlayer->eClass);
	_pPlayer->iMaxHp = ciPlayerHP[_pPlayer->eClass];
	_pPlayer->iHp = ciPlayerHP[_pPlayer->eClass];
	_pPlayer->iAtk = ciPlayerAtk[_pPlayer->eClass];
	_pPlayer->iDef = ciPlayerDef[_pPlayer->eClass];
	_pPlayer->iLck = ciPlayerLck[_pPlayer->eClass];
	_pPlayer->iLevel = 1;
	_pPlayer->dExp = 0.0;
	_pPlayer->iStoredItemsNum = 0;
}

bool _IsSaveFileExist(void) {
	FILE* fpPlayerInfo = nullptr;
	errno_t err = 0;

	err = fopen_s(&fpPlayerInfo, ccPlayerSaveFileDirectory, "rb");
	if(fpPlayerInfo) fclose(fpPlayerInfo);
	
	if (0 == err) return true;
	return false;
}

bool CheckContinueGame(void) {
	if (_IsSaveFileExist()) {
		int iSelect;

		while (true) {
			system("cls");
			cout << "���̺� ������ �����մϴ�. �̾��Ͻðڽ��ϱ�? (1 - YES, 2 - NO)" << endl;
			cin >> iSelect;

			switch (iSelect)
			{
			case 1: return true;
			case 2: return false;
			default:
				SystemWarning("�߸��� �Է��Դϴ�!");
				break;
			}
		}
	}
	return false;
}

void _SavePlayerInfo(const Player* _pPlayer) {
	cout << "�÷��̾� ������ �����մϴ�!" << endl;
	system("pause");

	FILE* fpPlayerInfo = nullptr;
	errno_t err = 0;

	err = fopen_s(&fpPlayerInfo, ccPlayerSaveFileDirectory, "wb");
	if (0 == err) {
		fwrite(_pPlayer, sizeof(Player), 1, fpPlayerInfo);
		if (fpPlayerInfo) fclose(fpPlayerInfo);

		cout << "�÷��̾� ������ �����߽��ϴ�!" << endl;
		system("pause");
	}
	else SystemWarning("������ �����ϴµ� �����߽��ϴ�.");
}

Player* AllocatePlayerInfoFromSaveFile(void) {
	Player* pSavedPlayerInfo = new Player;

	FILE* fpPlayerInfo = nullptr;
	errno_t err = 0;

	err = fopen_s(&fpPlayerInfo, ccPlayerSaveFileDirectory, "rb");
	if (0 == err) {
		fread(pSavedPlayerInfo, sizeof(Player), 1, fpPlayerInfo);
		if (fpPlayerInfo) fclose(fpPlayerInfo);

		return pSavedPlayerInfo;
	}
	else ErrorAssertion("����� �÷��̾� ������ �о���� ���߽��ϴ�!");

	return nullptr;
}

Player* AllocatePlayerInfo(void) {
	Player* pPlayer = new Player;

	while (true) {
		system("cls");
		cout << "�÷��̾� �̸��� �Է��ϼ���. :";
		cin >> pPlayer->szName;
		break;
	}

	/*_SetNaturalNumber("�÷��̾� HP", &_pPlayer->iMaxHp);
	_pPlayer->iHp = _pPlayer->iMaxHp;
	_SetNaturalNumber("�÷��̾� ���ݷ�", &_pPlayer->iAtk);
	_SetNaturalNumber("�÷��̾� ����", &_pPlayer->iDef);*/
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
	cout << "-----[�÷��̾� ����]-----" << endl;
	cout << "  ����   : " << _pPlayer->iLevel << '(' << _pPlayer->dExp << "%)" << endl;
	cout << "  ����   : " << ccClassName[_pPlayer->eClass] << endl;
	cout << "  �̸�   : " << _pPlayer->szName << endl;
	cout << endl;
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
	cout << "-----[���� ����]-----" << endl;
	cout << "  �̸�   : " << _pMonster->szName << endl;
	cout << endl;
	cout << "  HP     : " << _pMonster->iHp << endl;
	cout << "  ���ݷ� : " << _pMonster->iAtk << endl;
	cout << "  ���� : " << _pMonster->iDef << endl;
	cout << "  ���   : " << _pMonster->iLck << endl;
}

void PrintMenuInterface(void) {
	cout << "1. �ʱ�, 2. �߱�, 3. ���, 4. �κ��丮, 5. ������" << endl;
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

bool _IsMonsterDied(const Monster* _pMonster) {
	return 0 >= _pMonster->iHp;
}

bool _CheckHP(const Player* _pPlayer, const Monster* _pMonster) {
	return (_pPlayer->iHp > 0 && _pMonster->iHp > 0);
}

void _Clamp(int* _iValue, int _iMin, int _iMax) {
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
		IncreasePlayerExp(_pPlayer, double((_pMonster->iAtk + _pMonster->iDef + _pMonster->iLck)) / _pPlayer->iLevel);
		
		system("pause");
	}
}

void IncreasePlayerExp(Player* _pPlayer, int _iExpToAdd) {
	_pPlayer->dExp += _iExpToAdd;
	int iAddAmount = int(_pPlayer->dExp) / 100;
	if (iAddAmount != 0) {
		// ������ �ö��ٸ� �Ӽ������� ������Ų��.
		_Clamp(&(_pPlayer->iLevel += iAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_Clamp(&(_pPlayer->iMaxHp += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_pPlayer->iHp = _pPlayer->iMaxHp;
		_Clamp(&(_pPlayer->iAtk += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_Clamp(&(_pPlayer->iDef += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_Clamp(&(_pPlayer->iLck += ciAddAmount), ciMinPropertyValue, ciMaxPropertyValue);
		_pPlayer->dExp -= iAddAmount * 100;
		cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "��/�� ���� '" << _pPlayer->iLevel << "'��/�� �Ǿ����ϴ�!" << endl;
	}
}

void EnterBattleStage(Player* _pPlayer, E_DIFFICULTY _eDifficulty) {
	//Monster stMonster;
	//SetMonsterInfo(&stMonster, _eDifficulty);
	Monster* pMonster;
	pMonster = GetMonsterInfo(_eDifficulty);

	system("cls");
	cout << "������ ���۵˴ϴ�!" << endl;
	cout << "����� [" << pMonster->szName << "]��/�� �����Ͽ����ϴ�!!" << endl;
	system("pause");

	while (_CheckHP(_pPlayer, pMonster)) {
		system("cls");
		// �÷��̾� �� ���� ���� ���
		PrintPlayerInfo(_pPlayer);
		cout << endl;
		PrintMonsterInfo(pMonster);
		cout << endl;
		PrintBehaviorInterface();
		switch (GetSelectBehaviorIndex())
		{
		case BEHAVIOR_BATTLE:
			if (!_IsPlayerDied(_pPlayer)) {
				// �÷��̾ ���͸� �����Ѵ�.
				_Attack(_pPlayer, pMonster);
			}
			else cout << ccClassName[_pPlayer->eClass] << ' ' << _pPlayer->szName << "��/�� �ൿ�Ҵ� ���°� �Ǿ����ϴ�!" << endl;
			
			if (!_IsMonsterDied(pMonster)) {
				// ���Ͱ� �÷��̾ �����Ѵ�.
				_Attack(pMonster, _pPlayer);
			}
			else cout << pMonster->szName << "��/�� �ൿ�Ҵ� ���°� �Ǿ����ϴ�!" << endl;
			system("pause");
			break;

		case BEHAVIOR_RUN:
			cout << "����� �����ƽ��ϴ�!" << endl;
			DeleteMonsterInfo(&pMonster);
			system("pause");
			return;
		default:
			SystemWarning("�߸��� �Է��Դϴ�!");
			break;
		}
	}

	_ProcessBattleResult(_pPlayer, pMonster);
	DeleteMonsterInfo(&pMonster);
}

void PrintInventory(Player* _pPlayer) {

}

void EnterInventory(Player* _pPlayer) {
	if (_pPlayer->iStoredItemsNum <= 0) {
		cout << "���� ������ �������� �����ϴ�!" << endl;
		system("pause");
	}

	while (true) {
		system("cls");
		PrintInventory(_pPlayer);
		/*�κ��丮 ���� �۾� ó��*/
	}
}

void PrintExitCase(void) {
	system("cls");
	cout << "������ �����մϴ�!" << endl;
	system("exit");
}

void RunTextRpg(void) {
	srand((unsigned int)time(nullptr));

	// Player stPlayer;
	Player* pPlayer = nullptr;

	PrintTitle();

	// SetPlayerInfo(&stPlayer);
	if (CheckContinueGame()) {
		cout << "����� �÷��̾� ������ �����մϴ�." << endl;
		system("pause");
		pPlayer = AllocatePlayerInfoFromSaveFile();
	}
	else {
		pPlayer = AllocatePlayerInfo();
	}


	cout << endl;

	while (true) {
		system("cls");
		PrintPlayerInfo(pPlayer);
		cout << endl;
		PrintMenuInterface();
		switch (GetSelectMenuIndex())
		{
		case MENU_LOW:			
			EnterBattleStage(pPlayer, DIFF_LOW);		
			break;
		case MENU_MIDDLE:		
			EnterBattleStage(pPlayer, DIFF_MIDDLE);		
			break;
		case MENU_HIGH:			
			EnterBattleStage(pPlayer, DIFF_HIGH);		
			break;
		case MENU_INVENTORY:	
			EnterInventory(pPlayer);					
			break;
		case MENU_EXIT:
			_SavePlayerInfo(pPlayer);
			DeletePlayerInfo(&pPlayer);
			PrintExitCase();
			return;
		default:				
			SystemWarning("�߸��� �Է��Դϴ�!");			
			break;
		}
	}

	DeletePlayerInfo(&pPlayer);
}