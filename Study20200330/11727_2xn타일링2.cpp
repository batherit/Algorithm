#include<iostream>
using namespace std;

int dp[1001];

int main(void) {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 3; // dp[2 - 1] + 2 (2를 채우는 고유 방식)

	for (int i = 3; i <= t; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	cout << dp[t];

	return 0;
}