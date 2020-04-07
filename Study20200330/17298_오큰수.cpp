#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int in;
	vector<int> v;
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> in;
		v.push_back(in);
	}

	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty()) {
			if (v[s.top()] < v[i]) {
				result[s.top()] = v[i];
				s.pop();
			}
			else break;
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}