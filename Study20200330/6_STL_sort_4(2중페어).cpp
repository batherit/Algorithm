#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool comp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		// ������ ���ٸ�, ������ ������������ �����Ѵ�.
		return a.second.second > b.second.second;
	}
	else {
		// ������ �����ʴٸ�, ������ ������������ �����Ѵ�.
		return a.second.first > b.second.first;
	}
}

int main(void) {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(make_pair("A", make_pair(90, 19920703)));
	v.push_back(pair<string, pair<int, int>>("B", pair<int, int>(87, 19891212)));

	sort(v.begin(), v.end(), comp);

	return 0;
}