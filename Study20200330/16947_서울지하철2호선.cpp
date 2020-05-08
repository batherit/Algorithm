#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> vvi;

bool cycle[3001];
vector<bool> vis;
int cost[3001]; 
vvi list;

int make_cycle(int s, int old_v) {
	vis[s] = true;

	for (int i = 0; i < list[s].size(); i++) {
		int there = list[s][i];
		if (!vis[there]) {
			int ret = make_cycle(there, s);
			if (ret == -1) {
				// 사이클을 찾지는 못하였지만 종료된 상황
				// 다른 정점을 방문해본다.
				continue;
			}
			else if (ret == -2) {
				// 사이클을 찾은 이후
				// 이외의 사이클을 찾을 것이라면 고칠 필요가 있다.
				return -2;
			}
			else if (ret != s) {
				// 사이클을 이루는 정점 중 하나
				cycle[s] = true;
				return ret;
			}
			else if (ret == s) {
				// 사이클의 중단점
				cycle[s] = true;
				return -2;
			}
		}
		else if (vis[there]) {
			// 방문한 곳인데,
			if (there != old_v) {
				// 이전에 방문한 정점이 아니라면
				// 사이클을 이루는 마지막 정점이다.
				cycle[s] = true;
				return there;
			}
		}
	}
	return -1;
}

int make_cost(int s) {
	vis[s] = true;
	if (cycle[s]) {
		// 사이클을 만난 경우
		return 0;
	}

	for (int i = 0; i < list[s].size(); i++) {
		int there = list[s][i];
		if (!vis[there]) {
			int ret = make_cost(there);
			if(ret >= 0) {
				// 사이클을 만나 회귀하는 경우
				return cost[s] = ret + 1;
			}
		}
	}
	return -1;
}

int main(void) {
	int n;
	cin >> n;
	list.resize(n + 1);
	vis.resize(n + 1);
	
	int v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> v1 >> v2;
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}

	make_cycle(1, -1);
	for (int i = 1; i <= n; i++) {
		vis.assign(n + 1, false);
		make_cost(i);
	}

	for (int i = 1; i <= n; i++) {
		cout << cost[i] << ' ';
	}

	return 0;
}