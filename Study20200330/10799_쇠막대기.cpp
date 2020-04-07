#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	stack<int> s;
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(i);
		else if (str[i] == ')') {
			if (i - s.top() == 1) {
				s.pop();
				result += s.size();
			}
			else {
				s.pop();
				result++;
			}
		}
	}

	cout << result;

	return 0;
}