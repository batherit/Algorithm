// O(n root n)
#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001];
// dp[n] : n�� ǥ���ϴµ� �ʿ��� �������� �ּ� ����

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i * i <= t; i++) {
		dp[i * i] = 1;
	}

	for (int i = 2; i <= t; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			// �� ������ ���� j * j�� ������ �ּ� �׼��� ���Ѵ�.
			dp[i] = min(dp[i - j * j], dp[i]);
		}
		dp[i] += 1;
	}

	cout << dp[t];

	return 0;
}