#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(void) {
	int iA, iB;
	cout << "�� ���� ���� �Է��ϼ��� : ";
	cin >> iA >> iB;

	swap(iA, iB);

	cout << "-----���� ���-----" << endl;
	cout << iA << ' ' << iB;

	return 0;
}