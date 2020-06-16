#include<iostream>
using namespace std;

// data�� n�� �ڸ��� ��(10�� ���)�� ���Ѵ�.
int ext(int data, int n) {
	if (n != 1 && n % 10 != 0) {
		cout << "����!" << endl;
		return -1;
	}

	return (data % (n * 10)) / n;
}

int ext2(int data, int n) {
	if (n != 1 && n % 10 != 0) {
		cout << "����!" << endl;
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
	cout << "Data�� N(10�� ���)�� �ڸ��� ���� ���ϰ��� �մϴ�." << endl;
	cout << "Data�� N�� ���� �Է����ּ���. : ";
	cin >> iData >> iN;

	cout << "-----[���]-----" << endl;
	cout << ext2(iData, iN);
	return 0;
}