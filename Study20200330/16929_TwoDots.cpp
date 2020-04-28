#include<iostream>
#include<string>
#include<cmath>
using namespace std;

char arr[55][55];
bool vis[55][55];
int len[55][55];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool dfs(int y, int x, char c, int l) {
	len[y][x] = l;
	vis[y][x] = true;

	int n_y, n_x;
	for (int i = 0; i < 4; i++) {
		n_y = y + dy[i];
		n_x = x + dx[i];
		if (arr[n_y][n_x] == c && !vis[n_y][n_x]) {
			if (dfs(n_y, n_x, c, l + 1)) return true;
		}
		else if (arr[n_y][n_x] == c && vis[n_y][n_x]) {
			// ���� ������ ������ �湮�� ���� �ִ� ���.
			if (abs(len[n_y][n_x] - l) > 1) {
				// ������ ��� ���̿� ��ϵ� ��� ������ ���� 2 �̻��̸�, 
				// ��� ���� ������ �湮�� ���� �ƴϴ�. == ����Ŭ�� �ִ� ��.
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	cin.ignore();

	string row;
	for (int i = 0; i < n; i++) {
		getline(cin, row);
		for (int j = 0; j < m; j++) {
			arr[i][j] = row[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				if (dfs(i, j, arr[i][j], 0)) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}

	cout << "No";
	return 0;
}