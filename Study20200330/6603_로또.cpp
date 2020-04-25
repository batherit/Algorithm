#include<iostream>
#include<algorithm>
using namespace std;

int chk[15];
int arr[15];

int main(void) {
	int t;
	while (true) {
		cin >> t;
		if (t == 0) break;
		for (int i = 0; i < t; i++) {
			if (i < 6) chk[i] = 0;
			else chk[i] = 1;
		}
		for (int i = 0; i < t; i++) {
			cin >> arr[i];
		}
		do {
			for (int i = 0; i < t; i++) {
				if (chk[i] == 0) cout << arr[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(chk, chk + t));
		cout << '\n';
	}

	return 0;
}
