#include<iostream>
#include<algorithm>
using namespace std;

int arr[10];
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

	for (int i = s; i < n; i++) {
		res[d] = arr[i];
		sol(n, m, i + 1, d + 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	sol(n, m, 0, 0);

	return 0;
}