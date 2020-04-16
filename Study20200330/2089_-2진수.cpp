#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	stack<int> result;
	while (t != 0) {
		if (t < 0) {
			// �����̸鼭
			if (t % -2 != 0) {
				// �� ������ �������� �ʴ� ���
				result.push(-1 * (t % -2));
				t /= -2;
				t += 1;
			}
			else {
				// �� ������ �������� ���
				result.push(0);
				t /= -2;
			}
		}
		else {
			// ����� ���
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