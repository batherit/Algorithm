#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000001];

// dp[N] : N을 1로 만드는 최소 연산 횟수
int main(void) {
	int t;
	cin >> t;
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int m;
	for (int i = 4; i <= t; i++) {
		dp[i] = 987654321;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[t];
	
	return 0;
}