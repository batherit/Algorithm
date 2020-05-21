#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

// ���� true, ���� false
bool broken[11];

bool ok(int n) {
	string str = to_string(n);
	for (auto ch : str) {
		if (true == broken[ch - '0']) return false;
	}
	return true;
}

// n : ������ �ϴ� ä��
// r : ���� ��ư���θ� ������ ���� ��ư ����
int sub(int n, int r) {
	// nä���� 100���� ������ ����
	// �ִ� + or -�� ���Ƚ��
	int dist = abs(n - 100);
	int res = abs(n - r) + to_string(r).size();

	return min(dist, res);
}

int sol(int n) {
	// ���� ��ư�� ��� �ϳ� �̻� �����Ѵ�.
	int dir = n - 100;
	int r1 = -1, r2 = 1000001;
	if (dir == 0) return 0;
	else if (dir > 0) {
		for (int i = 100; i <= n; i++) {
			if (ok(i)) {
				r1 = i;
			}
		}
		for (int i = 1000001; i >= n; i--) {
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

	if (-1 != r1 && 1000001 != r2)	return min(sub(n, r1), sub(n, r2));
	else if (-1 != r1)				return sub(n, r1);
	else if (1000001 != r2)			return sub(n, r2);
	else							return abs(n - 100);
}

int main(void) {
	int n, m;
	cin >> n >> m;

	int in;
	for (int i = 0; i < m; i++) {
		cin >> in;
		broken[in] = true;
	}

	cout << sol(n);

	return 0;
}