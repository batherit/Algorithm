#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int parent[100001];
bool visit[100001];
vector<int> v[100001];
int order[100001];

int bfs(void) {
	// 첫 방문 노드가 1이므로, 그것이 아니라면 0(잘못)을 반환한다.
	if (1 != order[0]) return 0;

	queue<int> q;
	visit[1] = true;
	parent[1] = 0;
	q.push(1);

	// 첫 방문노드가 있는 순서 배열 인덱스 0은 이미 정상임이 위 if문에 의해 보장되므로
	// 1부터 체크한다.
	int order_idx = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		int cnt = 0;
		for (auto there : v[here]) {
			if (!visit[there]) {
				visit[there] = true;
				// here를 거쳐 there를 방문했다는 것을 의미한다.
				parent[there] = here;
				cnt++;
			}
		}
		for (int i = 0; i < cnt; i++) {
			if (parent[order[order_idx]] == here) {
				q.push(order[order_idx++]);
			}
			// 방문 순서가 옳지 않으므로 0을 반환한다.
			else return 0;
		}
	}

	// 모두 확인하였지만 잘못을 발견하지 못했으므로 1을 반환한다.
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