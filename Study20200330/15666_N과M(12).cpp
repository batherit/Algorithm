#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int res[10];
int arr[10];
vector<vector<int>> v;

void save(int e) {
	vector<int> tmp;

	for (int i = 0; i < e; i++) {
		tmp.push_back(res[i]);
	}
	v.push_back(tmp);
}

void sol(int n, int m, int s, int d) {
	if (d == m) {
		save(d);
		return;
	}

	for (int i = s; i < n; i++) {
		res[d] = arr[i];
		sol(n, m, i, d + 1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	sol(n, m, 0, 0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}