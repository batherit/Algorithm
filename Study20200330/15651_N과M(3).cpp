#include<iostream>
using namespace std;

int res[10];

void prt(int e) {
	for (int i = 0; i < e; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

void sol(int n, int m, int d) {
	if (d == m) {
		prt(d);
		return;
	}

	for (int i = 1; i <= n; i++) {
		res[d] = i;
		sol(n, m, d + 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	sol(n, m, 0);

	return 0;
}