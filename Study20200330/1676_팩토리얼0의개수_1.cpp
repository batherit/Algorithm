#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	// O(n)
	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	cout << cnt;

	return 0;
}