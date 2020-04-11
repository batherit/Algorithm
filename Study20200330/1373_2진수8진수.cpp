#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int main(void) {
	string str;
	cin >> str;

	stack<char> s;
	for (auto a : str) {
		s.push(a);
	}
	
	stack<int> result;
	while (!s.empty()) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			if (!s.empty()) {
				if (s.top() == '1') sum += pow(2, i);
				s.pop();
			}
			else break;
		}
		result.push(sum);
	}
	
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}