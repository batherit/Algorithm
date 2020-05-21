#include<iostream>
using namespace std;

int cnt_p[1000001];
int cnt_m[1000001];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in >= 0) {
			cnt_p[in]++;
		}
		else {
			cnt_m[-in]++;
		}
	}

	// 음수 출력
	for (int i = 1000000; i > 0; i--) {
		if (0 != cnt_m[i]) {
			for (int j = 0; j < cnt_m[i]; j++) {
				cout << -i << '\n';
			}
		}
	}

	// 양수 출력
	for (int i = 0; i <= 1000000; i++) {
		if (0 != cnt_p[i]) {
			for (int j = 0; j < cnt_p[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}