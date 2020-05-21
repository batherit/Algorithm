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
	cout << "������� '" << iBingoCnt << "'�����Դϴ�." << endl;
}

POINT GetPointByInput(int iBoard[][ciBingoSize], bool iCheck[][ciBingoSize]) {
	POINT sPoint = { ERROR, ERROR };
	int iInput;
	while (true) {
		cout << "�Է� :";
		// ������� �Է��� �޴´�.
		cin >> iInput;

		// �̹� üũ�� �������� �Ǵ��Ѵ�.
		bool iOk = false;

		for (int i = 0; i < ciBingoSize && false == iOk; i++) {
			for (int j = 0; j < ciBingoSize && false == iOk; j++) {
				if (iInput == iBoard[i][j]) {
					if (false == iCheck[i][j]) {
						iCheck[i][j] = true;	// ������ üũ�ϴ� ������ ǥ��
						sPoint.y = i, sPoint.x = j;			// ã�� ��ġ�� ����
						iOk = true;				// ã�Ҵٰ� ǥ��
					}
				}
			}
		}
		// �ùٸ� �Է��� �޾����Ƿ� �ݺ����� ���� �ٸ� ó���� �����Ѵ�.
		if (true == iOk) break;
		else {
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl << endl;
			system("pause");
		}
	}

	// �ùٸ� �Է��� �� �������� ������ ������ ���� ������ �Ѵ�.
	return sPoint;
}

bool IsValidIndex(int iY, int iX) {
	return  (0 <= iY && iY < ciBingoSize) && (0 <= iX && iX < ciBingoSize);
}

bool IsHorizontalBingo(bool iCheck[][ciBingoSize], int iY, int iX) {
	int iDynamicY, iDynamicX;
	// 2. ���� ���� Ȯ��
	// 1) ���� ���� Ž��
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// ���� ������ ���� Ž��
	while (IsValidIndex(iDynamicY, --iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// ���� ������ ���� Ž��
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
	// 2. ���� ���� Ȯ��
	// 1) ���� ���� Ž��
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// ���� ������ ���� Ž��
	while (IsValidIndex(--iDynamicY, iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// �Ʒ��� ������ ���� Ž��
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
	// 2. ���� ���� Ȯ��
	// 1) ���� ���� Ž��
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// �»� �밢�� ���� Ž��
	while (IsValidIndex(--iDynamicY, --iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// ���� �밢�� ���� Ž��
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
	// 2. ���� ���� Ȯ��
	// 1) ���� ���� Ž��
	int iCheckCnt = 1;
	iDynamicY = iY, iDynamicX = iX;
	// ��� �밢�� ���� Ž��
	while (IsValidIndex(--iDynamicY, ++iDynamicX)) {
		if (true == iCheck[iDynamicY][iDynamicX]) {
			iCheckCnt++;
		}
	}
	// ���� �밢�� ���� Ž��
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
	cout << "���� '" << iBingoCnt << "'�����Դϴ�!" << endl;
	cout << "������ �����մϴ�." << endl;
}

void RunBingo(void) {
	int iBingoCnt = 0;
	int iBoard[ciBingoSize][ciBingoSize];
	bool iCheck[ciBingoSize][ciBingoSize];

	// ���� �ϱ��� �������� �ʱ�ȭ�Ѵ�.
	InitBoard(iBoard);
	InitCheck(iCheck);
	
	while (iBingoCnt < ciBingoSize) {
		system("cls");
		// ���� ���带 ����Ѵ�.
		PrintBingoBoard(iBoard, iCheck, iBingoCnt);

		// 1. ����� �Է�
		POINT sPoint = GetPointByInput(iBoard, iCheck);

		// 2. ���� ���� Ȯ��
		//		1) ���� ���� Ž��
		if (IsHorizontalBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "���� �����Դϴ�! " << iBingoCnt << endl;
		}
		//		2) ���� ���� Ž��
		if (IsVerticalBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "���� �����Դϴ�! " << iBingoCnt << endl;

		}
		//		3) �»�� ���� Ž��
		if (IsLeftTopBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "(��)�밢�� �����Դϴ�! " << iBingoCnt << endl;
		}
		//		4) ���� ���� Ž��
		if (IsRightTopBingo(iCheck, sPoint.y, sPoint.x)) {
			iBingoCnt++;
			cout << "(��)�밢�� �����Դϴ�! " << iBingoCnt << endl;
		}
		system("pause");
	}
	PrintResult(iBingoCnt);
}