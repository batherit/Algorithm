#include<iostream>
using namespace std;

long long dp[101][10];
// dp[n][m] : 끝자리가 m인 길이가 n인 계단 수의 개수
int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) dp[i][j] += (dp[i - 1][j - 1] % 1000000000);
			if (j + 1 <= 9) dp[i][j] += (dp[i - 1][j + 1] % 1000000000);
		}
	}

	long long sum = 0;

	for (int i = 1; i <= 9; i++) {
		sum += (dp[t][i] % 1000000000);
	}

	cout << sum % 1000000000;

	return 0;
}