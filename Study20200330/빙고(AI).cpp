#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// �ý��� ó�� ���� ���
const int ERROR = -1;

// �� ���� ���
const int PLAYER = 0;
const int COMPUTER = 1;

// �⺻ ���� ���
const int ciBingoSize = 5;
const int ciNameSize = 32;
const int ciShuffleCnt = 1000;

// Ž�� ����
const int VERTICAL = 0;
const int HORIZONTAL = 1;
const int LEFT_TOP = 2;
const int RIGHT_TOP = 3;

const char ciDirectionStr[4][20] = { "����", "����", "(��)�밢��", "(��)�밢��" };
const int ciDX[4] = { 0, 1, 1, -1 };
const int ciDY[4] = { 1, 0, 1, 1 };

typedef struct _point {
	int x;
	int y;
}POINT;

typedef struct _bingo_data {
	char szName[ciNameSize];
	int iBingoCnt = 0;
	int iBoard[ciBingoSize][ciBingoSize] = {};
	bool iCheck[ciBingoSize][ciBingoSize] = {};
}BINGO_DATA;

void PrintBadInput(void);

void InitBoard(int iBoard[][ciBingoSize]);		// == int (*iBoard)[ciBingoSize]
void ShuffleBoard(int iBoard[][ciBingoSize]);
void InitCheck(bool iCheck[][ciBingoSize]);
void SetTurn(int* pTurn);
void PrintBingoBoard(const BINGO_DATA *pBingoData);
void InputBingoNumberByTurn(int* iTurn, BINGO_DATA *pPlayerData, BINGO_DATA *pComData);
void PrintTurn(int iTurn);
void ChangeTurn(int* pTurn);
int GetNumberOfUser(const BINGO_DATA* pPlayerData);
int GetNumberOfComputer(const BINGO_DATA* pComData);
void CheckBingo(BINGO_DATA* pBingoData, int iSelectedNumber);
bool IsValidIndex(int iY, int iX);
bool IsBingo(const bool iCheck[][ciBingoSize], POINT sPoint, int iDirection);
void PrintResult(const BINGO_DATA* pPlayerData, const BINGO_DATA* pComData);
void RunBingo(void);

int main(void) {
	RunBingo();

	return 0;
}








void PrintBadInput(void) {
	cout << "�߸��� �Է��Դϴ�!" << endl;
}

void InitBoard(int iBoard[][ciBingoSize]) {
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			iBoard[i][j] = i * ciBingoSize + j + 1;
		}
	}
}

void ShuffleBoard(int iBoard[][ciBingoSize]) {
	int iDestY, iDestX;
	int iSrcY, iSrcX;

	for (int i = 0; i < ciShuffleCnt; i++) {
		iDestX = rand() % ciBingoSize;
		iDestY = rand() % ciBingoSize;
		iSrcX = rand() % ciBingoSize;
		iSrcY = rand() % ciBingoSize;

		swap(iBoard[iDestY][iDestX], iBoard[iSrcY][iSrcX]);
	}
}

void InitCheck(bool iCheck[][ciBingoSize]) {
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			iCheck[i][j] = false;
		}
	}
}

void SetTurn(int* iTurn) {
	while (true) {
		system("cls");
		cout << "���� ���� ���ڸ� ���ϰڽ��ϱ�? (0 - �÷��̾�, 1 - ��ǻ��)" << endl;
		cin >> *iTurn;

		if (PLAYER != *iTurn && COMPUTER != *iTurn) {
			cout << "�߸��� �Է��Դϴ�!" << endl;
			system("pause");
			continue;
		}
		else if (PLAYER == *iTurn) {
			cout << "�÷��̾ ���� ���մϴ�!" << endl;
			system("pause");
			break;
		}
		else if (COMPUTER == *iTurn) {
			cout << "��ǻ�Ͱ� ���� ���մϴ�!" << endl;
			system("pause");
			break;
		}
	}
}

void PrintBingoBoard(const BINGO_DATA* pBingoData) {
	cout << "\t=============================================" << endl;
	cout << "\t\t������� '" << pBingoData->iBingoCnt << "'�����Դϴ�." << endl;
	cout << "\t=============================================" << endl;
	for (int i = 0; i < ciBingoSize; i++) {
		cout << '\t';
		for (int j = 0; j < ciBingoSize; j++) {
			if (false == pBingoData->iCheck[i][j]) {
				cout << pBingoData->iBoard[i][j] << '\t';
			}
			else {
				cout << 'x' << '\t';
			}
		}
		cout << endl;
	}
}

void InputBingoNumberByTurn(int* pTurn, BINGO_DATA *pPlayerData, BINGO_DATA *pComData) {
	int iSelectedNumber;
	// �� ������ ��ǥ�� ���� �´�.
	if (PLAYER == *pTurn) {
		// �÷��̾� ���� ���
		iSelectedNumber = GetNumberOfUser(pPlayerData);
		cout << "�÷��̾�� '" << iSelectedNumber << "'�� ������ϴ�!" << endl;
	}
	else if (COMPUTER == *pTurn) {
		// ��ǻ�� ���� ���
		// GetPointOfComputer�� AI, ����� �ܼ��� ������ ����.
		iSelectedNumber = GetNumberOfComputer(pComData);
		cout << "��ǻ�ʹ� '" << iSelectedNumber << "'�� ������ϴ�!" << endl;
	}
	system("pause");

	CheckBingo(pPlayerData, iSelectedNumber);
	CheckBingo(pComData, iSelectedNumber);

	// ���� �����Ѵ�.
	ChangeTurn(pTurn);
}

void PrintTurn(int iTurn) {
	if (PLAYER == iTurn) cout << "�÷��̾� �����Դϴ�! " << endl;
	else if (COMPUTER == iTurn) cout << "��ǻ�� �����Դϴ�! " << endl;
}

void ChangeTurn(int* pTurn) {
	if (PLAYER == *pTurn) *pTurn = COMPUTER;
	else if (COMPUTER == *pTurn) *pTurn = PLAYER;
}

int GetNumberOfUser(const BINGO_DATA* pPlayerData) {
	int iSelectedNumber = -1;
	while (true) {
		cout << "���ڸ� �Է� :";
		// ������� �Է��� �޴´�.
		cin >> iSelectedNumber;

		//�ش� �Է¿� ���� �ε����� �����Ѵ�.
		for (int i = 0; i < ciBingoSize ; i++) {
			for (int j = 0; j < ciBingoSize; j++) {
				if (iSelectedNumber == pPlayerData->iBoard[i][j]) {
					if (false == pPlayerData->iCheck[i][j]) {
						// üũ������ ���� ����� �̸� ��ȯ�Ѵ�.
						return iSelectedNumber;
					}
				}
			}
		}
		// �ùٸ� �Է��� �޾����Ƿ� �ݺ����� ���� �ٸ� ó���� �����Ѵ�.
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl << endl;
		system("pause");
	}

	// �ùٸ� �Է��� �� �������� ������ ������ ���� ������ �Ѵ�.
	return iSelectedNumber;
}

int GetNumberOfComputer(const BINGO_DATA* pComData) {
	int iCandidateNumArr[ciBingoSize * ciBingoSize + 1];
	int iCandidateNumCnt = 0;
	int iComInputNum = -1;

	// ���� ���� ������ ã�� �ĺ� �迭�� ����ִ´�.
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			if (false == pComData->iCheck[i][j])
				iCandidateNumArr[iCandidateNumCnt++] = pComData->iBoard[i][j];
		}
	}

	// �ĺ� �迭�� ����ִ� �� �� �ƹ����̳� �̴´�.
	if (iCandidateNumCnt > 0) {
		iComInputNum = iCandidateNumArr[rand() % iCandidateNumCnt];

		//�ش� �Է¿� ���� �ε����� �����Ѵ�.
		for (int i = 0; i < ciBingoSize; i++) {
			for (int j = 0; j < ciBingoSize; j++) {
				if (iComInputNum == pComData->iBoard[i][j]) {
					if (false == pComData->iCheck[i][j]) {
						return iComInputNum;
						
					}
				}
			}
		}
	}

	return iComInputNum;
}

void CheckBingo(BINGO_DATA* pBingoData, int iSelectedNumber) {
	POINT sPoint = { ERROR, ERROR };

	//�ش� �Է¿� ���� �ε����� �����Ѵ�.
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			if (iSelectedNumber == pBingoData->iBoard[i][j]) {
				if (false == pBingoData->iCheck[i][j]) {
					// üũ �Ϸ�!
					pBingoData->iCheck[i][j] = true;
					sPoint.y = i;
					sPoint.x = j;
				}
				else {
					cout << "ERROR : �̹� üũ�� ��" << endl;
					system("pause");
					system("exit");
				}
			}
		}
	}
	
	// ������ ��ǥ�� �������� ���� ���� Ȯ��
	for (int i = 0; i < 4; i++) {
		// 0 - VERTICAL, 1 - HORIZONTAL, 2 - LEFT_TOP, 3 - RIGHT_TOP
		if (IsBingo(pBingoData->iCheck, sPoint, i)) {
			pBingoData->iBingoCnt++;
			cout << '[' << pBingoData->szName << "] : " << ciDirectionStr[i] << " �����Դϴ�! " << endl;
			system("pause");
		}
	}
}

bool IsValidIndex(int iY, int iX) {
	return  (0 <= iY && iY < ciBingoSize) && (0 <= iX && iX < ciBingoSize);
}

bool IsBingo(const bool iCheck[][ciBingoSize], POINT sPoint, int iDirection) {
	int iDynamicY, iDynamicX;

	int iCheckCnt = 1;
	iDynamicY = sPoint.y, iDynamicX = sPoint.x;
	
	while (IsValidIndex(iDynamicY += ciDY[iDirection], iDynamicX += ciDX[iDirection])) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	
	iDynamicY = sPoint.y, iDynamicX = sPoint.x;
	while (IsValidIndex(iDynamicY -= ciDY[iDirection], iDynamicX -= ciDX[iDirection])) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	if (ciBingoSize == iCheckCnt) return true;
	return false;
}

void PrintResult(const BINGO_DATA* pPlayerData, const BINGO_DATA* pComData) {
	cout << "���� �÷��̾ '" << pPlayerData->iBingoCnt << "'����, ��ǻ�Ͱ� '" << pComData->iBingoCnt <<"'�����," << endl;
	if (pPlayerData->iBingoCnt > pComData->iBingoCnt)		cout << "�÷��̾ �¸��Ͽ����ϴ�!" << endl;
	else if (pPlayerData->iBingoCnt < pComData->iBingoCnt)	cout << "��ǻ�Ͱ� �¸��Ͽ����ϴ�!" << endl;
	else cout << "���º��Դϴ�!" << endl;
	cout << "������ �����մϴ�." << endl;
}

void RunBingo(void) {
	srand((unsigned int)time(nullptr));

	int iTurn = PLAYER;

	BINGO_DATA bdPlayerData;
	BINGO_DATA bdComData;

	// ���� ���� ���ڸ� ����� ������ ���� �����Ѵ�.
	SetTurn(&iTurn);

	// �������� �ʱ�ȭ�Ѵ�.
	//	1) ��ǻ�� ������
	strcpy_s(bdComData.szName, strlen("COMPUTER") + 1, "COMPUTER");
	InitBoard(bdComData.iBoard);
	ShuffleBoard(bdComData.iBoard);
	InitCheck(bdComData.iCheck);

	//	2) �÷��̾� ������
	strcpy_s(bdPlayerData.szName, strlen("PLAYER") + 1, "PLAYER");
	InitBoard(bdPlayerData.iBoard);
	ShuffleBoard(bdPlayerData.iBoard);
	InitCheck(bdPlayerData.iCheck);
	

	while (bdPlayerData.iBingoCnt < ciBingoSize && bdComData.iBingoCnt < ciBingoSize) {
		system("cls");
		// ��ǻ���� ���� ���带 ����Ѵ�. (Ư��Ű �Է����� ���� �� �ִ�.)
		PrintBingoBoard(&bdComData);
		cout << endl;
		// �÷��̾��� ���� ���带 ����Ѵ�.
		PrintBingoBoard(&bdPlayerData);

		// �÷��̾� �Ǵ� ��ǻ�ͷκ��� ���ڸ� �Է¹ް� �̸� ó���Ѵ�.
		PrintTurn(iTurn);
		system("pause");
		InputBingoNumberByTurn(&iTurn, &bdPlayerData, &bdComData);	
	}
	PrintResult(&bdPlayerData, &bdComData);
}

// ��(���� ���ϴ� ���)�� �����Ѵ�.
// ��ǻ���� ���� ���带 ����Ѵ�.
// �÷��̾��� ���� ���带 ����Ѵ�.
// ��ǻ�Ͱ� ���մϴ� => ���� ��� => ��ǻ��/�÷��̾� üũ�� ����
// �÷��̾ �Է��մϴ� => ���� �Է� => ��ǻ��/�÷��̾� üũ�� ����