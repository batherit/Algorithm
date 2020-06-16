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

		// Ŭ�����忡 ��ũ���� �̸�Ƽ���� ��� ����
		if (cost[scn][scn] == -1) {
			// cost[scn][clp]���� cost[scn][scn]������ �����
			// cost[scn][clp] + 1�̴�.
			cost[scn][scn] = cost[scn][clp] + 1;
			q.push(make_pair(scn, scn));
		}
		// Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
		if (scn + clp <= n && cost[scn + clp][clp] == -1) {
			cost[scn + clp][clp] = cost[scn][clp] + 1;
			q.push(make_pair(scn + clp, clp));
		}
		// ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
		if (scn - 1 >= 0 && cost[scn - 1][clp] == -1) {
			cost[scn - 1][clp] = cost[scn][clp] + 1;
			q.push(make_pair(scn - 1, clp));
		}
	}

	// n���� �̸�Ƽ���� ȭ�鿡 ����µ� �ɸ��� �ð�
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