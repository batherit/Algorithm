#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	// n : 사람 수, m : 친구 관계의 수
	int n, m;
	cin >> n >> m;

	int in1, in2;
	vector<pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2;
		v.push_back(make_pair(in1, in2));
		v.push_back(make_pair(in2, in1));
	}
	sort(v.begin(), v.end());

	int end[2010] = { 0, };
	int idx = 0;
	for (int i = 0; i < v.size(); i++) {
		if(v[0].first + idx == v[i].first)
			end[idx]++;
		else 
			end[++idx]++;
	}

	for (int i = 1; i < n; i++) {
		end[i] += end[i - 1];
	}

	int s = 0;
	int e = 0;
	bool ok = false;
	for (int i = 0; i < n - 1; i++) {
		s = e;
		e = end[i];
		ok = false;
		for (int j = s; j < e; j++) {
			if (v[j].second == v[j].first + 1) {
				ok = true;
				break;
			}
		}
		if (!ok) break;
	}

	cout << (ok ? 1 : 0);

	return 0;
}