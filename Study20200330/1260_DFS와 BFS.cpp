#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef vector<vector<int>> vvi;
vector<bool> vis;

void dfs(vvi &edges, int s) {
	cout << s << ' ';
	vis[s] = true;

	for (int i = 0; i < edges[s].size(); i++) {
		// edges[s]에 달린 정점 순회
		int there = edges[s][i];
		if (!vis[there]) {
			//vis[there] = true;
			dfs(edges, there);
		}
	}
}

void bfs(vvi &edges, int s) {
	// bfs는 방문 체크와 동시에 q에 정점을 집어넣는다.
	queue<int> q;
	q.push(s);
	vis[s] = true;

	while (!q.empty()) {
		int here = q.front();
		cout << here << ' ';
		q.pop();
		for (int i = 0; i < edges[here].size(); i++) {
			int there = edges[here][i];
			if (!vis[there]) {
				q.push(there);
				vis[there] = true;
			}
		}
	}
}

int main(void) {
	int v, e, s;
	cin >> v >> e >> s;

	vvi edges(v + 1);
	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}
	
	for (int i = 1; i <= v; i++) {
		sort(edges[i].begin(), edges[i].end());
	}

	vis.assign(1001, false);
	dfs(edges, s);
	cout << '\n';
	vis.assign(1001, false);
	bfs(edges, s);

	return 0;
}