#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<string> rows;
vector<int> alpha_num;

int conv2idx[30];

int sum() {
	int ret = 0;
	for (int i = 0; i < rows.size(); i++) {
		int sub = 0;
		for (int j = 0; j < rows[i].size(); j++) {
			sub *= 10;
			sub += alpha_num[conv2idx[rows[i][j] - 'A']];
		}
		ret += sub;
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;

	string unique_rows;
	rows.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> rows[i];
		unique_rows += rows[i];
	}

	sort(unique_rows.begin(), unique_rows.end());
	unique_rows.erase(unique(unique_rows.begin(), unique_rows.end()), unique_rows.end());
	for (int i = 0; i < unique_rows.size(); i++) {
		conv2idx[unique_rows[i] - 'A'] = i;
	}

	alpha_num.resize(unique_rows.size());
	for (int i = 0; i < alpha_num.size(); i++) {
		alpha_num[i] = 9 - i; // 내림차순 정렬된 상태
	}

	int ret = 0;
	do {
		ret = max(ret, sum());
	} while (prev_permutation(alpha_num.begin(), alpha_num.end()));

	cout << ret;

	return 0;
}
