#include<iostream>
using namespace std;

int dp[11];
//dp[N] : N�� 1,2,3�� ������ ��Ÿ���� ����� ��
//dp[0]�� 1�� ���ǵ� �� �ְڴ�. => �ƹ� ���� ������� �ʰ� 1�� ����� ���. �� ����.
int main(void) {
	dp[1] = 1;
	dp[2] = dp[2 - 1] + 1;
	dp[3] = dp[3 - 1] + dp[3 - 2] + 1;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	
	int t;
	cin >> t;

	int in;
	while (t--) {
		cin >> in;
		cout << dp[in] << '\n';
	}

	return 0;
}