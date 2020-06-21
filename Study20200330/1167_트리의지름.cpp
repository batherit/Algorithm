#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<pair<int, int>> v[100001];
bool visit[100001];

pair<int, int> dfs(int here, int total_cost) {
	visit[here] = true;

	pair<int, int> return_pair;
	pair<int, int> max_pair(here, total_cost);
	int there, cost;
	for (int i = 0; i < v[here].size(); i++) {
		there = v[here][i].first;
		cost = v[here][i].second;
		if (!visit[there]) {
			return_pair = dfs(there, total_cost + cost);	
			if (return_pair.second >= max_pair.second) {
				max_pair = return_pair;
			}
		}
	}
	return max_pair;
}

int main(void) {
	int n;
	cin >> n;

	int from, to, cost;
	for (int i = 1; i <= n; i++) {
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) break;
			cin >> cost;

			v[from].push_back(make_pair(to, cost));
		}
	}

	// 1에서 가장 먼 노드와 그 비용을 구한다.
	memset(visit, 0, sizeof(visit));
	pair<int, int> result = dfs(1, 0);

	// 1에서 가장 먼 노드에서 가장 먼 노드까지의 비용을 구한다.
	memset(visit, 0, sizeof(visit));
	result = dfs(result.first, 0);

	cout << result.second;

	return 0;
}
