#include<iostream>
#include<algorithm>
using namespace std;

int RGB[2][3];
int N;

int main(void) {
	cin >> N;
	cin >> RGB[0][0] >> RGB[0][1] >> RGB[0][2];
	int i;
	for (i = 1; i < N; i++) {
		cin >> RGB[i % 2][0] >> RGB[i % 2][1] >> RGB[i % 2][2];
		for (int j = 0; j < 3; j++) {
			RGB[i % 2][j] += min(
				RGB[(i - 1) % 2][(j + 1) % 3],
				RGB[(i - 1) % 2][(j + 2) % 3]);
		}
	}

	int minCost;
	int lastIdx = (i - 1) % 2;
	minCost = min(RGB[lastIdx][0], RGB[lastIdx][1]);
	minCost = min(minCost, RGB[lastIdx][2]);

	cout << minCost << endl;

	return 0;
}