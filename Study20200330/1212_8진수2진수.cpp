#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main(void) {
	string str;
	cin >> str;

	queue<int> result;
	stack<int> s;
	for (auto a : str) {
		int n = a - '0';
		for (int i = 0; i < 3; i++) {
			s.push(n % 2);
			n /= 2;
		}
		while (!s.empty()) {
			result.push(s.top());
			s.pop();
		}
	}

	while (result.size() > 1 && result.front() == 0) {
		result.pop();
	}

	while (!result.empty()) {
		cout << result.front();
		result.pop();
	}

	return 0;
}