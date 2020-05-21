// 2. 로또 구현 (1차원 배열을 이용, 1~45까지의 수를 무작위 6개, 총 5회차 추출, 중복 x, 오름차순 정렬-버블소트)
/*
숙제 2. 로또 구현해오기
1차원 배열을 이용하여 1~45까지의 수를 무작위로 6개.
총5회차를 추출하여 출력하기.
각 회차당 중복번호 없어야 하고 오름차순 정렬이 되어야 한다.
*/

#include<iostream>
#include<ctime>
using namespace std;

const int ciLottoCount = 5;					// 로또를 몇 번 진행할 것인지?
const int ciCandidateLottoSize = 45;		// 로또 후보 수 최댓값 // 최솟값은 1
const int ciLottoSizeToSelect = 6;			// 몇 개의 로또 번호를 뽑을 것인지? 
											// ㄴciCandidateLottoSize보다 작거나 같다.

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









// 현재의 회차를 출력한다.
void PrintCurrentCount(int iCount) {
	cout << '[' << ciLottoCount - iCount << "회차] : ";
}

// 로또 번호가 될 로또 후보 수들을 초기화한다.
void InitNumberArray(int iNumArr[]) {
	iNumArr[0] = 0;
	iNumArr[ciCandidateLottoSize + 1] = 0;
	for (int i = 1; i <= ciCandidateLottoSize; i++) {
		iNumArr[i] = i;
	}
}

// 로또 후보 수들에서 6개의 로또 번호 수들을 세팅한다.
void SetLottoNumber(int iNumArr[], int iLottoNumArr[]) {
	int iSelectedIndex = -1;
	for (int i = 0; i < ciLottoSizeToSelect; i++) {
		// 로또 후보 수 중에서 무작위로 하나 뽑느다.
		iSelectedIndex = rand() % (ciCandidateLottoSize - i) + 1;

		// 로또 번호 배열에 저장한다.
		iLottoNumArr[i] = iNumArr[iSelectedIndex];

		/*for (int j = iSelectedIndex; iNumArr[j + 1] != 0; j++) {
			iNumArr[j] = iNumArr[j + 1];
		}*/

		// 뽑힌 수는 로또 후보 수에서 제거한다.
		for (int j = iSelectedIndex; j <= ciCandidateLottoSize; j++) {
			// iSelectedIndex부터 덮어씌우는 과정을 진행한다.
			iNumArr[j] = iNumArr[j + 1];
		}
	}
}

// 두 수를 스왑한다
void Swap(int* iNum1, int* iNum2) {
	int iTemp = *iNum1;
	*iNum1 = *iNum2;
	*iNum2 = iTemp;
}

// 버블 소트를 진행한다.
void BubbleSort(int iArr[], int iSize, int iOffset /*= 0*/) {
	for (int i = 0; i < iSize - 1; i++) {
		for (int j = 0 + iOffset; j < iSize - 1 - i + iOffset; j++) {
			if (iArr[j] > iArr[j + 1]) {
				Swap(&iArr[j], &iArr[j + 1]);
			}
		}
	}
}

// 로또 결과를 출력한다.
void PrintResult(int iLottoNumArr[]) {
	for (int i = 0; i < ciLottoSizeToSelect; i++) {
		cout << iLottoNumArr[i] << '\t';
	}
}

// 로또 프로그램을 실행한다.
void RunLotto(void) {
	srand((unsigned int)time(nullptr));

	int iCount = ciLottoCount;
	int iNumArr[ciCandidateLottoSize + 10];
	int iSelectedNumArr[ciLottoSizeToSelect];

	// 초기 iCount만큼 회차를 진행한다.
	while (iCount--) {
		// 회수를 출력한다.
		PrintCurrentCount(iCount);

		// 로또 후보 수 초기화
		InitNumberArray(iNumArr);

		// 6개 뽑기
		SetLottoNumber(iNumArr, iSelectedNumArr);

		// 오름차순 정렬하기
		BubbleSort(iSelectedNumArr, sizeof(iSelectedNumArr) / sizeof(int));

		// 출력하기
		PrintResult(iSelectedNumArr);
		cout << endl;
	}
}