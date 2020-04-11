#include<iostream>
#include<vector>
using namespace std;

bool prime[1000001];

int main(void) {
	vector<int> v;
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == false) {
			v.push_back(i);
			for (int j = i + i; j <= 1000000; j += i) {
				prime[j] = true;
			}
		}
	}

	int t;
	cin >> t;

	int in;
	while (t--) {
		cin >> in;
		int cnt = 0;
		for (auto val : v) {
			if (val <= in - val) {
				if (prime[val] == false && prime[in - val] == false) {
					cnt++;
				}
			}
			else break;
		}
		cout << cnt << '\n';
	}

	return 0;
}