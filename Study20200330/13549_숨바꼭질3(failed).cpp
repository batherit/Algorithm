#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int cost[100001];

int bfs(int n, int k) {
	int toggle = 0;
	queue<int> q[2];

	q[toggle].push(n);
	cost[n] = 0;

	int here = -1;
	while (true) {
		while (!q[toggle].empty()) {
			//ÀÛ¾÷ ÈÄ
			here = q[toggle].front();
			q[toggle].pop();

			if (here + 1 <= 100000 && cost[here + 1] == -1) {
				cost[here + 1] = cost[here] + 1;
				if (here + 1 == k) return cost[k];
				q[(toggle + 1) % 2].push(here + 1);
			}
			if (here - 1 >= 0 && cost[here - 1] == -1) {
				cost[here - 1] = cost[here] + 1;
				if (here - 1 == k) return cost[k];
				q[(toggle + 1) % 2].push(here - 1);
			}
			if (2 * here <= 100000 && cost[2 * here] == -1) {
				cost[2 * here] = cost[here];
				if (2 * here == k) return cost[k];
				q[toggle].push(2 * here);
			}
		}
		if (q[(toggle + 1) % 2].empty()) break;
		else toggle = (toggle + 1) % 2;
	}
	return cost[k];
}

int main(void) {
	memset(cost, -1, sizeof(cost));

	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);
	return 0;
}