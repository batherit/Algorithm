#include<iostream>
using namespace std;

int arr[1000][1000];

int turn[4] = { 1, 1, 2, 2 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0};

int main(void) {
	int n, m;
	cin >> n >> m;

	int dir = 0;
	int x, y;
	int ret_x, ret_y;
	x = y = n / 2;

	int go = 0;
	for (int i = 1; i <= n * n; i++) {
		if (go == turn[dir]) {
			turn[dir] += 2;
			dir = (dir + 1) % 4;
			go = 0;
		}
		if (i == m) {
			ret_x = x;
			ret_y = y;
		}
		arr[y][x] = i;
		y += dy[dir];
		x += dx[dir];
		go++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ret_y + 1 << ' ' << ret_x + 1;

	return 0;
}