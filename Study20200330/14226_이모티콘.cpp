#include<iostream>
#include<tuple>
#include<queue>
#include<cstring>
using namespace std;

int cost[1001][1001];

int dfs(int n) {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	cost[1][0] = 0;

	while (!q.empty()) {
		int scn, clp;
		tie(scn, clp) = q.front();
		q.pop();

		// 클립보드에 스크린의 이모티콘을 모두 복사
		if (cost[scn][scn] == -1) {
			// cost[scn][clp]에서 cost[scn][scn]으로의 비용이
			// cost[scn][clp] + 1이다.
			cost[scn][scn] = cost[scn][clp] + 1;
			q.push(make_pair(scn, scn));
		}
		// 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		if (scn + clp <= n && cost[scn + clp][clp] == -1) {
			cost[scn + clp][clp] = cost[scn][clp] + 1;
			q.push(make_pair(scn + clp, clp));
		}
		// 화면에 있는 이모티콘 중 하나를 삭제한다.
		if (scn - 1 >= 0 && cost[scn - 1][clp] == -1) {
			cost[scn - 1][clp] = cost[scn][clp] + 1;
			q.push(make_pair(scn - 1, clp));
		}
	}

	// n개의 이모티콘을 화면에 만드는데 걸리는 시간
	int res = -1;
	for (int i = 0; i <= n; i++) {
		if (cost[n][i] != -1) {
			if (res == -1 || res > cost[n][i]) {
				res = cost[n][i];
			}
		}
	}
	return res;
}

int main(void) {
	memset(cost, -1, sizeof(cost));

	int n;
	cin >> n;

	cout << dfs(n);

	return 0;
}