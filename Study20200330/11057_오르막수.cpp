#include<iostream>
using namespace std;

// dp[p][n] : p로 끝난 n길이의 오르막수의 개수
int dp[10][1001]; 

int main(void) {
	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k >= 0; k--) {
				dp[j][i] += dp[k][i - 1] % 10007;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[i][n];
	}
	cout << sum % 10007;

	return 0;
}