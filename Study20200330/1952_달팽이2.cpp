#include<iostream>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool vis[101][101];
int n, m;

int next(int y, int x, int dir) {
	// 다음 갈 곳을 반환한다.
	int next_dir = (dir + 1) % 4;
	int next_y = y + dy[dir];
	int next_x = x + dx[dir];

	if ((next_y < 0 || next_y >= n) 
		|| (next_x < 0 || next_x >= m)
		|| vis[next_y][next_x]) {
		next_y = y + dy[next_dir];
		next_x = x + dx[next_dir];
		if ((next_y < 0 || next_y >= n)
			|| (next_x < 0 || next_x >= m)
			|| vis[next_y][next_x]) {
			return -1;
		}
		else return next_dir;
	}
	else return dir;
}

int main(void) {
	cin >> n >> m;

	int y, x;
	y = x = 0;

	int dir = 0;
	int res = 0;
	int tmp = 0;
	vis[0][0] = true;
	for (int i = 0; i < n * m; i++) {
		tmp = next(y, x, dir);
		if (tmp == -1) break;	// 갈 곳이 없다면
		if (tmp != dir) {
			// 방향이 꺾이면
			res++;
			dir = tmp;
		}
		y += dy[dir];
		x += dx[dir];
		vis[y][x] = true;
	}

	cout << res;

	return 0;
}