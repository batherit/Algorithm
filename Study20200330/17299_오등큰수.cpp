#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int freq[1000001];

int main(void) {
	int t;
	cin >> t;
	vector<int> result;
	result.resize(t, -1);

	vector<int> v;
	int in;
	for (int i = 0; i < t; i++) {
		cin >> in;
		freq[in]++;
		v.push_back(in);
	}

	stack<int> s;
	for (int i = 0; i < t; i++) {
		while (!s.empty()) {
			if (freq[v[s.top()]] < freq[v[i]]) {
				result[s.top()] = v[i];
				s.pop();
			}
			else break;
		}
		s.push(i);
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}