#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int board[101][101];
int group[101][101];
int cost[101][101];
queue<pair<int, int>> q[2];
int toggle;
int n;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };



bool ok(int y, int x) {
	return (0 <= y && y < n) && (0 <= x && x < n);
}

void grouping(int y, int x, int id) {
	group[y][x] = id;

	int there_y = -1;
	int there_x = -1;

	for (int i = 0; i < 4; i++) {
		there_y = y + dy[i];
		there_x = x + dx[i];
		if (ok(there_y, there_x)) {
			if (1 == board[there_y][there_x] && 0 == group[there_y][there_x]) {
				// 다음 그루핑
				grouping(there_y, there_x, id);
			}
			else if (0 == board[there_y][there_x] && 0 == group[there_y][there_x]) {
				// 초기 큐 작성
				cost[there_y][there_x] = cost[y][x] + 1;
				group[there_y][there_x] = group[y][x];
				q[toggle].push(make_pair(there_y, there_x));
			}
		}
	}
}

int bfs() {
	int res;
	while(true) {
		res = 987654321;
		while (!q[toggle].empty()) {
			int here_y = q[toggle].front().first;
			int here_x = q[toggle].front().second;
			q[toggle].pop();

			int there_y = -1;
			int there_x = -1;
			for (int i = 0; i < 4; i++) {
				there_y = here_y + dy[i];
				there_x = here_x + dx[i];
				if (ok(there_y, there_x)) {
					if (0 == group[there_y][there_x]) {
						cost[there_y][there_x] = cost[here_y][here_x] + 1;
						group[there_y][there_x] = group[here_y][here_x];
						q[(toggle + 1) % 2].push(make_pair(there_y, there_x));
					}
					else if (group[there_y][there_x] != group[here_y][here_x]) {
						res = min(res, cost[there_y][there_x] + cost[here_y][here_x]);
					}
				}
			}
		}
		if (q[(toggle + 1) % 2].empty() || res != 987654321) break;
		else  toggle = (toggle + 1) % 2;
		
	}
	
	return res;
}

int main()
{
	cin >> n;

	// 육지 및 바다 정보를 입력한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	// 섬을 그루핑하면서 초기 큐를 작성한다.
	int id = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (1 == board[i][j] && 0 == group[i][j]) {
				grouping(i, j, id++);
			}
		}
	}

	// 비용을 출력한다.
	cout << bfs();

	return 0;
}