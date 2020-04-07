#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	stack<char> s;
	bool is_tag = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<')
		{
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			is_tag = true;
		}
		else if (str[i] == '>') {
			is_tag = false;
			cout << '>';
			continue;
		}

		if (is_tag) cout << str[i];
		else {
			if (str[i] != ' ') {
				s.push(str[i]);
			}
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	
	return 0;
}