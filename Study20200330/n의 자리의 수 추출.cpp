#include<iostream>
using namespace std;

// data의 n의 자리의 수(10의 배수)를 구한다.
int ext(int data, int n) {
	if (n != 1 && n % 10 != 0) {
		cout << "에러!" << endl;
		return -1;
	}

	return (data % (n * 10)) / n;
}

int ext2(int data, int n) {
	if (n != 1 && n % 10 != 0) {
		cout << "에러!" << endl;
		return -1;
	}

	int cnt = n / 10;
	while (cnt--) {
		data /= 10;
	}
	return data %= 10;
}

int main(void) {
	int iData, iN;
	cout << "Data의 N(10의 배수)의 자리의 수를 구하고자 합니다." << endl;
	cout << "Data와 N의 값을 입력해주세요. : ";
	cin >> iData >> iN;

	cout << "-----[결과]-----" << endl;
	cout << ext2(iData, iN);
	return 0;
}