#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	stack<int> s;
	string result;
	int current_value = 1;
	int input;
	bool failed = false;
	while (!failed && t--) {
		cin >> input;
		while (!failed) {
			if (input >= current_value) {
				s.push(current_value++);
				result.push_back('+');
			}
			else if (!s.empty()) {
				if (input == s.top()) {
					s.pop();
					result.push_back('-');
					break;
				}
				if (input > s.top()) {	// ���ʿ��� ����� ���ϵ��� �ϴ� ���ǹ�.
					failed = true;
				}
				else {
					s.pop();
					result.push_back('-');
				}
			}
			else failed = true;
		}
	}

	if (!failed) {
		for (auto ch : result) {
			cout << ch << '\n';
		}
	}
	else cout << "NO" << '\n';

	return 0;
}