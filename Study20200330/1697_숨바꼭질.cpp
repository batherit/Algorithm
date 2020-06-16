#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int cost[100001];
int from[100001];

void bfs(int n, int k) {
	if (n == k) {
		cost[k] = 0;
		return;
	}

	queue<int> q;
	q.push(n);
	cost[n] = 0;

	int here;
	while (!q.empty()) {
		here = q.front();
		q.pop();

		if (here + 1 <= 100000 && -1 == cost[here + 1]) {
			q.push(here + 1);
			cost[here + 1] = cost[here] + 1;
			if (here + 1 == k) return;
		}
		if (here - 1 >= 0 && -1 == cost[here - 1]) {
			q.push(here - 1);
			cost[here - 1] = cost[here] + 1;
			if (here - 1 == k) return;

		}
		if (2 * here <= 100000 && -1 == cost[2 * here]) {
			q.push(2 * here);
			cost[2 * here] = cost[here] + 1;
			if (2 * here == k) return;
		}
	}
}

int main(void) {
	memset(cost, -1, sizeof(cost));

	int n, k;
	cin >> n >> k;

	bfs(n, k);

	cout << cost[k];

	return 0;
}