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
				// ����Ŭ�� ã���� ���Ͽ����� ����� ��Ȳ
				// �ٸ� ������ �湮�غ���.
				continue;
			}
			else if (ret == -2) {
				// ����Ŭ�� ã�� ����
				// �̿��� ����Ŭ�� ã�� ���̶�� ��ĥ �ʿ䰡 �ִ�.
				return -2;
			}
			else if (ret != s) {
				// ����Ŭ�� �̷�� ���� �� �ϳ�
				cycle[s] = true;
				return ret;
			}
			else if (ret == s) {
				// ����Ŭ�� �ߴ���
				cycle[s] = true;
				return -2;
			}
		}
		else if (vis[there]) {
			// �湮�� ���ε�,
			if (there != old_v) {
				// ������ �湮�� ������ �ƴ϶��
				// ����Ŭ�� �̷�� ������ �����̴�.
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
		// ����Ŭ�� ���� ���
		return 0;
	}

	for (int i = 0; i < list[s].size(); i++) {
		int there = list[s][i];
		if (!vis[there]) {
			int ret = make_cost(there);
			if(ret >= 0) {
				// ����Ŭ�� ���� ȸ���ϴ� ���
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