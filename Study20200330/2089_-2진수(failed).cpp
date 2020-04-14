#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	t = ~t + 1;

	stack<int> result;
	while (t != 0) {
		int r = t % 2;
		result.push(r);
		t /= 2;
	}

	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}