#include<iostream>
#include<algorithm>
using namespace std;

int cst[11][11];
int ord[11];

int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		ord[i] = i;
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			cin >> cst[i][j];
		}
	}

	int mn = 987654321;
	do {
		int sum = 0;
		int tmp = 0;
		for (int i = 0; i < t - 1; i++) {
			tmp = cst[ord[i]][ord[i + 1]];
			if (tmp != 0) {
				sum += tmp;
			} else break;
		}
		if (tmp == 0) continue;
		else {
			tmp = cst[ord[t - 1]][ord[0]];
			if (tmp != 0) {
				sum += tmp;
				if (sum < mn) {
					mn = sum;
				}
			}
			else break;
		}

	} while (next_permutation(ord + 1, ord + t));

	cout << mn;

	return 0;
}