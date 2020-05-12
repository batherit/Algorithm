#include<iostream>
using namespace std;

int N;
int dp[3][100001];

int sol(int c, int depth = 0) {
	if (depth == N - 1) return 1;
	if (dp[c][depth] != 0) return dp[c][depth];

	int ret = 0;
	switch (c)
	{
	case 0:
		ret = sol(0, depth + 1) + sol(1, depth + 1) + sol(2, depth + 1);
		break;
	case 1:
		ret = sol(0, depth + 1) + sol(2, depth + 1);
		break;
	case 2:
		ret = sol(0, depth + 1) + sol(1, depth + 1);
		break;
	}
	return  dp[c][depth] = ret % 9901;
}

int main(void) {
	cin >> N;

	int case_num = 0;
	for (int i = 0; i < 3; i++) {
		case_num += sol(i);
	}

	cout << case_num % 9901;

	return 0;
}