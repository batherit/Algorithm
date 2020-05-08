#include<iostream>
using namespace std;

long long dp[201][201];
//dp[n][k] : 0에서 n까지의 n + 1개의 정수 중
//k개를 뽑아 n이라는 정수를 만드는 경우의 수
// O(kn^2)

int main(void) {
	int n, k;
	cin >> n >> k;

	// dp[n][k] = 시그마 dp[n - i][k - 1];
	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
		for (int j = 1; j <= k; j++) {
			for (int r = 0; r <= i; r++) {
				dp[i][j] += (dp[i - r][j - 1] % 1000000000);
			}
			dp[i][j] %= 1000000000;
		}
	}
	cout << dp[n][k];
	return 0;
}