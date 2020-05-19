#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

// 고장 true, 정상 false
bool broken[11];

bool ok(int n) {
	string str = to_string(n);
	for (auto ch : str) {
		if (true == broken[ch - '0']) return false;
	}
	return true;
}

int sol(int n) {
	// 정상 버튼이 적어도 하나 이상 존재한다.
	int dir = n - 100;
	int r1 = 99, r2 = 1000000;
	if (dir == 0) return 0;
	else if (dir > 0) {
		for (int i = 100; i <= n; i++) {
			if (ok(i)) {
				r1 = i;
			}
		}
		for (int i = 999999; i >= n; i--) {
			if (ok(i)) {
				r2 = i;
			}
		}
	}
	else if (dir < 0) {
		for (int i = 100; i >= n; i--) {
			if (ok(i)) {
				r1 = i;
			}
		}
		for (int i = 0; i <= n; i++) {
			if (ok(i)) {
				r2 = i;
			}
		}
	}

	if (99 != r1 && n + 1 != r2) {
		return min(abs(n - r1) + to_string(r1).size(), abs(n - r2) + to_string(r2).size());
	}
	else if (99 != r1) {
		return abs(n - r1) + to_string(r1).size();
	}
	else if (n + 1 != r2) {
		return abs(n - r2) + to_string(r2).size();
	}
	else return 0;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	int in;
	for (int i = 0; i < m; i++) {
		cin >> in;
		broken[in] = true;
	}

	bool all_broken = true;
	for (int i = 1; i <= 10; i++) {
		if (!broken[i]) {
			all_broken = false;
			break;
		}
	}

	if (true == all_broken) cout << 0;
	else cout << sol(n);

	return 0;
}