#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
	int n;
	cin >> n;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		int mx = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] > arr[i]) {
				if (dp[j] > mx) {
					mx = dp[j];
				}
			}
		}
		dp[i] += mx;
		res = max(res, dp[i]);
	}

	cout << res;

	return 0;
}