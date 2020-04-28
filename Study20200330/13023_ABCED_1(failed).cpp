#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cnt[2001];

typedef pair<int, int> pii;

bool cmp(const pii &a, const pii &b) {
	return a.first < b.first;
}

int main(void) {
	int v, e;
	cin >> v >> e;

	vector<pair<int, int>> r;
	int f1, f2;
	for (int i = 0; i < e; i++) {
		cin >> f1 >> f2;
		r.push_back({ f1, f2 });
		r.push_back({ f2, f1 });
		cnt[f1]++; cnt[f2]++;
	}

	for (int i = 0; i < v; i++) {
		
	}

	sort(r.begin(), r.end());

	bool ok = false;
	for (int i = 0; i < v - 1; i++) {
		ok = false;
		for (int j = 0; r[j].first == i; j++) {
			if (r[j].second == i + 1) {
				ok = true;
				break;
			}
		}

		r.erase(lower_bound(r.begin(), r.end(), pii(i, 0), cmp), upper_bound(r.begin(), r.end(), pii(i, 0), cmp));

		if (!ok) {
			cout << 0;
			break;
		}
	}
	if (ok) cout << 1;

	return 0;
}