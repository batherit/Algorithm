#include<iostream>
#include<algorithm>
using namespace std;

int arr[2][100001];
int dp[2][100001]; // dp[p][n] : p행 n열을 택했을 때의 점수 최댓값

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], max(dp[0][i - 2], dp[1][i - 2]));
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], max(dp[0][i - 2], dp[1][i - 2]));
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}

	return 0;
}