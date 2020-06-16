#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int cost[100001];
bool visit[100001];
vector<int> v[100001];

void bfs(void) {
	// 시작 정점은 1
	queue<int> q;
	cost[1] = 0;
	visit[1] = true;
	q.push(1);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (auto there : v[here]) {
			if (!visit[there]) {
				visit[there] = true;
				cost[there] = cost[here] + 1;
				q.push(there);
			}
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	int f, t;
	for (int i = 0; i < n - 1; i++) {
		cin >> f >> t;
		v[f].push_back(t);
		v[t].push_back(f);
	}

	bfs();

	vector<int> temp_sol;
	int in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		temp_sol.push_back(in);
	}

	int cur_cost = cost[temp_sol[0]];
	int res = 1;

	if (1 == temp_sol[0]) {
		for (int i = 0; i < temp_sol.size(); i++) {
			if (cost[temp_sol[i]] < cur_cost || cost[temp_sol[i]] > cur_cost + 1) {
				// 현재 비용보다 작거나, 그 이상일 시 간격이 2이상이면
				// 잘못된 경로를 찾은 것이다.
				res = 0;
				break;
			}
			cur_cost = cost[temp_sol[i]];
		}
	}
	else res = 0;


	cout << res;

	return 0;
}