#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(void) {
	vector<int> nums{ 1, 2, 3, 4, 5 };
	int target = 6;

	map<int, int> idx;
	for (int i = 0; i < nums.size(); i++) {
		idx[nums[i]] = i;
	}

	vector<int> result;
	map<int, int>::iterator iter;
	for (int i = 0; i < nums.size(); i++) {
		iter = idx.find(target - nums[i]);
		if (iter != idx.end() && idx[target - nums[i]] != idx[nums[i]]) {
			result.push_back(idx[nums[i]]);
			result.push_back(idx[target - nums[i]]);
			break;
		}
	}
	sort(result.begin(), result.end());
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}
