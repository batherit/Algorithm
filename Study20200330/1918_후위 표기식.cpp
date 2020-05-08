#include<iostream>
#include<string>
#include<stack>
using namespace std;

int order(char oper) {
	switch (oper) {
	case '+' : case '-' :
		return 1;
	case '*' : case '/' :
		return 2;
	case '(':
		return 0;
	}
}

string sol(string &str) {
	string res;
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			res.push_back(str[i]);
		}
		else {
			if (str[i] == '(') {
				s.push('(');
			}
			else if (str[i] == ')') {
				while (s.top() != '(') {
					res.push_back(s.top());
					s.pop();
				}
				s.pop(); // '('À» Á¦°Å
			}
			else {
				while (!s.empty()) {
					if (order(s.top()) >= order(str[i])) {
						res.push_back(s.top());
						s.pop();
					}
					else break;
				}
				s.push(str[i]);
			}
		}
	}

	while (!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}

	return res;
}

int main(void) {
	string str;
	cin >> str;

	cout << sol(str);

	return 0;
}