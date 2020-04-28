#include<iostream>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	int len = n * m;

	int cnt = 0;
	while (true) {
		len -= n; if (len == 0) break;
		n -= 1;
		cnt++;
		len -= m; if (len == 0) break;
		m -= 1;
		cnt++;
	}
	cout << cnt;

	return 0;
}