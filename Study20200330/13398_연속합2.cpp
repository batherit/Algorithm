#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int dp_l[100001];
int dp_r[100002];

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp_l[1] = arr[1];
	int mx1 = arr[1];
	for (int i = 2; i <= n; i++) {
		if (arr[i] < arr[i] + dp_l[i - 1]) {
			dp_l[i] = arr[i] + dp_l[i - 1];
		}
		else {
			dp_l[i] = arr[i];
		}
		// 제거가 없다는 가정하 가장 큰 연속합 mx1을 찾는다.
		mx1 = max(mx1, dp_l[i]);
	}

	dp_r[n] = arr[n];
	for (int i = n - 1; i >= 1; i--) {
		if (arr[i] < arr[i] + dp_r[i + 1]) {
			dp_r[i] = arr[i] + dp_r[i + 1];
		}
		else {
			dp_r[i] = arr[i];
		}
	}

	int mx2 = -987654321;
	dp_l[0] = -987654321;
	dp_r[100001] = -987654321;
	for (int i = 1; i <= n; i++) {
		mx2 = max(mx2, dp_l[i - 1] + dp_r[i + 1]);
	}

	cout << max(mx1, mx2);

	return 0;
}