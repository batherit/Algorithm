#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// 시스템 처리 관련 상수
const int ERROR = -1;

// 턴 관련 상수
const int PLAYER = 0;
const int COMPUTER = 1;

// 기본 설정 상수
const int ciBingoSize = 5;
const int ciNameSize = 32;
const int ciShuffleCnt = 1000;

// 탐색 방향
const int VERTICAL = 0;
const int HORIZONTAL = 1;
const int LEFT_TOP = 2;
const int RIGHT_TOP = 3;

const char ciDirectionStr[4][20] = { "세로", "가로", "(좌)대각선", "(우)대각선" };
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
	cout << "잘못된 입력입니다!" << endl;
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
		cout << "누가 먼저 숫자를 말하겠습니까? (0 - 플레이어, 1 - 컴퓨터)" << endl;
		cin >> *iTurn;

		if (PLAYER != *iTurn && COMPUTER != *iTurn) {
			cout << "잘못된 입력입니다!" << endl;
			system("pause");
			continue;
		}
		else if (PLAYER == *iTurn) {
			cout << "플레이어가 먼저 말합니다!" << endl;
			system("pause");
			break;
		}
		else if (COMPUTER == *iTurn) {
			cout << "컴퓨터가 먼저 말합니다!" << endl;
			system("pause");
			break;
		}
	}
}

void PrintBingoBoard(const BINGO_DATA* pBingoData) {
	cout << "\t=============================================" << endl;
	cout << "\t\t현재까지 '" << pBingoData->iBingoCnt << "'빙고입니다." << endl;
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
	// 고른 숫자의 좌표를 갖고 온다.
	if (PLAYER == *pTurn) {
		// 플레이어 턴일 경우
		iSelectedNumber = GetNumberOfUser(pPlayerData);
		cout << "플레이어는 '" << iSelectedNumber << "'을 골랐습니다!" << endl;
	}
	else if (COMPUTER == *pTurn) {
		// 컴퓨터 턴일 경우
		// GetPointOfComputer는 AI, 현재는 단순히 난수로 고른다.
		iSelectedNumber = GetNumberOfComputer(pComData);
		cout << "컴퓨터는 '" << iSelectedNumber << "'을 골랐습니다!" << endl;
	}
	system("pause");

	CheckBingo(pPlayerData, iSelectedNumber);
	CheckBingo(pComData, iSelectedNumber);

	// 턴을 변경한다.
	ChangeTurn(pTurn);
}

void PrintTurn(int iTurn) {
	if (PLAYER == iTurn) cout << "플레이어 차례입니다! " << endl;
	else if (COMPUTER == iTurn) cout << "컴퓨터 차례입니다! " << endl;
}

void ChangeTurn(int* pTurn) {
	if (PLAYER == *pTurn) *pTurn = COMPUTER;
	else if (COMPUTER == *pTurn) *pTurn = PLAYER;
}

int GetNumberOfUser(const BINGO_DATA* pPlayerData) {
	int iSelectedNumber = -1;
	while (true) {
		cout << "숫자를 입력 :";
		// 사용자의 입력을 받는다.
		cin >> iSelectedNumber;

		//해당 입력에 대해 인덱스를 추출한다.
		for (int i = 0; i < ciBingoSize ; i++) {
			for (int j = 0; j < ciBingoSize; j++) {
				if (iSelectedNumber == pPlayerData->iBoard[i][j]) {
					if (false == pPlayerData->iCheck[i][j]) {
						// 체크된적이 없는 수라면 이를 반환한다.
						return iSelectedNumber;
					}
				}
			}
		}
		// 올바른 입력을 받았으므로 반복문을 나가 다른 처리를 진행한다.
		cout << "잘못된 입력입니다. 다시 입력해주세요." << endl << endl;
		system("pause");
	}

	// 올바른 입력이 위 과정에서 무조건 나오는 것을 전제로 한다.
	return iSelectedNumber;
}

int GetNumberOfComputer(const BINGO_DATA* pComData) {
	int iCandidateNumArr[ciBingoSize * ciBingoSize + 1];
	int iCandidateNumCnt = 0;
	int iComInputNum = -1;

	// 뽑지 않은 수들을 찾아 후보 배열에 집어넣는다.
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			if (false == pComData->iCheck[i][j])
				iCandidateNumArr[iCandidateNumCnt++] = pComData->iBoard[i][j];
		}
	}

	// 후보 배열에 들어있는 수 중 아무것이나 뽑는다.
	if (iCandidateNumCnt > 0) {
		iComInputNum = iCandidateNumArr[rand() % iCandidateNumCnt];

		//해당 입력에 대해 인덱스를 추출한다.
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

	//해당 입력에 대해 인덱스를 추출한다.
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			if (iSelectedNumber == pBingoData->iBoard[i][j]) {
				if (false == pBingoData->iCheck[i][j]) {
					// 체크 완료!
					pBingoData->iCheck[i][j] = true;
					sPoint.y = i;
					sPoint.x = j;
				}
				else {
					cout << "ERROR : 이미 체크된 수" << endl;
					system("pause");
					system("exit");
				}
			}
		}
	}
	
	// 현재의 좌표를 기준으로 빙고 여부 확인
	for (int i = 0; i < 4; i++) {
		// 0 - VERTICAL, 1 - HORIZONTAL, 2 - LEFT_TOP, 3 - RIGHT_TOP
		if (IsBingo(pBingoData->iCheck, sPoint, i)) {
			pBingoData->iBingoCnt++;
			cout << '[' << pBingoData->szName << "] : " << ciDirectionStr[i] << " 빙고입니다! " << endl;
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
	cout << "최종 플레이어가 '" << pPlayerData->iBingoCnt << "'빙고, 컴퓨터가 '" << pComData->iBingoCnt <<"'빙고로," << endl;
	if (pPlayerData->iBingoCnt > pComData->iBingoCnt)		cout << "플레이어가 승리하였습니다!" << endl;
	else if (pPlayerData->iBingoCnt < pComData->iBingoCnt)	cout << "컴퓨터가 승리하였습니다!" << endl;
	else cout << "무승부입니다!" << endl;
	cout << "게임을 종료합니다." << endl;
}

void RunBingo(void) {
	srand((unsigned int)time(nullptr));

	int iTurn = PLAYER;

	BINGO_DATA bdPlayerData;
	BINGO_DATA bdComData;

	// 누가 먼저 숫자를 언급할 것인지 턴을 세팅한다.
	SetTurn(&iTurn);

	// 빙고판을 초기화한다.
	//	1) 컴퓨터 빙고판
	strcpy_s(bdComData.szName, strlen("COMPUTER") + 1, "COMPUTER");
	InitBoard(bdComData.iBoard);
	ShuffleBoard(bdComData.iBoard);
	InitCheck(bdComData.iCheck);

	//	2) 플레이어 빙고판
	strcpy_s(bdPlayerData.szName, strlen("PLAYER") + 1, "PLAYER");
	InitBoard(bdPlayerData.iBoard);
	ShuffleBoard(bdPlayerData.iBoard);
	InitCheck(bdPlayerData.iCheck);
	

	while (bdPlayerData.iBingoCnt < ciBingoSize && bdComData.iBingoCnt < ciBingoSize) {
		system("cls");
		// 컴퓨터의 빙고 보드를 출력한다. (특수키 입력으로 없앨 수 있다.)
		PrintBingoBoard(&bdComData);
		cout << endl;
		// 플레이어의 빙고 보드를 출력한다.
		PrintBingoBoard(&bdPlayerData);

		// 플레이어 또는 컴퓨터로부터 숫자를 입력받고 이를 처리한다.
		PrintTurn(iTurn);
		system("pause");
		InputBingoNumberByTurn(&iTurn, &bdPlayerData, &bdComData);	
	}
	PrintResult(&bdPlayerData, &bdComData);
}

// 턴(먼저 말하는 사람)을 세팅한다.
// 컴퓨터의 빙고 보드를 출력한다.
// 플레이어의 빙고 보드를 출력한다.
// 컴퓨터가 말합니다 => 숫자 언급 => 컴퓨터/플레이어 체크판 갱신
// 플레이어가 입력합니다 => 숫자 입력 => 컴퓨터/플레이어 체크판 갱신