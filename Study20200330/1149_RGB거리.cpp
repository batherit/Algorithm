#include<iostream>
#include<algorithm>
using namespace std;

int cost[1001][3]; // cost[n][c] : n�� ���� ���Ͽ� c�÷� ����Ʈ ���
int dp[1001][3]; // dp[n][c] : n�� ���� c�÷��� ���������� ��� ���� ���

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	
	for (int i = 1; i <= n; i++) {
		// �������� ���ߴٰ� ����.
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		// �ʷϻ��� ���ߴٰ� ����.
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		// �Ķ����� ���ߴٰ� ����.
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}