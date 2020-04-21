#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int res[10];

void ptr(int e) {
	for (int i = 0; i < e; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

void sol(int m, int d) {
	if (d == m) {
		ptr(d);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		res[d] = v[i];
		sol(m, d + 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << v.size() << '\n';

	sol(m, 0);

	return 0;
}