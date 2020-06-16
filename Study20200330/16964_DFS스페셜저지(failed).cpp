#include<iostream>
#include<vector>

using namespace std;

int order[100001];
vector<int> v[100001];
bool visit[100001];
int m = 1;

void dfs(int start) {
	visit[start] = true;

	for (int i = 0; i < v[start].size(); i++) {
		int there = v[start][i];
		if (!visit[there] && there == order[m]) {
			visit[there] = true;
			m++;
			dfs(there);
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

	for (int i = 0; i < n; i++) {
		cin >> order[i];
	}

	if (1 == order[0]) {
		cout << (m == n ? 0 : 1) << endl;
	}
	else cout << 0;

	return 0;
}