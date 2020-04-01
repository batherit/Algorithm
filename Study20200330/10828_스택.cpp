#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

enum STACK_CMD { PUSH, POP, TOP, SIZE, EMPTY, NONE };
STACK_CMD translate(char cmd[], int& push_value) {
	if (cmd == nullptr) return NONE;

	char* ret_cmd = strtok(cmd, " ");
	if (strcmp(ret_cmd, "push") == 0) {
		char* value_str = strtok(nullptr, " ");
		push_value = atoi(value_str);
		return PUSH;
	}
	else if (strcmp(ret_cmd, "pop") == 0)	return POP;
	else if (strcmp(ret_cmd, "top") == 0)	return TOP;
	else if (strcmp(ret_cmd, "size") == 0)	return SIZE;
	else if (strcmp(ret_cmd, "empty") == 0)	return EMPTY;
	else return NONE;
}

#define TRANSLATE(cmd, push_value) translate(cmd, push_value)

int main(void) {
	int t;
	cin >> t;
	cin.ignore();

	char cmd[100];
	stack<int> s;
	int push_value;
	while (t--) {
		cin.getline(cmd, sizeof(cmd));
		switch (TRANSLATE(cmd, push_value))
		{
		case PUSH:
			s.push(push_value);
			break;
		case POP:
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else cout << -1 << '\n';
			break;
		case TOP:
			if (!s.empty()) {
				cout << s.top() << '\n';
			}
			else cout << -1 << '\n';
			break;
		case SIZE:
			cout << s.size() << '\n';
			break;
		case EMPTY:
			cout << (s.empty() ? 1 : 0) << '\n';
			break;
		default:
			break;
		}
	}

	return 0;
}