#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

int cost[100001];

int bfs(int n, int k) {
	deque<int> dq;
	dq.push_front(n);
	cost[n] = 0;

	int here = -1;
	while (!dq.empty()) {
		here = dq.front();
		dq.pop_front();

		if (here == k) return cost[k];

		if (2 * here <= 100000 && cost[2 * here] == -1) {
			cost[2 * here] = cost[here];
			dq.push_front(2 * here);
		}

		if (here - 1 >= 0 && cost[here - 1] == -1) {
			cost[here - 1] = cost[here] + 1;
			dq.push_back(here - 1);
		}
		if (here + 1 <= 100000 && cost[here + 1] == -1) {
			cost[here + 1] = cost[here] + 1;
			dq.push_back(here + 1);
		}


	}
}

int main(void) {
	memset(cost, -1, sizeof(cost));

	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}