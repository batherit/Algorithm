#include<iostream>
using namespace std;

int main(void) {
	/*int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int i5 = 0;
	int i6 = 0;

	cout << dec << &i1 - &i2 << endl;
	cout << dec << &i2 - &i3 << endl;
	cout << dec << &i3 - &i4 << endl;
	cout << dec << &i4 - &i5 << endl;
	cout << dec << &i5 - &i6 << endl;*/
	//cout << dec << &i6 << endl;

	int iArr[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	int iN;
	cin >> iN;

	cout << iArr[iN / 6][iN % 6] << endl;
	cout << (*(iArr + 1))[1] << endl;
	cout << *(*(iArr + 2) - 2) << endl;
	cout << *(*(iArr + 4) - 8) << endl;

	return 0;
}

// 1. 1���� �迭�� ��ġ 2���� �迭ó�� �ٷ�� (25��¥�� �迭 ����, 2�� for��)
// 2. �ζ� ���� (1���� �迭�� �̿�, 1~45������ ���� ������ 6��, �� 5ȸ�� ����, �ߺ� x, �������� ����-�����Ʈ)