#include<iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	int a, b;
	while (t--) {
		cin >> a >> b;
		int res = 1;
		for (int i = 0; i < b; i++) {
			res = (res * a - 1) % 10 + 1;
		}
		cout << res << '\n';
	}

	return 0;
}