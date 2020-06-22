#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int board[21][21];

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> team;
	for (int i = 0; i < n; i++) {
		if (i < n / 2) team.push_back(0);
		else team.push_back(1);
	}

	int ret = 9887654321;
	do {
		vector<int> start;
		vector<int> link;

		for (int i = 0; i < team.size(); i++) {
			if (team[i] == 0) start.push_back(i);
			else link.push_back(i);
		}

		int start_sum = 0;
		int link_sum = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				start_sum += board[start[i]][start[j]];
				link_sum += board[link[i]][link[j]];
			}
		}
		ret = min(ret, abs(start_sum - link_sum));
	} while (next_permutation(team.begin(), team.end()));

	cout << ret;
	return 0;
}