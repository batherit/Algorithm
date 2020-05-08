// O(n root n)
#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001];
// dp[n] : n을 표현하는데 필요한 제곱수의 최소 개수

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i * i <= t; i++) {
		dp[i * i] = 1;
	}

	for (int i = 2; i <= t; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			// 맨 마지막 항을 j * j로 가정시 최소 항수를 구한다.
			dp[i] = min(dp[i - j * j], dp[i]);
		}
		dp[i] += 1;
	}

	cout << dp[t];

	return 0;
}