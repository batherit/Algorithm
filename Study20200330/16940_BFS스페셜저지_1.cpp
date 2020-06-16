#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int parent[100001];
bool visit[100001];
vector<int> v[100001];
int order[100001];

int bfs(void) {
	// ù �湮 ��尡 1�̹Ƿ�, �װ��� �ƴ϶�� 0(�߸�)�� ��ȯ�Ѵ�.
	if (1 != order[0]) return 0;

	queue<int> q;
	visit[1] = true;
	parent[1] = 0;
	q.push(1);

	// ù �湮��尡 �ִ� ���� �迭 �ε��� 0�� �̹� �������� �� if���� ���� ����ǹǷ�
	// 1���� üũ�Ѵ�.
	int order_idx = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		int cnt = 0;
		for (auto there : v[here]) {
			if (!visit[there]) {
				visit[there] = true;
				// here�� ���� there�� �湮�ߴٴ� ���� �ǹ��Ѵ�.
				parent[there] = here;
				cnt++;
			}
		}
		for (int i = 0; i < cnt; i++) {
			if (parent[order[order_idx]] == here) {
				q.push(order[order_idx++]);
			}
			// �湮 ������ ���� �����Ƿ� 0�� ��ȯ�Ѵ�.
			else return 0;
		}
	}

	// ��� Ȯ���Ͽ����� �߸��� �߰����� �������Ƿ� 1�� ��ȯ�Ѵ�.
	return 1;
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

	cout << bfs();
	
	return 0;
}