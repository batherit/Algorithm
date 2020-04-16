#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	stack<int> result;
	while (t != 0) {
		if (t < 0) {
			// 음수이면서
			if (t % -2 != 0) {
				// 딱 나누어 떨어지지 않는 경우
				result.push(-1 * (t % -2));
				t /= -2;
				t += 1;
			}
			else {
				// 딱 나누어 떨어지는 경우
				result.push(0);
				t /= -2;
			}
		}
		else {
			// 양수인 경우
			result.push(t % -2);
			t /= -2;
		}
	}

	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}