#include<iostream>
using namespace std;

int dp[1001];
//dp[N] : 2xn ũ���� ���簢���� ä��� ����� ��
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