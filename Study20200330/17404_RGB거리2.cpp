#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	// r
	int res = 1000 * 1000 + 1;
	dp[1][0] = arr[1][0];
	dp[1][1] = 1000 * 1000 + 1;
	dp[1][2] = 1000 * 1000 + 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	res = min(res, min(dp[n][1], dp[n][2]));

	// g
	dp[1][0] = 1000 * 1000 + 1;
	dp[1][1] = arr[1][1];
	dp[1][2] = 1000 * 1000 + 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	res = min(res, min(dp[n][0], dp[n][2]));

	// b
	dp[1][0] = 1000 * 1000 + 1;
	dp[1][1] = 1000 * 1000 + 1;
	dp[1][2] = arr[1][2];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	res = min(res, min(dp[n][0], dp[n][1]));

	cout << res;

	return 0;
}