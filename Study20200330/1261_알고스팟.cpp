#include<iostream>
#include<deque>
#include<string>
#include<cstring>
#include<tuple>
using namespace std;

int board[101][101];
int cost[101][101];
int w, h;
const int dx[4] = { 1, 0 , -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

bool ok(int y, int x) {
	return (0 <= y && y < h) && (0 <= x && x < w);
}

int bfs(int y, int x) {
	deque<pair<int, int>> dq;
	cost[y][x] = 0;
	dq.push_front(make_pair(y, x));

	int here_y, here_x;
	while (!dq.empty()) {
		tie(here_y, here_x) = dq.front();
		dq.pop_front();
		if (here_y == h - 1 && here_x == w - 1) return cost[here_y][here_x];

		int there_y, there_x;
		for (int i = 0; i < 4; i++) {
			there_y = here_y + dy[i];
			there_x = here_x + dx[i];
			if (ok(there_y, there_x) && cost[there_y][there_x] == -1) {
				if (board[there_y][there_x] == 0) {
					cost[there_y][there_x] = cost[here_y][here_x];
					dq.push_front(make_pair(there_y, there_x));
				}
				else {
					cost[there_y][there_x] = cost[here_y][here_x] + 1;
					dq.push_back(make_pair(there_y, there_x));
				}

			}
		}
	}
}

int main(void) {
	memset(cost, -1, sizeof(cost));
	cin >> w >> h;

	string input_str;
	for (int i = 0; i < h; i++) {
		cin >> input_str;
		for (int j = 0; j < w; j++) {
			board[i][j] = input_str[j] - '0';
		}
	}

	cout << bfs(0, 0);

	return 0;
}