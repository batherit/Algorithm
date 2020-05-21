#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string& a, string& b) {
	if (a.size() < b.size()) return true;
	else if (a.size() > b.size()) return false;
	else return a < b;
}

int main(void) {
	int n;
	cin >> n;

	vector<string> v;
	string in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end(), cmp);

	// 중복 제거
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}