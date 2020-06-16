#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visit[100001];
int order[100001];
int priority[100001];
vector<int> v[100001];
int idx = 0;

bool cmp(int& a, int& b) {
	return priority[a] < priority[b];
}

int dfs(int start, int n) {
	if (order[idx++] != start) return 0;

	visit[start] = true;

	if (idx == n) {
		return 1;
	}

	int there;
	int result;
	for (int i = 0; i < v[start].size(); i++) {
		there = v[start][i];
		if (!visit[there]) {
			result = dfs(there, n);
			if (2 != result) return result;
		}
	}
	// 아직 모른다.
	return 2;
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
	for (int i = 0; i < n; i++) {
		cin >> order[i]; 
		priority[order[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
	}

	if (1 == dfs(1, n)) cout << 1;
	else cout << 0;

	return 0;
}