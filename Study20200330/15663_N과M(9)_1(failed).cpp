#include<iostream>
#include<algorithm>
using namespace std;

int chk[10];
int arr[10];

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (i < m) chk[i] = 1;
		else chk[i] = 0;
	}

	do {
		for (int i = 0; i < n; i++) {
			if (chk[i] == 1) cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (prev_permutation(chk, chk + n));

	return 0;
}