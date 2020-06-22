#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nums;
vector<char> opers;

int main(void) {
	int n;
	cin >> n;

	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int in;
	for (int i = 0; i < 4; i++) {
		cin >> in;
		for (int j = 0; j < in; j++) {
			if (i == 0) opers.push_back('+');
			else if (i == 1) opers.push_back('-');
			else if (i == 2) opers.push_back('*');
			else if (i == 3) opers.push_back('/');
		}
	}

	sort(opers.begin(), opers.end());

	int mx = -1000000001;
	int mn = 1000000001;
	do {
		int result = 0;
		result = nums[0];
		for (int i = 1; i < n; i++) {
			if (opers[i - 1] == '+') result += nums[i];
			else if (opers[i - 1] == '-') result -= nums[i];
			else if (opers[i - 1] == '*') result *= nums[i];
			else if (opers[i - 1] == '/') result /= nums[i];
		}
		if (result > mx) mx = result;
		if (result < mn) mn = result;
	} while (next_permutation(opers.begin(), opers.end()));

	cout << mx;
	cout << '\n';
	cout << mn;
}