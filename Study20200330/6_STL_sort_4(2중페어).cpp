#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool comp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		// 성적이 같다면, 생일을 내림차순으로 정렬한다.
		return a.second.second > b.second.second;
	}
	else {
		// 성적이 같지않다면, 성적을 내림차순으로 정렬한다.
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