#include<iostream>
#include<algorithm>
using namespace std;

int p[10001];

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> p[i];
		for (int j = 1; j < i; j++) {
			p[i] = max(p[i - j] + p[j], p[i]);
		}
	}
	cout << p[t];

	return 0;
}