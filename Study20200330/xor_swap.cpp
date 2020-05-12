#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(void) {
	int iA, iB;
	cout << "두 개의 값을 입력하세요 : ";
	cin >> iA >> iB;

	swap(iA, iB);

	cout << "-----스왑 결과-----" << endl;
	cout << iA << ' ' << iB;

	return 0;
}