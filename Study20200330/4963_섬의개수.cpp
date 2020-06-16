#include<iostream>
#include<cstring>
using namespace std;

int arr[55][55];
bool vis[55][55];
int w, h;
const int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

bool is_valid(int i, int j, int h, int w) {
	return (0 <= i && i < h) && (0 <= j && j < w);
}

void dfs(int here_y, int here_x) {
	vis[here_y][here_x] = true;
	
	for (int i = 0; i < 8; i++) {
		int there_y = here_y + dy[i];
		int there_x = here_x + dx[i];
		if (is_valid(there_y, there_x, h, w) &&
			!vis[there_y][there_x] &&
			(1 == arr[there_y][there_x])) {
			dfs(there_y, there_x);
		}
	}
}

int main(void) {
	while (true) {
		cin >> w >> h;
		if (0 == w && 0 == h) break;

		memset(vis, false, sizeof(vis));
		// 1 ¶¥, 0 ¹Ù´Ù
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (1 == arr[i][j] && !vis[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}