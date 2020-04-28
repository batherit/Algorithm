#include<iostream>
#include<string>
using namespace std;

char arr[15][15];
int res[15];

void prt(int e) {
	for (int i = 0; i < e; i++) {
		cout << res[i] << ' ';
	}
}

bool pss(int d) {
	int sum = 0;
	for (int i = d; i >= 0; i--) {
		sum += res[i];
		switch (arr[i][d])
		{
		case '+':
			if (sum <= 0) return false;
			break;
		case '-':
			if (sum >= 0) return false;
			break;
		case '0':
			if (sum != 0) return false;
			break;
		}
	}
	return true;
}

bool sol(int n, int d) {
	if (d == n) {
		prt(d);
		return true;
	}

	switch (arr[d][d]) {
	case '+':
		for (int i = 1; i <= 10; i++) {
			res[d] = i;
			if (pss(d)) {
				if (sol(n, d + 1)) {
					return true;
				}
			}
		}
		break;
	case '-':
		for (int i = -1; i >= -10; i--) {
			res[d] = i;
			if (pss(d)) {
				if (sol(n, d + 1)) {
					return true;
				}
			}
		}
		break;
	case '0':
		res[d] = 0;
		if (pss(d)) {
			if (sol(n, d + 1)) {
				return true;
			}
		}
		break;
	}
	return false;
}

int main(void) {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= i) {
				arr[i][j] = str[idx++];
			}
		}
	}

	sol(n, 0);

	return 0;
}