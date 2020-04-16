#include<iostream>
using namespace std;

int ar[100001];
int dp[100001];
// dp[n] : n까지의 수 중 가장 큰 연속합 (n - 1까지 유효)

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> ar[i];
	}

	int mx = ar[1];
	dp[1] = ar[1];
	for (int i = 2; i <= t; i++) {
		if (ar[i] < dp[i - 1] + ar[i]) {
			// 연속하는게 더 낫다면,
			dp[i] = dp[i - 1] + ar[i];
		}
		else {
			dp[i] = ar[i];
		}
		if (dp[i] > mx) mx = dp[i];
	}

	cout << mx;

	return 0;
}