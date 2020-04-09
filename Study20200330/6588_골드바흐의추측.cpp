#include<iostream>
#include<vector>
using namespace std;

bool prime[1000001];

int main(void) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> v;
	prime[1] = true;
	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i] == false) {
			v.push_back(i);
			for (int j = i * i; j <= 1000000; j += i) {
				prime[j] = true;
			}
		}
	}

	int in;
	while (true) {
		cin >> in;
		if (in == 0) break;

		int finded = false;
		for (auto val : v) {
			if (val <= in - val) {
				if (prime[val] == false && prime[in - val] == false) {
					cout << in << " = " << val << " + " << in - val << '\n';
					finded = true;
					break;
				}
			}
			else break;
		}
		if (!finded) cout << "Goldbach's conjecture is wrong." << '\n';
	}

	return 0;
}