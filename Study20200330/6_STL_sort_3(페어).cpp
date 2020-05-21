#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	vector<pair<int, string>> v;
	v.push_back(pair<int, string>(90, "A"));
	v.push_back(make_pair(85, "B"));

	sort(v.begin(), v.end());

}