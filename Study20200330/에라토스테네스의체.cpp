#include<iostream>
using namespace std;

int prime[100];		// �Ҽ� ����
int pn = 0;			// �Ҽ��� ����
bool check[101];	// ���������� true
int n = 100;		// 100���� �Ҽ�

// O(NloglogN)
int main(void) {
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			// j = i * i���� i�� �鸸�̸� i * i�� 1���� �Ǳ� ������, int�� ó���� ���ϴ� ��찡 �����Ѵ�.
			// ����, i * 2�� �ٲٴ� ���� ����.
			for (int j = i * i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}

	return 0;
}