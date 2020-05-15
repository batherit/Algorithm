#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[1001];
int dp[1001];

int sol(int st, int n) {
	memset(dp, 0, sizeof(dp));

	// st 왼쪽 가장 긴 증가 부분 수열을 찾는다.
	int r = 0;
	for (int i = 0; i <= st; i++) {
		dp[i] = 1;
		int mx = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				if (dp[j] > mx) {
					mx = dp[j];
				}
			}
		}
		dp[i] += mx;
		r = max(r, dp[i]);
	}

	// st 오른쪽 가장 긴 감소 부분 수열을 찾는다.
	int l = 0;
	for (int i = st; i <= n - 1; i++) {
		dp[i] = 1;
		int mx = 0;
		for (int j = i - 1; j >= st; j--) {
			if (arr[j] > arr[i]) {
				if (dp[j] > mx) {
					mx = dp[j];
				}
			}
		}
		dp[i] += mx;
		l = max(l, dp[i]);
	}

	return r + l - 1;
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, sol(i, n));
	}
	cout << res;

	return 0;
}