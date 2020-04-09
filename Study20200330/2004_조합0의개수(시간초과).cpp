//nCr = n! / (r!(n - r)!)
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	int cnt_t_2 = 0, cnt_t_5 = 0;
	int cnt_b_2 = 0, cnt_b_5 = 0;

	for (int i = 2; i <= n; i *= 2) {
		for (int j = 1; i * j <= n; j++) {
			cnt_t_2++;
		}
	}
	for (int i = 5; i <= n; i *= 5) {
		for (int j = 1; i * j <= n; j++) {
			cnt_t_5++;
		}
	}

	for (int i = 2; i <= m; i *= 2) {
		for (int j = 1; i * j <= m; j++) {
			cnt_b_2++;
		}
	}
	for (int i = 5; i <= m; i *= 5) {
		for (int j = 1; i * j <= m; j++) {
			cnt_b_5++;
		}
	}

	for (int i = 2; i <= n-m; i *= 2) {
		for (int j = 1; i * j <= n-m; j++) {
			cnt_b_2++;
		}
	}
	for (int i = 5; i <= n-m; i *= 5) {
		for (int j = 1; i * j <= n-m; j++) {
			cnt_b_5++;
		}
	}

	cout << max(0, min(cnt_t_2 - cnt_b_2, cnt_t_5 - cnt_b_5));

	return 0;
}