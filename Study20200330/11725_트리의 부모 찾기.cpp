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
		// �� ������̾�ߵɱ�?
		// ��Ʈ�� �������� ���� ���¿��� �ܹ��� Ž���� �����ϸ� ��� ��带 ��ȸ���� ���� �� �ִ�.
		/*
		7
1 6
6 3
3 5
4 1
2 4
4 7
�׸� �׷��� �ľ��غ���
		*/
		v[t].push_back(f);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}