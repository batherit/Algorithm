#include<iostream>
#include<vector>
using namespace std;

vector<int> v[100001];
int parent[100001];

void dfs(int root) {
	for (int i = 0; i < v[root].size(); i++) {
		if (parent[v[root][i]] == 0) {
			parent[v[root][i]] = root;
			dfs(v[root][i]);
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	int f, t;
	for (int i = 1; i < n; i++) {
		cin >> f >> t;
		v[f].push_back(t);
		// 왜 양방향이어야될까?
		// 루트를 지정하지 않은 상태에서 단방향 탐색을 진행하면 모든 노드를 순회하지 않을 수 있다.
		/*
		7
1 6
6 3
3 5
4 1
2 4
4 7
그림 그려서 파악해보기
		*/
		v[t].push_back(f);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}