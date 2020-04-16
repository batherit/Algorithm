#include<iostream>
using namespace std;

int dp[100001];
// dp[n] : n을 표현하는데 필요한 제곱수의 최소 개수

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i * i <= t; i++) {
		dp[i * i] = 1;
	}

	int mn;
	int temp;
	int result = 987654321;
	for (int i = 1; i * i <= t; i++) {
		mn = 987654321;
		for (int j = 1; j * j <= i; j++) {
			if (t - i * i == j * j) {
				if (dp[j * j] > 0 && dp[j * j] < mn) {
					mn = dp[j * j];
				}
			}
		}
		dp[i * i] += mn;
		if (dp[i * i] < result) result = dp[i * i];
	}

	cout << result;

	return 0;
}