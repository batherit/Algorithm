#include<iostream>
using namespace std;

int sol(int n) {
	int ret = 0;
	int s, e;
	int c = 1;
	for (s = 1; s <= n; s *= 10, c++) {
		e = s * 10;
		if (e > n) e = n + 1;
		ret += (e - s) * c;
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	cout << sol(n);

	return 0;
}