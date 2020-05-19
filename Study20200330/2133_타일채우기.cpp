#include<iostream>
using namespace std;

int tile[31];

int main(void) {
	int n;
	cin >> n;

	tile[2] = 3;
	tile[4] = 3 * tile[2] + 2;

	int temp = 2;
	for (int i = 6; i < 31; i += 2) {
		temp += 2 * tile[i - 4];
		tile[i] += (3 * tile[i - 2] + temp);
	}

	cout << tile[n] << endl;

	return 0;
}