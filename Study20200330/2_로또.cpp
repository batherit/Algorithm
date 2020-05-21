// 2. �ζ� ���� (1���� �迭�� �̿�, 1~45������ ���� ������ 6��, �� 5ȸ�� ����, �ߺ� x, �������� ����-�����Ʈ)
/*
���� 2. �ζ� �����ؿ���
1���� �迭�� �̿��Ͽ� 1~45������ ���� �������� 6��.
��5ȸ���� �����Ͽ� ����ϱ�.
�� ȸ���� �ߺ���ȣ ����� �ϰ� �������� ������ �Ǿ�� �Ѵ�.
*/

#include<iostream>
#include<ctime>
using namespace std;

const int ciLottoCount = 5;					// �ζǸ� �� �� ������ ������?
const int ciCandidateLottoSize = 45;		// �ζ� �ĺ� �� �ִ� // �ּڰ��� 1
const int ciLottoSizeToSelect = 6;			// �� ���� �ζ� ��ȣ�� ���� ������? 
											// ��ciCandidateLottoSize���� �۰ų� ����.

void PrintCurrentCount(int iCount);
void InitNumberArray(int iNumArr[]);
void SetLottoNumber(int iNumArr[], int iLottoNumArr[]);
void Swap(int* iNum1, int* iNum2);
void BubbleSort(int iArr[], int iSize, int iOffset = 0);
void PrintResult(int iLottoNumArr[]);
void RunLotto(void);

int main(void) {
	RunLotto();

	return 0;
}









// ������ ȸ���� ����Ѵ�.
void PrintCurrentCount(int iCount) {
	cout << '[' << ciLottoCount - iCount << "ȸ��] : ";
}

// �ζ� ��ȣ�� �� �ζ� �ĺ� ������ �ʱ�ȭ�Ѵ�.
void InitNumberArray(int iNumArr[]) {
	iNumArr[0] = 0;
	iNumArr[ciCandidateLottoSize + 1] = 0;
	for (int i = 1; i <= ciCandidateLottoSize; i++) {
		iNumArr[i] = i;
	}
}

// �ζ� �ĺ� ���鿡�� 6���� �ζ� ��ȣ ������ �����Ѵ�.
void SetLottoNumber(int iNumArr[], int iLottoNumArr[]) {
	int iSelectedIndex = -1;
	for (int i = 0; i < ciLottoSizeToSelect; i++) {
		// �ζ� �ĺ� �� �߿��� �������� �ϳ� �̴���.
		iSelectedIndex = rand() % (ciCandidateLottoSize - i) + 1;

		// �ζ� ��ȣ �迭�� �����Ѵ�.
		iLottoNumArr[i] = iNumArr[iSelectedIndex];

		/*for (int j = iSelectedIndex; iNumArr[j + 1] != 0; j++) {
			iNumArr[j] = iNumArr[j + 1];
		}*/

		// ���� ���� �ζ� �ĺ� ������ �����Ѵ�.
		for (int j = iSelectedIndex; j <= ciCandidateLottoSize; j++) {
			// iSelectedIndex���� ������ ������ �����Ѵ�.
			iNumArr[j] = iNumArr[j + 1];
		}
	}
}

// �� ���� �����Ѵ�
void Swap(int* iNum1, int* iNum2) {
	int iTemp = *iNum1;
	*iNum1 = *iNum2;
	*iNum2 = iTemp;
}

// ���� ��Ʈ�� �����Ѵ�.
void BubbleSort(int iArr[], int iSize, int iOffset /*= 0*/) {
	for (int i = 0; i < iSize - 1; i++) {
		for (int j = 0 + iOffset; j < iSize - 1 - i + iOffset; j++) {
			if (iArr[j] > iArr[j + 1]) {
				Swap(&iArr[j], &iArr[j + 1]);
			}
		}
	}
}

// �ζ� ����� ����Ѵ�.
void PrintResult(int iLottoNumArr[]) {
	for (int i = 0; i < ciLottoSizeToSelect; i++) {
		cout << iLottoNumArr[i] << '\t';
	}
}

// �ζ� ���α׷��� �����Ѵ�.
void RunLotto(void) {
	srand((unsigned int)time(nullptr));

	int iCount = ciLottoCount;
	int iNumArr[ciCandidateLottoSize + 10];
	int iSelectedNumArr[ciLottoSizeToSelect];

	// �ʱ� iCount��ŭ ȸ���� �����Ѵ�.
	while (iCount--) {
		// ȸ���� ����Ѵ�.
		PrintCurrentCount(iCount);

		// �ζ� �ĺ� �� �ʱ�ȭ
		InitNumberArray(iNumArr);

		// 6�� �̱�
		SetLottoNumber(iNumArr, iSelectedNumArr);

		// �������� �����ϱ�
		BubbleSort(iSelectedNumArr, sizeof(iSelectedNumArr) / sizeof(int));

		// ����ϱ�
		PrintResult(iSelectedNumArr);
		cout << endl;
	}
}