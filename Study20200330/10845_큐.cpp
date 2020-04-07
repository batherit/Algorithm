#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	cin.ignore();

	queue<int> q;
	char cmd_row[15];
	char* cmd_str;
	int push_value;
	while (t--) {
		cin.getline(cmd_row, sizeof(cmd_row));
		cmd_str = strtok(cmd_row, " ");
		
		if (!strcmp(cmd_str, "push")) {
			push_value = atoi(strtok(nullptr, " "));
			q.push(push_value);
		}
		else if (!strcmp(cmd_str, "pop")) {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (!strcmp(cmd_str, "size")) {
			cout << q.size() << '\n';
		}
		else if (!strcmp(cmd_str, "empty")) {
			cout << (q.empty() ? 1 : 0) << '\n';
		}
		else if (!strcmp(cmd_str, "front")) {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else if (!strcmp(cmd_str, "back")) {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}

	return 0;
}