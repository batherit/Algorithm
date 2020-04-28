#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> vvi;
vvi edges;
bool vis[1001];

void dfs(int s) {
	vis[s] = true;
	for (int i = 0; i < edges[s].size(); i++) {
		int there = edges[s][i];
		if (!vis[there]) {
			//vis[there] = true;
			dfs(there);
		}
	}
}

int main(void) {
	int v, e;
	cin >> v >> e;
	edges.resize(v + 1);

	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}