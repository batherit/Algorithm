#include<iostream>
#include<string>
#include<stack>
using namespace std;

void solution(string& str) {
	stack<char> s;
	for (auto ch : str) {
		if (ch != ' ') {
			s.push(ch);
		}
		else {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << ' ';
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main(void) {
	int t;
	cin >> t;
	cin.ignore();

	string str;
	while (t--) {
		getline(cin, str);
		solution(str);
		cout << '\n';
	}
	

	return 0;
}