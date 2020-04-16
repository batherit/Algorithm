#include<iostream>
using namespace std;

int ar[1001];
int dp[1001];

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> ar[i];
	}

	int mx;
	int result = 0;
	for (int i = 1; i <= t; i++) {
		dp[i] = 1;
		mx = 0;
		for (int j = i - 1; j > 0; j--) {
			if (dp[j] > mx && ar[j] < ar[i]) {
				mx = dp[j];
			}
		}
		dp[i] += mx;
		if (dp[i] > result) result = dp[i];
	}

	cout << result;

	return 0;
}