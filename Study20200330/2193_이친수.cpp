#include<iostream>
using namespace std;

long long dp[100][2];
// dp[n][m] ���� m���� ������ n�ڸ� ��ģ���� ����

int main(void) {
	int t;
	cin >> t;

	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= t; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[t][0] + dp[t][1];

	return 0;
}