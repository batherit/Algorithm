#include<iostream>
using namespace std;

int res[10];

void prt(int e) {
	for (int i = 0; i < e; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

void sol(int n, int m, int s, int d) {
	if (d == m) {
		prt(d);
		return;
	}

	for (int i = s; i <= n; i++) {
		res[d] = i;
		sol(n, m, i, d + 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	sol(n, m, 1, 0);

	return 0;
}