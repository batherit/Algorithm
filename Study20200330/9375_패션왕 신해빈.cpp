#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<string, string> pss;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cin.ignore();

		char row[50];
		vector<pss> v;
		for (int i = 0; i < n; i++) {
			cin.getline(row, sizeof(row));
			pss p;
			p.second = strtok(row, " ");
			p.first = strtok(nullptr, " ");
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		
		int cnt = 0;
		int res = 1;

		if (!v.empty()) {
			string cur_str = v[0].first;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].first == cur_str) {
					cnt++;
				}
				else {
					res *= (cnt + 1); // + 1 : �ƹ��͵� �� ���� ����� ��
					cur_str = v[i].first;
					cnt = 1;
				}
			}
			res *= (cnt + 1); // �ܿ� ��� ó��
		}
		cout << res - 1 << '\n'; // �ƹ��͵� �� ���� ����� ���� ����
	}

	return 0;
}