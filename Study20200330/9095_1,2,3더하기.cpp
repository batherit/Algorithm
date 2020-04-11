#include<iostream>
using namespace std;

int dp[11];
//dp[N] : N을 1,2,3의 합으로 나타내는 방법의 수
//dp[0]은 1로 정의될 수 있겠다. => 아무 수도 사용하지 않고 1을 만드는 방법. 한 가지.
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