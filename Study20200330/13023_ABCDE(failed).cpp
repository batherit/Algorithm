#include<iostream>
#include<vector>
using namespace std;

bool arr[2001][2001];

int sol(int v, int s, int d) {
	if (d == v) {
		return 1;
	}

	for (int i = s + 1; i < v; i++) {
		if (arr[s][i]) {
			// 기준 s가 i와 친구인 경우,
			if (sol(v, i, d + 1) == 1) return 1;
		}
	}
	return 0;
}

int main(void) {
	int v, e;
	cin >> v >> e;
	
	int f1, f2;
	for (int i = 0; i < e; i++) {
		cin >> f1 >> f2;
		arr[f1][f2] = true;
		arr[f2][f1] = true;
	}
	
	cout << sol(v, 0, 0);

	return 0;
}