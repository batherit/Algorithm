#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> inequalitys;

bool ok(const vector<int> &v) {
	for (int i = 0; i < inequalitys.size(); i++) {
		if (inequalitys[i] == '<') {
			if (v[i] > v[i + 1]) return false;
		}
		else {
			if (v[i] < v[i + 1]) return false;
		}
	}
	return true;
}

int main(void) {
	int n;
	cin >> n;

	char inequality;
	inequalitys.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> inequality;
		inequalitys.push_back(inequality);
	}

	vector<int> mn(n + 1);
	vector<int> mx(n + 1);
	for (int i = 0; i <= n; i++) {
		mn[i] = i;
		mx[i] = 9 - i;
	}
	
	do {
		if (ok(mn)) break;
	} while (next_permutation(mn.begin(), mn.end()));

	do {
		if (ok(mx)) break;
	} while (prev_permutation(mx.begin(), mx.end()));

	for (int i = 0; i < mx.size(); i++) {
		cout << mx[i];
	}
	cout << '\n';
	for (int i = 0; i < mn.size(); i++) {
		cout << mn[i];
	}

	return 0;
}