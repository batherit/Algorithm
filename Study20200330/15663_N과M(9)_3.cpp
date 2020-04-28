#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int arr[10];
int res[10];
bool vis[10];
set<vector<int>> s;

void save(int e) {
	vector<int> tmp;
	for (int i = 0; i < e; i++) {
		tmp.push_back(res[i]);
	}
	s.insert(tmp);
}

void sol(int n, int m, int d) {
	if (d == m) {
		save(d);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			res[d] = arr[i];
			sol(n, m, d + 1);
			vis[i] = false;
		}
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	sol(n, m, 0);

	set<vector<int>>::iterator iter;

	for (iter = s.begin(); iter != s.end(); iter++) {
		for (int j = 0; j < iter->size(); j++) {
			cout << (*iter)[j] << ' ';
		} 
		cout << '\n';
	}

	return 0;
}