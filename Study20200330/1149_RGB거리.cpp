#include<iostream>
#include<algorithm>
using namespace std;

int cost[1001][3]; // cost[n][c] : n번 집에 대하여 c컬러 페인트 비용
int dp[1001][3]; // dp[n][c] : n번 집이 c컬러를 선택했을때 드는 최저 비용

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	
	for (int i = 1; i <= n; i++) {
		// 빨간색을 택했다고 가정.
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		// 초록색을 택했다고 가정.
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		// 파란색을 택했다고 가정.
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}