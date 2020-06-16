#include<iostream>
#include<queue>
#include<stack>
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

		if (here + 1 <= 100000 &&  -1 == cost[here + 1]) {
			q.push(here + 1);
			cost[here + 1] = cost[here] + 1;
			from[here + 1] = here;
			if (here + 1 == k) return;
		}
		if (here - 1 >= 0 && -1 == cost[here - 1]) {
			q.push(here - 1);
			cost[here - 1] = cost[here] + 1;
			from[here - 1] = here;
			if (here - 1 == k) return;
			
		}
		if (2 * here <= 100000 && -1 == cost[2 * here]) {
			q.push(2 * here);
			cost[2 * here] = cost[here] + 1;
			from[2 * here] = here;
			if (2 * here == k) return;
		}
	}
}

void print(int n, int k) {
	if (n != k) {
		print(n, from[k]);
	}
	cout << k << ' ';
}

int main(void) {
	memset(cost, -1, sizeof(cost));

	int n, k;
	cin >> n >> k;

	bfs(n, k);

	cout << cost[k] << endl;

	//print(n, k);

	stack<int> ans;
	for (int i = k; i != n; i = from[i]) {
		ans.push(i);
	}
	ans.push(n);
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';

	return 0;
}