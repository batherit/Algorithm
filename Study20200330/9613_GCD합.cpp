#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(void) {
	int t;
	cin >> t;

	int c;
	while (t--) {
		cin >> c;

		int in;
		vector<int> v;
		while (c--) {
			cin >> in;
			v.push_back(in);
		}

		long long sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				sum += gcd(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}