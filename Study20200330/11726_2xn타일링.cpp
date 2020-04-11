#include<iostream>
using namespace std;

int dp[1001];
//dp[N] : 2xn 크기의 직사각형을 채우는 방법의 수
int main(void) {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= t; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[t];

	return 0;
}