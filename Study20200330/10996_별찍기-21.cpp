#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int r = 0; r < 2; r++) {
			if (r == 0) {
				for (int j = 0; j < n / 2 + (n % 2 == 0 ? 0 : 1); j++) {
					cout << '*' << ' ';
				}
			}
			else if (r == 1) {
				cout << ' ';
				for (int j = 0; j < n / 2; j++) {
					cout << '*' << ' ';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}