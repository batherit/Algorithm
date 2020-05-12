#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];
int dp[10001];

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[2], max(arr[1] + arr[3], arr[2] + arr[3]));
	
	int m1, m2, m3;
	for (int i = 4; i <= n; i++) {
		m1 = arr[i - 1] + arr[i - 2] + dp[i - 4];	// ?xoox
		m2 = arr[i] + arr[i - 1] + dp[i - 3];		//  ?xoo
		m3 = arr[i] + dp[i - 2];					//   ?xo
		dp[i] = max(m1, max(m2, m3));
	}

	cout << dp[n];

	return 0;
}