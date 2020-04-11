#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	// O(n^2)
	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) {
		for (int j = 1; i * j <= n; j++) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}