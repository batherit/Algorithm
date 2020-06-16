// ≈‰∏∂≈‰
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int g_N, g_M;

int g_board[1000][1000];
int g_dist[1000][1000];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> g_q[2];

int BFS() {
	int latest_day = 0;

	int tog = 0;

	while (g_q[(tog + 1) % 2].empty()) {
		if (!g_q[tog].empty()) {
			while (!g_q[tog].empty()) {
				pair<int, int> here = g_q[tog].front();
				g_q[tog].pop();
				int i = here.first;
				int j = here.second;
				if (g_dist[i][j] == -1 && g_board[i][j] == 1) {
					g_dist[i][j] = latest_day;

					for (int k = 0; k < 4; k++) {
						int go_i = i + dy[k];
						int go_j = j + dx[k];
						if ((-1 < go_i && go_i < g_N) &&
							(-1 < go_j && go_j < g_M) &&
							(g_board[go_i][go_j] == 0)) {
							g_board[go_i][go_j] = 1;
							g_q[(tog + 1) % 2].push(make_pair(go_i, go_j));
						}
					}
				}
			}

		}
		else break;
		tog = (tog + 1) % 2;
		latest_day++;
	}

	for (int i = 0; i < g_N; i++) {
		for (int j = 0; j < g_M; j++) {
			if (g_board[i][j] == 0) return -1;
		}
	}
	return latest_day - 1;
}

int main(void) {
	memset(g_dist, -1, sizeof(g_dist));
	cin >> g_M >> g_N;
	for (int i = 0; i < g_N; i++) {
		for (int j = 0; j < g_M; j++) {
			cin >> g_board[i][j];
			if (g_board[i][j] == 1) {
				g_q[0].push(make_pair(i, j));
			}
		}
	}
	cout << BFS();
	return 0;
}