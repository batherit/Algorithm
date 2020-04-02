#include<iostream>
#include<stack>
#include<string>
using namespace std;

// L : 커서를 왼쪽으로... 커서가 문장의 맨 앞이면 무시됨.
// D : 커서를 오른쪽으로...커서가 문장의 맨 뒤이면 무시됨.
// B : 커서 왼쪽에 있는 문자를 삭제함 (커서가 맨 앞이면 무시.)
// P $ : $ 라는 문자를 커서 왼쪽에 추가함.

int main(void) {
	stack<char> s_l;
	stack<char> s_r;

	string init_str;
	cin >> init_str;
	// cin.ignore();

	for (auto ch : init_str) {
		s_l.push(ch);
	}

	int t;
	cin >> t;
	cin.ignore();

	char cmd[5];
	while (t--) {
		cin.getline(cmd, sizeof(cmd));

		switch (cmd[0])
		{
		case 'L':
			if (!s_l.empty()) {
				s_r.push(s_l.top());
				s_l.pop();
				
			}
			break;
		case 'D':
			if (!s_r.empty()) {
				s_l.push(s_r.top());
				s_r.pop();
				
			}
			break;
		case 'B':
			if (!s_l.empty()) {
				s_l.pop();
			}
			break;
		case 'P':
			s_l.push(cmd[2]);
			break;
		default:
			break;
		}
	}

	while (!s_l.empty()) {
		s_r.push(s_l.top());
		s_l.pop();
	}

	while (!s_r.empty()) {
		cout << s_r.top();
		s_r.pop();
	}

	return 0;
}