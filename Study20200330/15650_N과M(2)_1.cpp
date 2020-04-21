#include<iostream>
using namespace std;

int res[10];

void prt(int e) {
	for (int i = 0; i < e; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

void sol(int n, int m, int i, int c) {
	if (c == m) {
		prt(c);
		return;
	}

	if (i > n) return;

	res[c] = i;
	sol(n, m, i + 1, c + 1);	// 추가한다.
	sol(n, m, i + 1, c);		// 제외한다.
}

int main(void) {
	int n, m;
	cin >> n >> m;

	sol(n, m, 1, 0);

	return 0;
}