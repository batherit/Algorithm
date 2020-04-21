#include<iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	int M, N, x, y;
	while (t--) {
		cin >> M >> N >> x >> y;

		// x를 처음 값으로 잡는다.
		int cnt = 0;
		for (int i = x; cnt < N; cnt++, i += M) {
			if ((i - 1) % M + 1 == x && (i - 1) % N + 1 == y) {
				cout << i << '\n';
				break;
			}
		}

		if (cnt == N) cout << -1 << '\n';
	}

	return 0;
}