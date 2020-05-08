#include<iostream>
using namespace std;

long long dp[1000001];

int main(void) {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	int n;
	while (t--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			if (dp[i] == 0) {
				dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
			}
		}
		cout << dp[n] << '\n';
	}

	return 0;
}