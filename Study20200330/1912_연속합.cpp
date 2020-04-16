#include<iostream>
using namespace std;

int ar[100001];
int dp[100001];
// dp[n] : n������ �� �� ���� ū ������ (n - 1���� ��ȿ)

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
			// �����ϴ°� �� ���ٸ�,
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