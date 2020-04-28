#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[5][5];

int sol(int n, int m) {
	int e = 1 << (n * m);

	int ret = 0;
	int sum = 0;
	for (int k = 0; k < e; k++) {
		sum = 0;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp = 0;
			bool up = false;
			for (int j = 0; j < m; j++) {
				if ((k & (1 << (i * m + j))) == 0) {
					if (up) tmp *= 10;
					else up = true;
					tmp += arr[i][j];
				}
				else up = false;
			}
			sum += tmp;
		}
		for (int j = 0; j < m; j++) {
			tmp = 0;
			bool up = false;
			for (int i = 0; i < n; i++) {
				if ((k & (1 << (i * m + j))) != 0) {
					if (up) tmp *= 10;
					else up = true;
					tmp += arr[i][j];
				}
				else up = false;
			}
			sum += tmp;
		}
		ret = max(ret, sum);
	}
	return ret;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	cin.ignore();

	string row;
	for (int i = 0; i < n; i++) {
		getline(cin, row);
		for (int j = 0; j < m; j++) {
			arr[i][j] = row[j] - '0';
		}
	}

	cout << sol(n, m);

	return 0;
}