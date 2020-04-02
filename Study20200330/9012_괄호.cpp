#include<iostream>
#include<string>
#include<stack>
using namespace std;

// 스택을 쓰지 않아도 풀 수 있다!
bool solution(const string& str) {
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')') {
			if (!s.empty()) {
				s.pop();
			}
			else return false;
		}
	}
	
	if (s.empty()) return true;
	else return false;
}

int main(void) {
	int t;
	cin >> t;
	cin.ignore();

	string str;
	while (t--) {
		getline(cin, str);
		if (solution(str)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}