#include<iostream>
using namespace std;

long long dp[100001][4];
//dp[n][m] : n을 만드는 방법의 수, m은 마지막으로 사용한 수

int main(void) {
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= 100000; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j - 1 >= 1) dp[i][j] += (dp[i - j][j - 1]	% 1000000009);
			else if(i - j) dp[i][j] += (dp[i - j][3]		% 1000000009);
			if (j + 1 <= 3) dp[i][j] += (dp[i - j][j + 1]	% 1000000009);
			else dp[i][j] += (dp[i - j][1]					% 1000000009);
			//dp[i][j] %= 1000000009;
		}
	}

	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
	}

	return 0;
}