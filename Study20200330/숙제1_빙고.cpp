#include<iostream>
using namespace std;

typedef struct _point {
	int x;
	int y;
}POINT;

const int ERROR = -1;

const int ciBingoSize = 5;

void InitBoard(int iBoard[][ciBingoSize]);
void InitCheck(bool iCheck[][ciBingoSize]);
void PrintBingoBoard(int iBoard[][ciBingoSize], bool iCheck[][ciBingoSize], int iBingoCnt);
POINT GetPointByInput(int iBoard[][ciBingoSize], bool iCheck[][ciBingoSize]);
bool IsValidIndex(int iY, int iX);
bool IsHorizontalBingo(bool iCheck[][ciBingoSize], int iY, int iX);
bool IsVerticalBingo(bool iCheck[][ciBingoSize], int iY, int iX);
bool IsLeftTopBingo(bool iCheck[][ciBingoSize], int iY, int iX);
bool IsRightTopBingo(bool iCheck[][ciBingoSize], int iY, int iX);
void PrintResult(int iBingoCnt);
void RunBingo(void);

int main(void) {
	RunBingo();

	return 0;
}










void InitBoard(int iBoard[][ciBingoSize]) {
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			iBoard[i][j] = i * ciBingoSize + j + 1;
		}
	}
}

void InitCheck(bool iCheck[][ciBingoSize]) {
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			iCheck[i][j] = false;
		}
	}
}

void PrintBingoBoard(int iBoard[][ciBingoSize], bool iCheck[][ciBingoSize], int iBingoCnt) {
	for (int i = 0; i < ciBingoSize; i++) {
		for (int j = 0; j < ciBingoSize; j++) {
			if (false == iCheck[i][j]) {
				cout << iBoard[i][j] << '\t';
			}
			else {
				cout << 'x' << '\t';
			}
		}
		cout << endl;
	}
	cout << "현재까지 '" << iBingoCnt << "'빙고입니다." << endl;
}

POINT GetPointByInput(int iBoard[][ciBingoSize], bool iCheck[][ciBingoSize]) {
	POINT sPoint = { ERROR, ERROR };
	int iInput;
	while (true) {
		cout << "입력 :";
		// 사용자의 입력을 받는다.
		cin >> iInput;

		// 이미 체크한 곳인지를 판단한다.
		bool iOk = false;

		for (int i = 0; i < ciBingoSize && false == iOk; i++) {
			for (int j = 0; j < ciBingoSize && false == iOk; j++) {
				if (iInput == iBoard[i][j]) {
					if (false == iCheck[i][j]) {
						iCheck[i][j] = true;	// 새로이 체크하는 곳임을 표시
						sPoint.y = i, sPoint.x = j;			// 찾은 위치를 기입
						iOk = true;				// 찾았다고 표시
					}
				}
			}
		}
		// 올바른 입력을 받았으므로 반복문을 나가 다른 처리를 진행한다.
		if (true == iOk) break;
		else {
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl << endl;
			system("pause");
		}
	}

	// 올바른 입력이 위 과정에서 무조건 나오는 것을 전제로 한다.
	return sPoint;
}

bool IsValidIndex(int iY, int iX) {
	return  (0 <= iY && iY < ciBingoSize) && (0 <= iX && iX < ciBingoSize);
}

bool IsHorizontalBingo(bool iCheck[][ciBingoSize], int iY, int iX) {
	int iDynamicY, iDynamicX;
	// 2. 빙고 여부 확인
	// 1) 가로 방향 탐색
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// 좌측 가로줄 빙고 탐색
	while (IsValidIndex(iDynamicY, --iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// 우측 가로줄 빙고 탐색
	iDynamicY = iY, iDynamicX = iX;
	while (IsValidIndex(iDynamicY, ++iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	if (ciBingoSize == iCheckCnt) return true;
	return false;
}

bool IsVerticalBingo(bool iCheck[][ciBingoSize], int iY, int iX) {
	int iDynamicY, iDynamicX;
	// 2. 빙고 여부 확인
	// 1) 가로 방향 탐색
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// 위쪽 세로줄 빙고 탐색
	while (IsValidIndex(--iDynamicY, iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// 아래쪽 세로줄 빙고 탐색
	iDynamicY = iY, iDynamicX = iX;
	while (IsValidIndex(++iDynamicY, iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	if (ciBingoSize == iCheckCnt) return true;
	return false;
}

bool IsLeftTopBingo(bool iCheck[][ciBingoSize], int iY, int iX) {
	int iDynamicY, iDynamicX;
	// 2. 빙고 여부 확인
	// 1) 가로 방향 탐색
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// 좌상 대각줄 빙고 탐색
	while (IsValidIndex(--iDynamicY, --iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// 우하 대각줄 빙고 탐색
	iDynamicY = iY, iDynamicX = iX;
	while (IsValidIndex(++iDynamicY, ++iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	if (ciBingoSize == iCheckCnt) return true;
	return false;
}

bool IsRightTopBingo(bool iCheck[][ciBingoSize], int iY, int iX) {
	int iDynamicY, iDynamicX;
	// 2. 빙고 여부 확인
	// 1) 가로 방향 탐색
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// 우상 대각줄 빙고 탐색
	while (IsValidIndex(--iDynamicY, ++iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// 좌하 대각줄 빙고 탐색
	iDynamicY = iY, iDynamicX = iX;
	while (IsValidIndex(++iDynamicY, --iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	if (ciBingoSize == iCheckCnt) return true;
	return false;
}

void PrintResult(int iBingoCnt) {
	cout << "최종 '" << iBingoCnt << "'빙고입니다!" << endl;
	cout << "게임을 종료합니다." << endl;
}

void RunBingo(void) {
	int iBingoCnt = 0;
	int iBoard[ciBingoSize][ciBingoSize];
	bool iCheck[ciBingoSize][ciBingoSize];

	// 빙고를 하기전 변수들을 초기화한다.
	InitBoard(iBoard);
	InitCheck(iCheck);
	
	while (iBingoCnt < ciBingoSize) {
		system("cls");
		// 빙고 보드를 출력한다.
		PrintBingoBoard(iBoard, iCheck, iBingoCnt);

		// 1. 사용자 입력
		POINT sPoint = GetPointByInput(iBoard, iCheck);

		// 2. 빙고 여부 확인
		//		1) 가로 방향 탐색
		if (IsHorizontalBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "가로 빙고입니다! " << iBingoCnt << endl;
		}
		//		2) 세로 방향 탐색
		if (IsVerticalBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "세로 빙고입니다! " << iBingoCnt << endl;

		}
		//		3) 좌상대 방향 탐색
		if (IsLeftTopBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "(좌)대각선 빙고입니다! " << iBingoCnt << endl;
		}
		//		4) 우상대 방향 탐색
		if (IsRightTopBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "(우)대각선 빙고입니다! " << iBingoCnt << endl;
		}
		system("pause");
	}
	PrintResult(iBingoCnt);
}